<?php

/**
 * @file
 * Form function for the Taglit Fellows Application module.
 */
function taglit_apply_secb_form($form, $form_state) {
  global $user; //Get the current user.
	
	taglit_apply_check_app_exists($user);
	
  $query_select = db_select('taglit_apply') //Query the database to see of the user has a record.
	  ->fields('taglit_apply')
	  ->condition('uid', $user->uid, '=')
	  ->execute()
	  ->fetchAssoc();  
  
  $education_school = unserialize($query_select['education_school']);
  $education_date = unserialize($query_select['education_date']);
  $education_location = unserialize($query_select['education_location']);
  $education_degree = unserialize($query_select['education_degree']);
 
  $count_array = count($education_school);
  if ($count_array == 0) {
    $count_array++;
  }

  $form = array(); //Build the form.
  
  if (empty($form_state['num_items'])) {
    $form_state['num_items'] = $count_array;
  }

  // Build the number of name fieldsets indicated by $form_state['num_names']
  for ($i = 1; $i <= $form_state['num_items']; $i++) {
    $form['school'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('School #@num', array('@num' => $i)),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );

    $form['school'][$i]['education_school'] = array(
      '#type' => 'textfield',
      '#title' => t('Name of School'),
      '#size' => 100,
      '#maxlength' => 250,
      '#required' => TRUE,
      '#default_value' => isset($education_school[$i]) ? $education_school[$i] : NULL,
      );
    $form['school'][$i]['education_location'] = array(
      '#type' => 'textfield',
      '#title' => t('City/State'),
      '#size' => 100,
      '#maxlength' => 250,
      '#required' => TRUE,
      '#default_value' => isset($education_location[$i]) ? $education_location[$i] : NULL,
    );
    $form['school'][$i]['education_date'] = array(
      '#title' => t("Dates Attended"),
      '#type' => 'textfield',
      '#size' => 100,
      '#maxlength' => 250,
      '#required' => TRUE,
      '#default_value' => isset($education_date[$i]) ? $education_date[$i] : NULL,      
    );
    $form['school'][$i]['education_degree'] = array(
      '#type' => 'textfield',
      '#title' => t('Degree Earned'),
      '#size' => 100,
      '#maxlength' => 250,
      '#required' => TRUE,
      '#default_value' => isset($education_degree[$i]) ? $education_degree[$i] : NULL,      
    );
  }
  
  // Adds "Add another program" button
  $form['add_school'] = array(
    '#type' => 'submit',
    '#value' => t('Add another school'),
    '#submit' => array('taglit_apply_add_item'),
  );

  // If we have more than one name, this button allows removal of the
  // last name.
  if ($form_state['num_items'] > 1) {
    $form['remove_school'] = array(
      '#type' => 'submit',
      '#value' => t('Remove last school'),
      '#submit' => array('taglit_apply_remove_item'),
      
      // Since we are removing a name, don't validate until later.
      '#limit_validation_errors' => array(),
    );
  }

  $form['languages'] = array(
    '#type' => 'textarea',
    '#title' => 'Please list on separate lines languages that you speak or understand, and indicate to what level (e.g. Fluent, Reading comprehension, etc.).',
    '#rows' => 5,
    '#default_value' => $query_select['languages'],
    '#format' => 'plain_text',
  );  

  $form['other_skills'] = array(
    '#type' => 'textarea',
    '#title' => 'Please list on separate lines other skills or certifications that you have.',
    '#rows' => 5,
    '#default_value' => $query_select['other_skills'],
    '#format' => 'plain_text',
  ); 

 $form['jewish_elementary'] = array(
    '#type' => 'select',
    '#title' => t('During Grades 1-8 (elementary school), how many years did you attend a full-time Jewish school e.g., Schecter, etc.?'),
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
      ),
    '#default_value' => $query_select['jewish_elementary'],
  );  
  
 $form['jewish_highschool'] = array(
    '#type' => 'select',
    '#title' => t('During Grades 9-12 (high school), how many years did you attend a full-time Jewish school?'),
    '#options' => array(
      0 => t('0'),
      1 => t('1'),
      2 => t('2'),
      3 => t('3'),
      4 => t('4'),
      ),
    '#default_value' => $query_select['jewish_highschool'],
  );  

 $form['jewish_supplementary'] = array(
    '#type' => 'select',
    '#title' => t('How many years did you attend a Jewish supplementary school e.g., Hebrew school?'),
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
    '#default_value' => $query_select['jewish_supplementary'],
  ); 

 $form['jewish_camp'] = array(
    '#type' => 'select',
    '#title' => t('How many summers did you attend a Jewish summer camp as a camper?'),
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
    '#default_value' => $query_select['jewish_camp'],
  );

  $form['jewish_camp_name'] = array(
    '#type' => 'textfield',
    '#title' => t('What camp did you attend? If you attended multiple camps, list them all here (only Jewish camps).'),
    '#size' => 100,
    '#maxlength' => 250,
    '#required' => FALSE,
    '#default_value' => $query_select['jewish_camp_name'], 
    '#states' => array(
	    'visible' => array(  // Action to take: Make visible.
	      ':input[name="jewish_camp"]'  => array(
          array('value' => t('1')),
          array('value' => t('2')),
          array('value' => t('3')),
          array('value' => t('4')),
          array('value' => t('5')),
          array('value' => t('6')),
          array('value' => t('7')),
          array('value' => t('8')),
          array('value' => t('9')),
          array('value' => t('10')),
          array('value' => t('11')),
          array('value' => t('12+')),
        )
      ),
    ),     
  );

 $form['jewish_youthgroup'] = array(
    '#type' => 'radios',
    '#title' => t('Did you belong to a Jewish youth group when you were in high school?'),
    '#options' => array(
      0 => t('No'),
      1 => t('Yes'),
      ),
    '#default_value' => $query_select['jewish_youthgroup'],
  );

  $form['jewish_youthgroup_name'] = array(
    '#type' => 'textfield',
    '#title' => t('What youth group did you belong to? If you belonged to multiple youth groups, list them all here.'),
    '#size' => 100,
    '#maxlength' => 250,
    '#required' => FALSE,
    '#default_value' => $query_select['jewish_youthgroup_name'], 
    '#states' => array(
	    'visible' => array(  // Action to take: Make visible.
	      ':input[name="jewish_youthgroup"]'  => array(
          array('value' => t('1')),
        )
      ),
    ),     
  );
  
 $form['jewish_background'] = array(
    '#type' => 'select',
    '#title' => t('I describe my Jewish background as:'),
    '#options' => array(
      0 => t('Just Jewish'),
      1 => t('Conservative'),
      2 => t('Orthodox'),
      3 => t('Reform'),
      4 => t('Reformative'),
      5 => t('Secular Humanist'),
      6 => t('Reconstructionist'),
      7 => t('Traditional'),
      8 => t('Not Jewish'),
      9 => t('Other'),
      10 => t('Another Religion'),
      ),
    '#required' => TRUE,
    '#default_value' => $query_select['jewish_background'],
  );  
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  return $form;
}

