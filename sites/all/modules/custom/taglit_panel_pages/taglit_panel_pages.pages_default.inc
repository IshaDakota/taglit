<?php
/**
 * @file
 * taglit_panel_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function taglit_panel_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'about_page';
  $page->task = 'page';
  $page->admin_title = 'About Page';
  $page->admin_description = '';
  $page->path = 'about-taglit-fellows';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_about_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'about_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'about',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol_resp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
      'sidebarfirst' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'About Taglit-Birthright Israel Fellows';
  $display->uuid = '98ec0baf-edcf-4e3d-942c-90ebcd39f405';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bc381947-690a-498b-b256-49af5e96b1f3';
    $pane->panel = 'content';
    $pane->type = 'block';
    $pane->subtype = 'block-6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Application Criteria',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'application-criteria',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bc381947-690a-498b-b256-49af5e96b1f3';
    $display->content['new-bc381947-690a-498b-b256-49af5e96b1f3'] = $pane;
    $display->panels['content'][0] = 'new-bc381947-690a-498b-b256-49af5e96b1f3';
    $pane = new stdClass();
    $pane->pid = 'new-d2112f70-ee57-4615-9031-520b2e48ddc8';
    $pane->panel = 'sidebarfirst';
    $pane->type = 'block';
    $pane->subtype = 'block-7';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Key Dates & Deadlines',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'dates-deadlines',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd2112f70-ee57-4615-9031-520b2e48ddc8';
    $display->content['new-d2112f70-ee57-4615-9031-520b2e48ddc8'] = $pane;
    $display->panels['sidebarfirst'][0] = 'new-d2112f70-ee57-4615-9031-520b2e48ddc8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['about_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apply_page';
  $page->task = 'page';
  $page->admin_title = 'Apply Page';
  $page->admin_description = '';
  $page->path = 'application';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_apply_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'apply_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'apply',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol_resp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
      'sidebarfirst' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Application';
  $display->uuid = '856fc8df-3890-4cdc-99a8-120e00703f34';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-00cd814c-5033-41c1-9259-8aca3757e334';
    $pane->panel = 'content';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Applications Open Soon',
      'title' => '',
      'body' => '<p>Application for the Taglit-Birthright Israel Fellows program will open on April 1, 2014 at noon EDT.</p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '00cd814c-5033-41c1-9259-8aca3757e334';
    $display->content['new-00cd814c-5033-41c1-9259-8aca3757e334'] = $pane;
    $display->panels['content'][0] = 'new-00cd814c-5033-41c1-9259-8aca3757e334';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-00cd814c-5033-41c1-9259-8aca3757e334';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apply_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front_page';
  $page->task = 'page';
  $page->admin_title = 'Front Page';
  $page->admin_description = '';
  $page->path = 'frontpage';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol_resp';
  $display->layout_settings = array(
    'main_classes' => '',
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'left' => NULL,
      'right' => NULL,
      'content' => NULL,
      'sidebarfirst' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '667ed7ba-c3f3-493a-958b-33f715baa767';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-39d8197d-86f2-44f6-bcc9-0393839a5655';
    $pane->panel = 'content';
    $pane->type = 'block';
    $pane->subtype = 'block-2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '39d8197d-86f2-44f6-bcc9-0393839a5655';
    $display->content['new-39d8197d-86f2-44f6-bcc9-0393839a5655'] = $pane;
    $display->panels['content'][0] = 'new-39d8197d-86f2-44f6-bcc9-0393839a5655';
    $pane = new stdClass();
    $pane->pid = 'new-98e64a92-8238-408c-826e-3f8b7a9bfae0';
    $pane->panel = 'sidebarfirst';
    $pane->type = 'block';
    $pane->subtype = 'block-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '98e64a92-8238-408c-826e-3f8b7a9bfae0';
    $display->content['new-98e64a92-8238-408c-826e-3f8b7a9bfae0'] = $pane;
    $display->panels['sidebarfirst'][0] = 'new-98e64a92-8238-408c-826e-3f8b7a9bfae0';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
