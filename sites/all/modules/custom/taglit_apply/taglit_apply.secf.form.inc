<?php

/**
 * @file
 * Form function for the Taglit Fellows Application module.
 */
function taglit_apply_secf_form($form, $form_state) {
  global $user; //Get the current user.
  
  taglit_apply_check_app_exists($user);
  
  $query_select = db_select('taglit_apply') //Query the database to see of the user has a record.
  ->fields('taglit_apply')
  ->condition('uid', $user->uid, '=')
  ->execute()
  ->fetchAssoc();
  
  $form = array();
  
  $form['essay1'] = array(
    '#type' => 'text_format',
    '#title' => 'Tell us about yourself, the work that you do, and why you want to be a part of the 
    Taglit Fellows program. How do you see yourself contributing to your role as staff and in ensuring 
    the ongoing Jewish journey of your participants.',
    '#rows' => 25,
    '#default_value' => $query_select['essay1'],
    '#format' => 'filtered_html',
  );

  $form['essay2'] = array(
    '#type' => 'text_format',
    '#title' => '<p>Answer one of the following questions:
      <ul><li>If you were taking someone to Israel for the first time, what is one experience you want them to have and why?</li>
      <li>Describe three qualities that you think important in a leader and why.</li>
      <li>Identify 1-2 issues in Jewish life that interest you and ignite your passion. Please share some ways that you are 
      expressing this passion and involving yourself with these issues in your day-to-day life.</li>
      </ul>',
    '#rows' => 25,
    '#default_value' => $query_select['essay2'],
    '#format' => 'filtered_html',
  );
  

  $form['save'] = array(
    '#type' => 'submit',
    '#name' => 'save',
    '#value' => t('Save & Return Later'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#name' => 'submit',
    '#value' => t('Submit'),
  );
  $form['return'] = array(
    '#type' => 'submit',
    '#name' => 'return',
    '#value' => t('Return to Application Page'),
  );  
  return $form;
}

function taglit_apply_secf_form_submit($form, &$form_state) {
	global $user;
  
  if ($form_state['triggering_element']['#name'] == 'submit') {
	  $query = db_update('taglit_apply')
  	->fields(
  		array(
	    	'essay1' 	=> 	$form_state['values']['essay1']['value'],
	    	'essay2' 	=> 	$form_state['values']['essay2']['value'],
				'secf_complete' => 1
			)
		)
  ->condition('uid', $user->uid, '=')
  ->execute();
  
  $form_state['redirect'] = 'program-application';
  }
  elseif ($form_state['triggering_element']['#name'] == 'save') {
		$query = db_update('taglit_apply')
  	->fields(
  		array(
	    	'essay1' 	=> 	$form_state['values']['essay1']['value'],
	    	'essay2' 	=> 	$form_state['values']['essay2']['value'],
				'secf_complete' => 0
			)
		)
  ->condition('uid', $user->uid, '=')
  ->execute();
  
  $form_state['redirect'] = 'program-application';	  
  }
  elseif ($form_state['triggering_element']['#name'] == 'return') {
	  $form_state['redirect'] = 'program-application';
  }
}
