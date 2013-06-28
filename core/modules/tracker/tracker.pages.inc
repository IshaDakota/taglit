<?php

/**
 * @file
 * User page callbacks for tracker.module.
 */


/**
 * Page callback: Generates a page of tracked nodes for the site.
 *
 * Queries the database for info, adds RDFa info if applicable, and generates
 * the render array that will be used to render the page.
 *
 * @return array
 *   A renderable array.
 *
 * @see tracker_menu()
 */
function tracker_page($account = NULL, $set_title = FALSE) {
  if ($account) {
    $query = db_select('tracker_user', 't')
      ->extend('Drupal\Core\Database\Query\PagerSelectExtender')
      ->addMetaData('base_table', 'tracker_user')
      ->condition('t.uid', $account->uid);

    if ($set_title) {
      // When viewed from user/%user/track, display the name of the user
      // as page title -- the tab title remains Track so this needs to be done
      // here and not in the menu definition.
      drupal_set_title(user_format_name($account));
    }
  }
  else {
    $query = db_select('tracker_node', 't', array('target' => 'slave'))
      ->extend('Drupal\Core\Database\Query\PagerSelectExtender')
      ->addMetaData('base_table', 'tracker_node');
  }

  // This array acts as a placeholder for the data selected later
  // while keeping the correct order.
  $tracker_data = $query
    ->addTag('node_access')
    ->fields('t', array('nid', 'changed'))
    ->condition('t.published', 1)
    ->orderBy('t.changed', 'DESC')
    ->limit(25)
    ->execute()
    ->fetchAllAssoc('nid');

  $rows = array();
  if (!empty($tracker_data)) {
    $nids = array_keys($tracker_data);
    $nodes = node_load_multiple($nids);
    // Now, get the data and put into the placeholder array.
    // @todo This should be actually filtering on the desired language and just
    //   fall back to the default language.
    $result = db_query('SELECT n.nid, l.comment_count FROM {node_field_data} n INNER JOIN {node_comment_statistics} l ON n.nid = l.nid WHERE n.nid IN (:nids) AND n.default_langcode = 1 ORDER BY n.changed DESC', array(':nids' => $nids), array('target' => 'slave'))->fetchAllKeyed();
    foreach ($result as $nid => $comment_count) {
      $nodes[$nid]->last_activity = $tracker_data[$nid]->changed;
      $nodes[$nid]->comment_count = $comment_count;
    }

    // Display the data.
    foreach ($nodes as $node) {
      // Determine the number of comments.
      $comments = 0;
      if ($node->comment_count) {
        $comments = $node->comment_count;

        if ($new = comment_num_new($node->nid)) {
          $comments .= '<br />';
          $comments .= l(format_plural($new, '1 new', '@count new'), 'node/' . $node->nid, array('fragment' => 'new'));
        }
      }

      $mark_build = array(
        '#theme' => 'mark',
        '#status' => node_mark($node->nid, $node->changed),
      );

      $row = array(
        'type' => check_plain(node_get_type_label($node)),
        // Do not use $node->label(), because $node comes from the database.
        'title' => array('data' => l($node->title, 'node/' . $node->nid) . ' ' . drupal_render($mark_build)),
        'author' => array('data' => array('#theme' => 'username', '#account' => $node)),
        'replies' => array('class' => array('replies'), 'data' => $comments),
        'last updated' => array('data' => t('!time ago', array('!time' => format_interval(REQUEST_TIME - $node->last_activity)))),
      );

      // Adds extra RDFa markup to the $row array if the RDF module is enabled.
      if (module_exists('rdf')) {
        $mapping = rdf_get_mapping('node', $node->type);
        // Adds RDFa markup to the title of the node. Because the RDFa markup is
        // added to the td tag which might contain HTML code, we specify an
        // empty datatype to ensure the value of the title read by the RDFa
        // parsers is a plain literal.
        $title_mapping = $mapping->getPreparedFieldMapping('title');
        $row['title'] += rdf_rdfa_attributes($title_mapping) + array('datatype' => '');
        // Annotates the td tag containing the author of the node.
        $uid_mapping = $mapping->getPreparedFieldMapping('uid');
        $row['author'] += rdf_rdfa_attributes($uid_mapping);
        // Annotates the td tag containing the number of replies. We add the
        // content attribute to ensure that only the comment count is used as
        // the value for 'num_replies'. Otherwise, other text such as a link
        // to the number of new comments could be included in the 'num_replies'
        // value.
        $comment_count_mapping = $mapping->getPreparedFieldMapping('comment_count');
        $row['replies'] += rdf_rdfa_attributes($comment_count_mapping);
        $row['replies'] += array('content' => $node->comment_count);
        // If the node has no comments, we assume the node itself was modified
        // and apply 'changed' in addition to 'last_activity'.  If there are
        // comments present, we cannot infer whether the node itself was
        // modified or a comment was posted, so we use only 'last_activity'.
        $last_activity_mapping = $mapping->getPreparedFieldMapping('last_activity');
        $last_activity_attributes = rdf_rdfa_attributes($last_activity_mapping, $node->last_activity);
        if ($node->comment_count == 0) {
          $changed_mapping = $mapping->getPreparedFieldMapping('changed');
          $changed_attributes = rdf_rdfa_attributes($changed_mapping, $node->last_activity);
          $last_activity_attributes['property'] = array_merge($last_activity_attributes['property'], $changed_attributes['property']);
        }
        $row['last updated'] += $last_activity_attributes;

        // We need to add the about attribute on the tr tag to specify which
        // node the RDFa annotations above apply to. We move the content of
        // $row to a 'data' sub array so we can specify attributes for the row.
        $row = array('data' => $row);
        $row['about'] = url('node/' . $node->nid);
      }
      $rows[] = $row;
    }
  }

  $page['tracker'] = array(
    '#rows' => $rows,
    '#header' => array(t('Type'), t('Title'), t('Author'), t('Replies'), t('Last updated')),
    '#theme' => 'table',
    '#empty' => t('No content available.'),
  );
  $page['pager'] = array(
    '#theme' => 'pager',
    '#quantity' => 25,
    '#weight' => 10,
  );
  $page['#sorted'] = TRUE;

  return $page;
}