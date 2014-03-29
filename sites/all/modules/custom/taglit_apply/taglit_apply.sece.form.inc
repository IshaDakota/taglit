<?php

/**
 * @file
 * Form function for the Taglit Fellows Application module.
 */
function taglit_apply_sece_form($form_state) {
	global $user; //Get the current user.
  
  taglit_apply_check_app_exists($user);
  
  $query_select = db_select('taglit_apply') //Query the database to see of the user has a record.
  ->fields('taglit_apply')
  ->condition('uid', $user->uid, '=')
  ->execute()
  ->fetchAssoc();
  
  $form = array();
  
  $form['prof_status'] = array(
    '#type' => 'radios',
    '#title' => t('I am currently a:'),
    '#options' => array(
      1 => t('Student'),
      2 => t('Graduate/Professional'),
      3 => t('Both'),
    ),
    '#default_value' => $query_select['prof_status'],     
  );

  $form['ed_status'] = array(
    '#type' => 'radios',
    '#title' => t('Educational status:'),
    '#options' => array(
      1 => t('Some undergraduate work completed'),
      2 => t('Undergraduate degree completed'),
      3 => t('Some graduate work completed'),
      4 => t('Graduate degree completed'),
    ),
    '#default_value' => $query_select['ed_status'],     
    '#states' => array(
	    'visible' => array(  // Action to take: Make visible.
	      ':input[name="prof_status"]'  => array(
          array('value' => t('1')),
          array('value' => t('3')),
        )
      ),
    ),     
  );
  
  $form['ed_school_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Current College/University'),
    '#size' => 100,
    '#maxlength' => 250,
    '#required' => FALSE,
    '#default_value' => $query_select['ed_school_name'], 
    '#states' => array(
      'visible' => array(  // Action to take: Make visible.
  	    ':input[name="prof_status"]'  => array(
          array('value' => t('1')),
          array('value' => t('3')),
        ),
      ),
    ),     
  );  

  $form['prof_employer'] = array(
    '#type' => 'textfield',
    '#title' => t('Employer'),
    '#size' => 100,
    '#maxlength' => 250,
    '#required' => FALSE,
    '#default_value' => $query_select['prof_employer'], 
    '#states' => array(
      'visible' => array(  // Action to take: Make visible.
  	    ':input[name="prof_status"]'  => array(
          array('value' => t('2')),
          array('value' => t('3')),
        ),
      ),
    ),     
  ); 

  $form['prof_position'] = array(
    '#type' => 'textfield',
    '#title' => t('Current Position'),
    '#size' => 100,
    '#maxlength' => 250,
    '#required' => FALSE,
    '#default_value' => $query_select['prof_position'], 
    '#states' => array(
      'visible' => array(  // Action to take: Make visible.
  	    ':input[name="prof_status"]'  => array(
          array('value' => t('2')),
          array('value' => t('3')),
        ),
      ),
    ),     
  );     
  
  if ($query_select['sece_complete'] == 1) {
		$form['uploaded-file'] = array(
	  	'#markup' => '<p><strong>Current File: </strong><a href="http://' . variable_get("file_public_path", conf_path() . "/files/") . $query_select['cv_file_path'] . '">' . $query_select['cv_file_path'] . '</a></p>
	  	<p>If you upload a file below, it will replace this one.</p>',
		);
	}
  $form['file'] = array(
    '#type' => 'file',
    '#title' => t('Upload a copy of your CV (one page only)'),
    '#description' => t('Upload a file, allowed extensions: doc, docx, txt'),
  );
  
  $form['recommend'] = array(
    '#type' => 'textarea',
    '#title' => '<p>Please list at least two references, each on separate lines as below:
      <br><em>Bruce Wayne, Jewish Federation of Greater Gotham, batman@shalomgotham.org, 808-555-1234</em>
      <br><em>Richard Grayson, Gotham City College Hillel, robin@gcchillel.org, 808-555-4321</em></p>',
    '#rows' => 5,
    '#default_value' => $query_select['recommend'],
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Validate handler for taglit_apply_sece_form().
 */
function taglit_apply_sece_form_validate($form, &$form_state) {
  $file = file_save_upload('file', array(
    'file_validate_extensions' => array('doc docx txt'), // Validate extensions.
  ));
  // If the file passed validation:
  if ($file) {
    // Move the file, into the Drupal file system
    if ($file = file_move($file, 'public://')) {
      // Save the file for use in the submit handler.
      $form_state['storage']['file'] = $file;
    }
    else {
      form_set_error('file', t('Failed to write the uploaded file to the site\'s file folder.'));
    }
  }
  else {
    form_set_error('file', t('No file was uploaded.'));
  }
}

/**
 * Submit handler for taglit_apply_sece_form().
 */
function taglit_apply_sece_form_submit($form, &$form_state) {
  $file = $form_state['storage']['file'];
  // We are done with the file, remove it from storage.
  unset($form_state['storage']['file']);
  // Make the storage of the file permanent
  $file->status = FILE_STATUS_PERMANENT;
  // Save file status.
  file_save($file);
	global $user;
	
  $query = db_update('taglit_apply')
  	->fields(
  		array(
        'prof_status' 	=> 	$form_state['values']['prof_status'],
        'ed_status' 	=> 	$form_state['values']['ed_status'],
        'ed_school_name' 	=> 	$form_state['values']['ed_school_name'],
        'prof_employer' 	=> 	$form_state['values']['prof_employer'],
        'prof_position' 	=> 	$form_state['values']['prof_position'],
	    	'recommend' 	=> 	$form_state['values']['recommend'],
	    	'cv_file_path' 	=> 	$file->filename,
				'sece_complete' => 1
			)
		)
  ->condition('uid', $user->uid, '=')
  ->execute();
  
  $form_state['redirect'] = 'program-application';

}
