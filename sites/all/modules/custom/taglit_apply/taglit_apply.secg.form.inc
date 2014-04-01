<?php

/**
 * @file
 * Form function for the Taglit Fellows Application module.
 */
function taglit_apply_secg_form($form, $form_state) {
  global $user; //Get the current user.
  
  taglit_apply_check_app_exists($user);
  
  $query_select = db_select('taglit_apply') //Query the database to see of the user has a record.
  ->fields('taglit_apply')
  ->condition('uid', $user->uid, '=')
  ->execute()
  ->fetchAssoc();
  
  $form = array();
  
  $form['declaration'] = array(
    '#type' => 'radios',
    '#title' => t('I agree'),
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#required' => TRUE,
    '#default_value' => $query_select['declaration'],
  );

 $form['referred'] = array(
    '#type' => 'textfield',
    '#title' => t('I heard about the Taglit Fellows program from:'),
    '#size' => 100,
		'#maxlength' => 200,
    '#required' => TRUE,
    '#default_value' => $query_select['referred'],
  );

 $form['initials'] = array(
    '#type' => 'textfield',
    '#title' => t('Initials'),
    '#size' => 3,
		'#maxlength' => 3,
    '#default_value' => $query_select['initials'],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  return $form;
}

function taglit_apply_secg_form_submit($form, &$form_state) {
	global $user;
    
  $query = db_update('taglit_apply')
  	->fields(
  		array(
	    	'declaration' 	=> 	$form_state['values']['declaration'],
	    	'initials' 	=> 	$form_state['values']['initials'],
	    	'reffered' 	=> 	$form_state['values']['reffered'],
				'secg_complete' => 1
			)
		)
  ->condition('uid', $user->uid, '=')
  ->execute();
  
  taglit_apply_add_role_to_user($user, 'applicant');
  
  $form_state['redirect'] = 'program-application/complete';
}
