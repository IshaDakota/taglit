<?php
/**
 * @file
 * taglit_apply.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function taglit_apply_views_default_views() {
  $export = array();

    $view = new view();
    $view->name = 'applications';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'users';
    $view->human_name = 'Applications';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
    
    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Applications';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'role';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '50';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'uid' => 'uid',
      'field_first_name' => 'field_first_name',
      'field_last_name' => 'field_last_name',
      'field_university_program' => 'field_university_program',
      'created' => 'created',
      'nothing' => 'nothing',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      'uid' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_first_name' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_last_name' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_university_program' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'created' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'nothing' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    /* Field: User: Uid */
    $handler->display->display_options['fields']['uid']['id'] = 'uid';
    $handler->display->display_options['fields']['uid']['table'] = 'users';
    $handler->display->display_options['fields']['uid']['field'] = 'uid';
    $handler->display->display_options['fields']['uid']['label'] = '';
    $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
    $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
    /* Field: User: First Name */
    $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
    $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
    $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
    /* Field: User: Last Name */
    $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
    $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
    $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
    /* Field: User: University Program */
    $handler->display->display_options['fields']['field_university_program']['id'] = 'field_university_program';
    $handler->display->display_options['fields']['field_university_program']['table'] = 'field_data_field_university_program';
    $handler->display->display_options['fields']['field_university_program']['field'] = 'field_university_program';
    /* Field: User: Created date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'users';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['label'] = 'Started Application';
    $handler->display->display_options['fields']['created']['date_format'] = 'short';
    /* Field: Global: Custom text */
    $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['table'] = 'views';
    $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['label'] = '';
    $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Application';
    $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['nothing']['alter']['path'] = 'program-application/[uid]';
    $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
    /* Field: User: Roles */
    $handler->display->display_options['fields']['rid']['id'] = 'rid';
    $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
    $handler->display->display_options['fields']['rid']['field'] = 'rid';
    $handler->display->display_options['fields']['rid']['label'] = 'Application Complete';
    $handler->display->display_options['fields']['rid']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['rid']['alter']['text'] = 'Y';
    /* Sort criterion: User: Created date */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'users';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    /* Filter criterion: User: Active */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'users';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = '1';
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: User: Roles */
    $handler->display->display_options['filters']['rid']['id'] = 'rid';
    $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
    $handler->display->display_options['filters']['rid']['field'] = 'rid';
    $handler->display->display_options['filters']['rid']['operator'] = 'not';
    $handler->display->display_options['filters']['rid']['value'] = array(
      3 => '3',
      4 => '4',
      6 => '6',
    );
    
    /* Display: Administrators Page */
    $handler = $view->new_display('page', 'Administrators Page', 'page');
    $handler->display->display_options['defaults']['use_ajax'] = FALSE;
    $handler->display->display_options['use_ajax'] = TRUE;
    $handler->display->display_options['defaults']['access'] = FALSE;
    $handler->display->display_options['access']['type'] = 'role';
    $handler->display->display_options['access']['role'] = array(
      3 => '3',
    );
    $handler->display->display_options['defaults']['filter_groups'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter criterion: User: Active */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'users';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = '1';
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: User: Roles */
    $handler->display->display_options['filters']['rid']['id'] = 'rid';
    $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
    $handler->display->display_options['filters']['rid']['field'] = 'rid';
    $handler->display->display_options['filters']['rid']['operator'] = 'not';
    $handler->display->display_options['filters']['rid']['value'] = array(
      3 => '3',
      4 => '4',
      6 => '6',
    );
    /* Filter criterion: User: University Program (field_university_program) */
    $handler->display->display_options['filters']['field_university_program_value']['id'] = 'field_university_program_value';
    $handler->display->display_options['filters']['field_university_program_value']['table'] = 'field_data_field_university_program';
    $handler->display->display_options['filters']['field_university_program_value']['field'] = 'field_university_program_value';
    $handler->display->display_options['filters']['field_university_program_value']['exposed'] = TRUE;
    $handler->display->display_options['filters']['field_university_program_value']['expose']['operator_id'] = 'field_university_program_value_op';
    $handler->display->display_options['filters']['field_university_program_value']['expose']['label'] = 'University Program';
    $handler->display->display_options['filters']['field_university_program_value']['expose']['operator'] = 'field_university_program_value_op';
    $handler->display->display_options['filters']['field_university_program_value']['expose']['identifier'] = 'field_university_program_value';
    $handler->display->display_options['filters']['field_university_program_value']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
    );
    /* Filter criterion: User: Roles */
    $handler->display->display_options['filters']['rid_1']['id'] = 'rid_1';
    $handler->display->display_options['filters']['rid_1']['table'] = 'users_roles';
    $handler->display->display_options['filters']['rid_1']['field'] = 'rid';
    $handler->display->display_options['filters']['rid_1']['value'] = array(
      5 => '5',
    );
    $handler->display->display_options['filters']['rid_1']['exposed'] = TRUE;
    $handler->display->display_options['filters']['rid_1']['expose']['operator_id'] = 'rid_1_op';
    $handler->display->display_options['filters']['rid_1']['expose']['label'] = 'Completed';
    $handler->display->display_options['filters']['rid_1']['expose']['operator'] = 'rid_1_op';
    $handler->display->display_options['filters']['rid_1']['expose']['identifier'] = 'rid_1';
    $handler->display->display_options['filters']['rid_1']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
    );
    $handler->display->display_options['filters']['rid_1']['expose']['reduce'] = TRUE;
    $handler->display->display_options['path'] = 'applications';
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = 'Review Applications';
    $handler->display->display_options['menu']['weight'] = '0';
    $handler->display->display_options['menu']['name'] = 'user-menu';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;
    
    /* Display: Reviewers Page */
    $handler = $view->new_display('page', 'Reviewers Page', 'page_1');
    $handler->display->display_options['defaults']['access'] = FALSE;
    $handler->display->display_options['access']['type'] = 'role';
    $handler->display->display_options['access']['role'] = array(
      4 => '4',
    );
    $handler->display->display_options['defaults']['relationships'] = FALSE;
    $handler->display->display_options['defaults']['sorts'] = FALSE;
    /* Sort criterion: User: Last Name (field_last_name) */
    $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
    $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
    $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
    /* Sort criterion: User: Created date */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'users';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: User: University Program (field_university_program) */
    $handler->display->display_options['arguments']['field_university_program_value']['id'] = 'field_university_program_value';
    $handler->display->display_options['arguments']['field_university_program_value']['table'] = 'field_data_field_university_program';
    $handler->display->display_options['arguments']['field_university_program_value']['field'] = 'field_university_program_value';
    $handler->display->display_options['arguments']['field_university_program_value']['default_action'] = 'default';
    $handler->display->display_options['arguments']['field_university_program_value']['default_argument_type'] = 'php';
    $handler->display->display_options['arguments']['field_university_program_value']['default_argument_options']['code'] = 'global $user;
    $user = user_load($user->uid);
    return $user->field_university_program[\'und\'][\'0\'][\'value\'];
    
    ';
    $handler->display->display_options['arguments']['field_university_program_value']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['field_university_program_value']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['field_university_program_value']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['field_university_program_value']['limit'] = '0';
    $handler->display->display_options['path'] = 'application-review';
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = 'Review Applications';
    $handler->display->display_options['menu']['weight'] = '0';
    $handler->display->display_options['menu']['name'] = 'user-menu';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;
    
    /* Display: All HUC */
    $handler = $view->new_display('page', 'All HUC', 'page_2');
    $handler->display->display_options['defaults']['access'] = FALSE;
    $handler->display->display_options['access']['type'] = 'role';
    $handler->display->display_options['access']['role'] = array(
      6 => '6',
    );
    $handler->display->display_options['defaults']['filter_groups'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter criterion: User: Active */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'users';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = '1';
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: User: Roles */
    $handler->display->display_options['filters']['rid']['id'] = 'rid';
    $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
    $handler->display->display_options['filters']['rid']['field'] = 'rid';
    $handler->display->display_options['filters']['rid']['operator'] = 'not';
    $handler->display->display_options['filters']['rid']['value'] = array(
      3 => '3',
      4 => '4',
      6 => '6',
    );
    /* Filter criterion: User: University Program (field_university_program) */
    $handler->display->display_options['filters']['field_university_program_value']['id'] = 'field_university_program_value';
    $handler->display->display_options['filters']['field_university_program_value']['table'] = 'field_data_field_university_program';
    $handler->display->display_options['filters']['field_university_program_value']['field'] = 'field_university_program_value';
    $handler->display->display_options['filters']['field_university_program_value']['value'] = array(
      'HUC' => 'HUC',
      'HUC-EM' => 'HUC-EM',
      'HUC-RH' => 'HUC-RH',
      'HUC-NY' => 'HUC-NY',
    );
    $handler->display->display_options['path'] = 'app-review';
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = 'Review Applications';
    $handler->display->display_options['menu']['weight'] = '0';
    $handler->display->display_options['menu']['name'] = 'user-menu';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;

  $export['resource_library'] = $view;

  return $export;
}
