<?php

/**
 * @file
 * Form function for the Taglit Fellows Application module.
 */
function taglit_apply_secc_form($form, $form_state) {
  global $user; //Get the current user.
	
	taglit_apply_check_app_exists($user);
	
  $query_select = db_select('taglit_apply') //Query the database to see of the user has a record.
	  ->fields('taglit_apply')
	  ->condition('uid', $user->uid, '=')
	  ->execute()
	  ->fetchAssoc();  
  
  $israel_program = unserialize($query_select['israel_program']);
  $israel_date = unserialize($query_select['israel_date']);
  $israel_focus = unserialize($query_select['israel_focus']);
  $israel_role = unserialize($query_select['israel_role']);
 
  $count_array = count($israel_program);
  if ($count_array == 0) {
    $count_array++;
  }

  $form = array(); //Build the form.
  
  if (empty($form_state['num_items'])) {
    $form_state['num_items'] = $count_array;
  }

 $form['israel_birthright'] = array(
    '#type' => 'radios',
    '#title' => t('Have you been a participant on a Taglit-Birthright Israel trip?'),
    '#options' => array(
      0 => t('No'),
      1 => t('Yes'),
      ),
    '#default_value' => $query_select['israel_birthright'],
  );
  
  $form['israel_birthright_provider'] = array(
    '#type' => 'textfield',
    '#title' => t('When and with what provider?'),
    '#size' => 100,
    '#maxlength' => 250,
    '#required' => FALSE,
    '#default_value' => $query_select['israel_birthright_provider'], 
    '#states' => array(
	    'visible' => array(  // Action to take: Make visible.
	      ':input[name="israel_birthright"]'  => array(
          array('value' => t('1')),
        )
      ),
    ),     
  );

 $form['israel_birthright_staff'] = array(
    '#type' => 'radios',
    '#title' => t('Have you staffed a Taglit-Birthright Israel trip?'),
    '#options' => array(
      1 => t('Yes'),
      2 => t('No'),
      ),
    '#default_value' => $query_select['israel_birthright'],
  );
  
  $form['israel_birthright_staff_num'] = array(
    '#type' => 'select',
    '#title' => t('How many times?'),
    '#options' => array(
      0 => t('0'),
      1 => t('1'),
      2 => t('2'),
      3 => t('3'),
      4 => t('4'),
      5 => t('5'),
      6 => t('6'),
      7 => t('7'),
      8 => t('8'),
      9 => t('9'),
      10 => t('10'),
      11 => t('11'),
      12 => t('12+'),
    ),
    '#default_value' => $query_select['israel_birthright_staff_num'], 
    '#states' => array(
	    'visible' => array(  // Action to take: Make visible.
	      ':input[name="israel_birthright_staff"]'  => array(
          array('value' => t('1')),
        )
      ),
    ),     
  );
  
  $form['israel_birthright_staff_provider'] = array(
    '#type' => 'textfield',
    '#title' => t('For which provider(s)?'),
    '#size' => 100,
    '#maxlength' => 250,
    '#required' => FALSE,
    '#default_value' => $query_select['israel_birthright_staff_provider'], 
    '#states' => array(
	    'visible' => array(  // Action to take: Make visible.
	      ':input[name="israel_birthright_staff"]'  => array(
          array('value' => t('1')),
        )
      ),
    ),     
  );
  
   $form['intro'] = array(
    '#markup' => '<p>In addition to Taglit-Birthright Israel, please list your 
    educational programs/experiences in Israel beginning with the most recent 
    (list both participant and staff experiences):</p>',
  );

  // Build the number of name fieldsets indicated by $form_state['num_names']
  for ($i = 1; $i <= $form_state['num_items']; $i++) {
    $form['program'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Program #@num', array('@num' => $i)),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );

    $form['program'][$i]['israel_program'] = array(
      '#type' => 'textfield',
      '#title' => t('Name of Program'),
      '#size' => 100,
      '#maxlength' => 250,
      '#default_value' => isset($israel_program[$i]) ? $israel_program[$i] : NULL,
      );
    $form['program'][$i]['israel_date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date'),
      '#size' => 100,
      '#maxlength' => 250,
      '#default_value' => isset($israel_date[$i]) ? $israel_date[$i] : NULL,
    );
    $form['program'][$i]['israel_focus'] = array(
      '#title' => t('Focus of Program'),
      '#type' => 'textfield',
      '#size' => 100,
      '#maxlength' => 250,
      '#default_value' => isset($israel_focus[$i]) ? $israel_focus[$i] : NULL,      
    );
    $form['program'][$i]['israel_role'] = array(
      '#type' => 'textfield',
      '#title' => t('Role (Leader/Participant)'),
      '#size' => 100,
      '#maxlength' => 250,
      '#default_value' => isset($israel_role[$i]) ? $israel_role[$i] : NULL,      
    );
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  // Adds "Add another program" button
  $form['add_program'] = array(
    '#type' => 'submit',
    '#value' => t('Add another program'),
    '#submit' => array('taglit_apply_add_item'),
  );

  // If we have more than one name, this button allows removal of the
  // last name.
  if ($form_state['num_items'] > 1) {
    $form['remove_program'] = array(
      '#type' => 'submit',
      '#value' => t('Remove last program'),
      '#submit' => array('taglit_apply_remove_item'),
      
      // Since we are removing a name, don't validate until later.
      '#limit_validation_errors' => array(),
    );
  }
    
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  return $form;
}

function taglit_apply_secc_form_submit($form, &$form_state) {
   global $user;

  //create arrays for the program fields
  $israel_program = array();
  $israel_date = array();
  $israel_focus = array();
  $israel_role = array();
  
  for ($i = 1; $i <= $form_state['num_items']; $i++) {
    $israel_program[$i] = $form_state['values'][$i]['israel_program'];
    $israel_date[$i] = $form_state['values'][$i]['israel_date'];
    $israel_focus[$i] = $form_state['values'][$i]['israel_focus'];
    $israel_role[$i] = $form_state['values'][$i]['israel_role'];
  }

  $query = db_update('taglit_apply')
  ->fields(array(
    'israel_birthright' 	=> 	$form_state['values']['israel_birthright'],  
    'israel_birthright_provider' 	=> 	$form_state['values']['israel_birthright_provider'],  
    'israel_birthright_staff' 	=> 	$form_state['values']['israel_birthright_staff'],  
    'israel_birthright_staff_num' 	=> 	$form_state['values']['israel_birthright_staff_num'],  
    'israel_birthright_staff_provider' 	=> 	$form_state['values']['israel_birthright_staff_provider'],  
    'israel_program' => serialize($israel_program),
    'israel_date' => serialize($israel_date),
    'israel_focus' => serialize($israel_focus),
    'israel_role' => serialize($israel_role),
    'secc_complete' => 1
  ))
  ->condition('uid', $user->uid, '=')
  ->execute();
  $form_state['redirect'] = 'program-application';
}