function taglit_apply_secb_form_submit($form, &$form_state) {
   global $user;

  //create arrays for the program fields
  $education_school = array();
  $education_location = array();
  $education_date = array();
  $education_degree = array();
  
  for ($i = 1; $i <= $form_state['num_items']; $i++) {
    $education_school[$i] = $form_state['values'][$i]['education_school'];
    $education_location[$i] = $form_state['values'][$i]['education_location'];
    $education_date[$i] = $form_state['values'][$i]['education_date'];
    $education_degree[$i] = $form_state['values'][$i]['education_degree'];
  }
    
  $query = db_update('taglit_apply')
  ->fields(array(
    'education_school' => serialize($education_school),
    'education_location' => serialize($education_location),
    'education_date' => serialize($education_date),
    'education_degree' => serialize($education_degree),
    'languages' 	=> 	$form_state['values']['languages'],
    'other_skills' 	=> 	$form_state['values']['other_skills'],
    'jewish_elementary' 	=> 	$form_state['values']['jewish_elementary'],
    'jewish_highschool' 	=> 	$form_state['values']['jewish_highschool'],
    'jewish_supplementary' 	=> 	$form_state['values']['jewish_supplementary'],
    'jewish_camp' 	=> 	$form_state['values']['jewish_camp'],
    'jewish_camp_name' 	=> 	$form_state['values']['jewish_camp_name'],
    'jewish_youthgroup' 	=> 	$form_state['values']['jewish_youthgroup'],
    'jewish_youthgroup_name' 	=> 	$form_state['values']['jewish_youthgroup_name'],
    'jewish_background' 	=> 	$form_state['values']['jewish_background'],
    'secb_complete' => 1
  ))
  ->condition('uid', $user->uid, '=')
  ->execute();
  $form_state['redirect'] = 'program-application';
}
