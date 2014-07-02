<?php

/**
 * @file
 * Form function for the Taglit Fellows Application module.
 */
function taglit_apply_agmt_form($form, $form_state) {
  global $user; //Get the current user.
  
  taglit_apply_check_app_exists($user);
  
  $query_select = db_select('taglit_apply') //Query the database to see of the user has a record.
  ->fields('taglit_apply')
  ->condition('uid', $user->uid, '=')
  ->execute()
  ->fetchAssoc();
  
  $form = array();
  
  $form['agreement'] = array(
    '#type' => 'radios',
    '#title' => t('You agree that by clicking "Yes" on this page, you thereby acknowledge that you have read and understand this letter of agreement and agree to abide by its terms and conditions.'),
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#required' => TRUE,
    '#default_value' => $query_select['agreement'],
  );

 $form['agmt_initials'] = array(
    '#type' => 'textfield',
    '#title' => t('Initials'),
    '#size' => 3,
		'#maxlength' => 3,
    '#default_value' => $query_select['agmt_initials'],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  return $form;
}

function taglit_apply_agmt_form_submit($form, &$form_state) {
	global $user;
    
  $query = db_update('taglit_apply')
  	->fields(
  		array(
	    	'declaration' 	=> 	$form_state['values']['agreement'],
	    	'initials' 	=> 	$form_state['values']['agmt_initials'],
	    	'secagmt_complete' => 1

			)
		)
  ->condition('uid', $user->uid, '=')
  ->execute();
  
  taglit_apply_add_role_to_user($user, 'fellow');
  
  //rules_invoke_component('rules_send_completion_email', $user);
 
  $form_state['redirect'] = 'program-application';
}
