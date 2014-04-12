<?php

function taglit_apply_views_default_views() {
  $views = array();

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
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
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
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Started Application';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: User: Training Dates */
  $handler->display->display_options['fields']['field_training_dates']['id'] = 'field_training_dates';
  $handler->display->display_options['fields']['field_training_dates']['table'] = 'field_data_field_training_dates';
  $handler->display->display_options['fields']['field_training_dates']['field'] = 'field_training_dates';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['label'] = 'Application Complete';
  $handler->display->display_options['fields']['rid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['rid']['alter']['text'] = 'Y';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Application';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'program-application/[uid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    5 => '5',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid_1']['id'] = 'rid_1';
  $handler->display->display_options['filters']['rid_1']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid_1']['field'] = 'rid';
  $handler->display->display_options['filters']['rid_1']['operator'] = 'and';
  $handler->display->display_options['filters']['rid_1']['value'] = array(
    4 => '4',
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
  );
  $handler->display->display_options['filters']['rid_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: Training Dates (field_training_dates) */
  $handler->display->display_options['filters']['field_training_dates_value']['id'] = 'field_training_dates_value';
  $handler->display->display_options['filters']['field_training_dates_value']['table'] = 'field_data_field_training_dates';
  $handler->display->display_options['filters']['field_training_dates_value']['field'] = 'field_training_dates_value';
  $handler->display->display_options['filters']['field_training_dates_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['operator_id'] = 'field_training_dates_value_op';
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['label'] = 'Training Dates';
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['operator'] = 'field_training_dates_value_op';
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['identifier'] = 'field_training_dates_value';
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_training_dates_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_training_dates_value']['group_info']['label'] = 'Training Dates';
  $handler->display->display_options['filters']['field_training_dates_value']['group_info']['identifier'] = 'field_training_dates_value';
  $handler->display->display_options['filters']['field_training_dates_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        'I would like to participate in the August 2014 training.' => 'I would like to participate in the August 2014 training.',
        'I would like to participate in the February 2015 training.' => 'I would like to participate in the February 2015 training.',
        'I could participate in either training.' => 'I could participate in either training.',
      ),
    ),
    2 => array(
      'title' => 'August',
      'operator' => 'or',
      'value' => array(
        'I would like to participate in the August 2014 training.' => 'I would like to participate in the August 2014 training.',
        'I could participate in either training.' => 'I could participate in either training.',
      ),
    ),
    3 => array(
      'title' => 'February',
      'operator' => 'or',
      'value' => array(
        'I would like to participate in the February 2015 training.' => 'I would like to participate in the February 2015 training.',
        'I could participate in either training.' => 'I could participate in either training.',
      ),
    ),
    4 => array(
      'title' => 'Only August',
      'operator' => 'and',
      'value' => array(
        'I would like to participate in the August 2014 training.' => 'I would like to participate in the August 2014 training.',
      ),
    ),
    5 => array(
      'title' => 'Only February',
      'operator' => 'and',
      'value' => array(
        'I would like to participate in the February 2015 training.' => 'I would like to participate in the February 2015 training.',
      ),
    ),
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
    5 => '5',
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
  $handler->display->display_options['path'] = 'application-review';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Review Applications';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  
  /* Display: Reviewers Page #2 */
  $handler = $view->new_display('page', 'Reviewers Page #2', 'page_2');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_cancel_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'rules_component::rules_send_incomplete_email' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_send_completion_email' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_sendthemailnow' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::realname_action_realname_update' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
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
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Started Application';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: User: Training Dates */
  $handler->display->display_options['fields']['field_training_dates']['id'] = 'field_training_dates';
  $handler->display->display_options['fields']['field_training_dates']['table'] = 'field_data_field_training_dates';
  $handler->display->display_options['fields']['field_training_dates']['field'] = 'field_training_dates';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['label'] = 'Application Complete';
  $handler->display->display_options['fields']['rid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['rid']['alter']['text'] = 'Y';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Application';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'program-application/[uid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['path'] = 'application-review-2';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Review Applications';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  
  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_2';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 0;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['label'] = 'Application Complete';
  $handler->display->display_options['fields']['rid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['rid']['alter']['text'] = 'Y';
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
    5 => '5',
    6 => '6',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid_1']['id'] = 'rid_1';
  $handler->display->display_options['filters']['rid_1']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid_1']['field'] = 'rid';
  $handler->display->display_options['filters']['rid_1']['operator'] = 'and';
  $handler->display->display_options['filters']['rid_1']['value'] = array(
    4 => '4',
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
  );
  $handler->display->display_options['filters']['rid_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: Training Dates (field_training_dates) */
  $handler->display->display_options['filters']['field_training_dates_value']['id'] = 'field_training_dates_value';
  $handler->display->display_options['filters']['field_training_dates_value']['table'] = 'field_data_field_training_dates';
  $handler->display->display_options['filters']['field_training_dates_value']['field'] = 'field_training_dates_value';
  $handler->display->display_options['filters']['field_training_dates_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['operator_id'] = 'field_training_dates_value_op';
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['label'] = 'Training Dates';
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['operator'] = 'field_training_dates_value_op';
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['identifier'] = 'field_training_dates_value';
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_training_dates_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_training_dates_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_training_dates_value']['group_info']['label'] = 'Training Dates';
  $handler->display->display_options['filters']['field_training_dates_value']['group_info']['identifier'] = 'field_training_dates_value';
  $handler->display->display_options['filters']['field_training_dates_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'All',
      'operator' => 'or',
      'value' => array(
        'I would like to participate in the August 2014 training.' => 'I would like to participate in the August 2014 training.',
        'I would like to participate in the February 2015 training.' => 'I would like to participate in the February 2015 training.',
        'I could participate in either training.' => 'I could participate in either training.',
      ),
    ),
    2 => array(
      'title' => 'August',
      'operator' => 'or',
      'value' => array(
        'I would like to participate in the August 2014 training.' => 'I would like to participate in the August 2014 training.',
        'I could participate in either training.' => 'I could participate in either training.',
      ),
    ),
    3 => array(
      'title' => 'February',
      'operator' => 'or',
      'value' => array(
        'I would like to participate in the February 2015 training.' => 'I would like to participate in the February 2015 training.',
        'I could participate in either training.' => 'I could participate in either training.',
      ),
    ),
    4 => array(
      'title' => 'Only August',
      'operator' => 'and',
      'value' => array(
        'I would like to participate in the August 2014 training.' => 'I would like to participate in the August 2014 training.',
      ),
    ),
    5 => array(
      'title' => 'Only February',
      'operator' => 'and',
      'value' => array(
        'I would like to participate in the February 2015 training.' => 'I would like to participate in the February 2015 training.',
      ),
    ),
  );
  $handler->display->display_options['path'] = 'application-review-2/export';
  $handler->display->display_options['displays'] = array(
    'page_2' => 'page_2',
    'default' => 0,
    'page' => 0,
    'page_1' => 0,
  );

  // Add view to list of views to provide.
  $views[$view->name] = $view;
    
  $view = new view();
  $view->name = 'taglit_applicants';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taglit_apply';
  $view->human_name = 'Taglit Applicants';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'referred' => 'referred',
    'taglit_apply_id' => 'taglit_apply_id',
    'uid' => 'uid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'referred' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'taglit_apply_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Taglit Fellows: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'taglit_apply';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  /* Field: User: Gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['relationship'] = 'uid';
  /* Field: Taglit Fellows: Address */
  $handler->display->display_options['fields']['street_address']['id'] = 'street_address';
  $handler->display->display_options['fields']['street_address']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['street_address']['field'] = 'street_address';
  /* Field: Taglit Fellows: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  /* Field: Taglit Fellows: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Taglit Fellows: Country */
  $handler->display->display_options['fields']['country']['id'] = 'country';
  $handler->display->display_options['fields']['country']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['country']['field'] = 'country';
  /* Field: Taglit Fellows: Phone */
  $handler->display->display_options['fields']['mobile_phone']['id'] = 'mobile_phone';
  $handler->display->display_options['fields']['mobile_phone']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['mobile_phone']['field'] = 'mobile_phone';
  /* Field: Taglit Fellows: Referred by */
  $handler->display->display_options['fields']['referred']['id'] = 'referred';
  $handler->display->display_options['fields']['referred']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['referred']['field'] = 'referred';
  /* Field: Taglit Fellows: BRI Alum */
  $handler->display->display_options['fields']['israel_birthright']['id'] = 'israel_birthright';
  $handler->display->display_options['fields']['israel_birthright']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['israel_birthright']['field'] = 'israel_birthright';
  /* Field: Taglit Fellows: BRI TO */
  $handler->display->display_options['fields']['israel_birthright_provider']['id'] = 'israel_birthright_provider';
  $handler->display->display_options['fields']['israel_birthright_provider']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['israel_birthright_provider']['field'] = 'israel_birthright_provider';
  /* Field: Taglit Fellows: BRI Staff */
  $handler->display->display_options['fields']['israel_birthright_staff']['id'] = 'israel_birthright_staff';
  $handler->display->display_options['fields']['israel_birthright_staff']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['israel_birthright_staff']['field'] = 'israel_birthright_staff';
  /* Field: Taglit Fellows: BRI Staff Num Times */
  $handler->display->display_options['fields']['israel_birthright_staff_num']['id'] = 'israel_birthright_staff_num';
  $handler->display->display_options['fields']['israel_birthright_staff_num']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['israel_birthright_staff_num']['field'] = 'israel_birthright_staff_num';
  /* Field: Taglit Fellows: BRI Staff TO */
  $handler->display->display_options['fields']['israel_birthright_staff_provider']['id'] = 'israel_birthright_staff_provider';
  $handler->display->display_options['fields']['israel_birthright_staff_provider']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['israel_birthright_staff_provider']['field'] = 'israel_birthright_staff_provider';
  /* Field: Taglit Fellows: Jewish Background */
  $handler->display->display_options['fields']['jewish_background']['id'] = 'jewish_background';
  $handler->display->display_options['fields']['jewish_background']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['jewish_background']['field'] = 'jewish_background';
  /* Field: Taglit Fellows: Jewish Elementary */
  $handler->display->display_options['fields']['jewish_elementary']['id'] = 'jewish_elementary';
  $handler->display->display_options['fields']['jewish_elementary']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['jewish_elementary']['field'] = 'jewish_elementary';
  /* Field: Taglit Fellows: Jewish High School */
  $handler->display->display_options['fields']['jewish_highschool']['id'] = 'jewish_highschool';
  $handler->display->display_options['fields']['jewish_highschool']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['jewish_highschool']['field'] = 'jewish_highschool';
  /* Field: Taglit Fellows: Jewish Supplementary */
  $handler->display->display_options['fields']['jewish_supplementary']['id'] = 'jewish_supplementary';
  $handler->display->display_options['fields']['jewish_supplementary']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['jewish_supplementary']['field'] = 'jewish_supplementary';
  /* Field: Taglit Fellows: Jewish Camp */
  $handler->display->display_options['fields']['jewish_camp']['id'] = 'jewish_camp';
  $handler->display->display_options['fields']['jewish_camp']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['jewish_camp']['field'] = 'jewish_camp';
  /* Field: Taglit Fellows: Camp Name */
  $handler->display->display_options['fields']['jewish_camp_name']['id'] = 'jewish_camp_name';
  $handler->display->display_options['fields']['jewish_camp_name']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['jewish_camp_name']['field'] = 'jewish_camp_name';
  /* Field: Taglit Fellows: Jewish Youth Group */
  $handler->display->display_options['fields']['jewish_youthgroup']['id'] = 'jewish_youthgroup';
  $handler->display->display_options['fields']['jewish_youthgroup']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['jewish_youthgroup']['field'] = 'jewish_youthgroup';
  /* Field: Taglit Fellows: Youth Group Name */
  $handler->display->display_options['fields']['jewish_youthgroup_name']['id'] = 'jewish_youthgroup_name';
  $handler->display->display_options['fields']['jewish_youthgroup_name']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['jewish_youthgroup_name']['field'] = 'jewish_youthgroup_name';
  /* Field: Taglit Fellows: Educational Status */
  $handler->display->display_options['fields']['ed_status']['id'] = 'ed_status';
  $handler->display->display_options['fields']['ed_status']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['ed_status']['field'] = 'ed_status';
  /* Field: Taglit Fellows: School */
  $handler->display->display_options['fields']['ed_school_name']['id'] = 'ed_school_name';
  $handler->display->display_options['fields']['ed_school_name']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['ed_school_name']['field'] = 'ed_school_name';
  /* Field: Taglit Fellows: Professional Status */
  $handler->display->display_options['fields']['prof_status']['id'] = 'prof_status';
  $handler->display->display_options['fields']['prof_status']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['prof_status']['field'] = 'prof_status';
  /* Field: Taglit Fellows: Employer */
  $handler->display->display_options['fields']['prof_employer']['id'] = 'prof_employer';
  $handler->display->display_options['fields']['prof_employer']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['prof_employer']['field'] = 'prof_employer';
  /* Field: Taglit Fellows: Position */
  $handler->display->display_options['fields']['prof_position']['id'] = 'prof_position';
  $handler->display->display_options['fields']['prof_position']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['prof_position']['field'] = 'prof_position';
  /* Field: Taglit Fellows: Languages */
  $handler->display->display_options['fields']['languages']['id'] = 'languages';
  $handler->display->display_options['fields']['languages']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['languages']['field'] = 'languages';
  /* Field: Taglit Fellows: Other Skills */
  $handler->display->display_options['fields']['other_skills']['id'] = 'other_skills';
  $handler->display->display_options['fields']['other_skills']['table'] = 'taglit_apply';
  $handler->display->display_options['fields']['other_skills']['field'] = 'other_skills';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['relationship'] = 'uid';
  
  /* Display: Page - All Data */
  $handler = $view->new_display('page', 'Page - All Data', 'page_all_data');
  $handler->display->display_options['path'] = 'testpage';

  // Add view to list of views to provide.
  $views[$view->name] = $view;
  
  // At the end, return array of default views.
  return $views;
}
