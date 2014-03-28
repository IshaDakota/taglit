<?php

/**
 * @file
 * Form function for the Taglit Fellows Application module.
 */
function taglit_apply_secd_form($form, $form_state) {
  global $user; //Get the current user.
	
	taglit_apply_check_app_exists($user);
	
  $query_select = db_select('taglit_apply') //Query the database to see of the user has a record.
	  ->fields('taglit_apply')
	  ->condition('uid', $user->uid, '=')
	  ->execute()
	  ->fetchAssoc();  
  
  $curric_program = unserialize($query_select['curric_program']);
  $curric_date = unserialize($query_select['curric_date']);
  $curric_role = unserialize($query_select['curric_role']);
 
  $count_array = count($curric_program);
  if ($count_array == 0) {
    $count_array++;
  }

  $form = array(); //Build the form.
  
   $form['prof_development'] = array(
    '#type' => 'radios',
    '#title' => t('Have you been a participant on a Taglit-Birthright Israel trip?'),
    '#options' => array(
      0 => t('Taglit Fellows will be my first professional development opportunity in Jewish or Israel education.'),
      1 => t('I have participated in the following professional development in Jewish or Israel education.'),
      ),
    '#default_value' => $query_select['israel_birthright'],
  );
    
  if (empty($form_state['num_items'])) {
    $form_state['num_items'] = $count_array;
  }

  // Build the number of name fieldsets indicated by $form_state['num_names']
  for ($i = 1; $i <= $form_state['num_items']; $i++) {
    $form['program'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Program #@num', array('@num' => $i)),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
      '#states' => array(
  	    'visible' => array(  // Action to take: Make visible.
  	      ':input[name="prof_development"]'  => array(
            array('value' => t('1')),
          )
        ),
      ),     
    );

    $form['program'][$i]['curric_program'] = array(
      '#type' => 'textfield',
      '#title' => t('Program/Project'),
      '#size' => 100,
      '#maxlength' => 250,
      '#default_value' => isset($curric_program[$i]) ? $curric_program[$i] : NULL,
      );
    $form['program'][$i]['curric_date'] = array(
      '#type' => 'textfield',
      '#title' => t('Date'),
      '#size' => 100,
      '#maxlength' => 250,
      '#default_value' => isset($curric_date[$i]) ? $curric_date[$i] : NULL,
    );
    $form['program'][$i]['curric_role'] = array(
      '#type' => 'textfield',
      '#title' => t('Your Role'),
      '#size' => 100,
      '#maxlength' => 250,
      '#default_value' => isset($curric_role[$i]) ? $curric_role[$i] : NULL,      
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

function taglit_apply_secd_form_submit($form, &$form_state) {
   global $user;

  //create arrays for the program fields
  $curric_program = array();
  $curric_date = array();
  $curric_role = array();
  
  for ($i = 1; $i <= $form_state['num_items']; $i++) {
    $curric_program[$i] = $form_state['values'][$i]['curric_program'];
    $curric_date[$i] = $form_state['values'][$i]['curric_date'];
    $curric_role[$i] = $form_state['values'][$i]['curric_role'];
  }
    
  $query = db_update('taglit_apply')
  ->fields(array(
    'prof_development' => $form_state['values']['prof_development'],
    'curric_program' => serialize($curric_program),
    'curric_date' => serialize($curric_date),
    'curric_role' => serialize($curric_role),
    'secd_complete' => 1
  ))
  ->condition('uid', $user->uid, '=')
  ->execute();
  $form_state['redirect'] = 'program-application';
}
