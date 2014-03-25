<?php
/**
 * @file
 * Pages for the Taglit Fellows Application module.
 */

/**
 * Render the page for the Application home and status.
 */
function taglit_apply_page() { 
  global $user;
	
	$query_select = db_select('taglit_apply') //Query the database to see of the user has a record.
  ->fields('taglit_apply')
  ->condition('uid', $user->uid, '=')
  ->execute()
  ->fetchAssoc();
  if ($query_select['seca_complete'] && 
    $query_select['secb_complete'] && 
    $query_select['secc_complete'] && 
    $query_select['secd_complete'] && 
    $query_select['sece_complete'] && 
    $query_select['secf_complete']) {
      $app_complete = 'Y';
    } 
    else {
      $app_complete = 'N';
    }
  $output =  array(    
    'introduction' => array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('Please complete all of the sections below to 
      submit your application for the Masters Concentration in Israel 
      Program. You may complete work in one section and then return at 
      a later point to complete additional sections. The entire application 
      must be complete by January 15, 2014') . '</p>
      
      <p>' . t('When you have completed sections A - F, an additional section 
      (Section G: Declaration) will appear. After you sign and submit the 
      declaration, you application will be locked and you will no longer 
      be able to edit any sections.') . '</p>
      
      <p>' . t('If you have any questions about your application, please 
      contact Rachel Levin at 847-418-8336 or ') . 
      '<a href="mailto:rachel@theicenter.org">rachel@theicenter.org</a></p>',
    ),
    'quest_list' => array(
      '#type' => 'markup',
      '#markup' => '<ul class = "application-sections">
        <li class = "' . ($query_select['seca_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section A: General Information'), 'program-application/section-a') . '</li>
        <li class = "' . ($query_select['secb_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section B: Education' ), 'program-application/section-b') . '</li>
        <li class = "' . ($query_select['secc_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section C: Israel Experience'), 'program-application/section-c') . '</li>
        <li class = "' . ($query_select['secd_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section D: Israel Programming/Curriculum'), 'program-application/section-d') . '</li>
        <li class = "' . ($query_select['sece_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section E: Work Experience'), 'program-application/section-e') . '</li>
        <li class = "' . ($query_select['secf_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section F: Essay'), 'program-application/section-f') . '</li>'
        . ($app_complete == 'Y' ? '<li class = "' . ($query_select['secg_complete'] == 1 ? 'section-complete' : 'section-incomplete') . 
        '">' . l(t('Section G: Declaration'), 'program-application/section-g') . '</li>' : '') .
           '</ul>',
    ),
    'app_complete' => array(
      '#type' => 'markup',
      '#markup' => ''
    ),
  );
  return $output;
}

/**
 * Render the page for the Section A of the Application.
 */
function taglit_apply_seca_page() {
  $output =  array(
    'note' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >General Information</h2>',
    ),      
    'display_form' => drupal_get_form('taglit_apply_seca_form'),

    'main_link' => array(
      '#type' => 'markup',
      '#markup' => '<div class="next-step">' .
      l(t('Return to Application Page'),
      'program-application') . '</div>',
    ),
  );    
  return $output;
}

/**
 * Render the page for the Section B of the Application.
 */
function taglit_apply_secb_page() {
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Education Information</h2>',
    ),
    'intro' => array(
      '#type' => 'markup',
      '#markup' => '<p>Beginning with current or most recent, please list 
      colleges and universities attended:</p>',
    ),
    'display_form' => drupal_get_form('taglit_apply_secb_form'),

    'main_link' => array(
      '#type' => 'markup',
      '#markup' => '<div class="next-step">' .
      l(t('Return to Application Page'),
      'program-application') . '</div>',
    ),
  );    
  return $output;
}

/**
 * Render the page for the Section C of the Application.
 */
function taglit_apply_secc_page() {
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Israel Program Information</h2>',
    ),
    'intro' => array(
      '#type' => 'markup',
      '#markup' => '<p>Beginning with most recent, please list your 
      educational programs/experiences in Israel.:</p>',
    ),
    'display_form' => drupal_get_form('taglit_apply_secc_form'),

    'main_link' => array(
      '#type' => 'markup',
      '#markup' => '<div class="next-step">' .
      l(t('Return to Application Page'),
      'program-application') . '</div>',
    ),
  );    
  return $output;
}

/**
 * Render the page for the Section D of the Application.
 */
function taglit_apply_secd_page() {
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Israel Programming/Curriculum</h2>',
    ),
    'intro' => array(
      '#type' => 'markup',
      '#markup' => '<p>In what capacity have you been involved in working on 
      Israel Programming/Curriculum development in formal, informal or 
      experiential settings? Please list up to three examples.</p>',
    ),
    'display_form' => drupal_get_form('taglit_apply_secd_form'),
    'main_link' => array(
      '#type' => 'markup',
      '#markup' => '<div class="next-step">' .
      l(t('Return to Application Page'),
      'program-application') . '</div>',
    ),
  );    
  return $output;
}

/**
 * Render the page for the Section E of the Application.
 */
function taglit_apply_sece_page() {
	global $user;
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Work Experience</h2>',
    ),
    'intro' => array(
      '#type' => 'markup',
      '#markup' => '<p>Please upload a copy of your CV.</p>',
    ),
    'display_form' => drupal_get_form('taglit_apply_sece_form'),

    'main_link' => array(
      '#type' => 'markup',
      '#markup' => '<div class="next-step">' .
      l(t('Return to Application Page'),
      'program-application') . '</div>',
    ),
  );    
  return $output;
}

/**
 * Render the page for the Section F of the Application.
 */
function taglit_apply_secf_page() {
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Essay</h2>',
    ),
    'intro' => array(
      '#type' => 'markup',
      '#markup' => '<p>In the space below, please answer one of 
      the following questions. Responses should not exceed 500 words.</p>',
    ),
    'display_form' => drupal_get_form('taglit_apply_secf_form'),

    'main_link' => array(
      '#type' => 'markup',
      '#markup' => '<div class="next-step">' .
      l(t('Return to Application Page'),
      'program-application') . '</div>',
    ),
  );    
  return $output;
}

/**
 * Render the page for the Section G of the Application.
 */
function taglit_apply_secg_page() {
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Declaration</h2>',
    ),
    'intro' => array(
      '#type' => 'markup',
      '#markup' => '<p>If offered a position in the Concentration in Israel 
      Education Program, I agree to meet all of the program requirements 
      including, but not limited to attending all seminars, taking the required 
      courses, participating in the mentoring component and presenting a final 
      project.</p>
      <p>Once you submit this declaration, your application will be submitted, 
      and you will no longer be able to edit any sections.</p>',
    ),
    'display_form' => drupal_get_form('taglit_apply_secg_form'),

    'main_link' => array(
      '#type' => 'markup',
      '#markup' => '<div class="next-step">' .
      l(t('Return to Application Page'),
      'program-application') . '</div>',
    ),
  );    
  return $output;
}

/**
 * Render the display for the application for a certain user.
 */
function taglit_apply_user_page() {
   $userid = arg(1); //Get the user of the page we are on.
   global $user; //get the user viewing the page.

  $query_select = db_select('taglit_apply') //Query the database to see of the user has a record.
  ->fields('taglit_apply')
  ->condition('uid', $userid, '=')
  ->execute()
  ->fetchAssoc();
  
  $user_fields=user_load($userid);
  if (isset($user_fields->field_first_name['und']['0']['value'])) { 
    $first_name = $user_fields->field_first_name['und']['0']['value'];
  } 
  else{
    $first_name = NULL;
  }
  if (isset($user_fields->field_middle_name['und']['0']['value'])) { 
    $middle_name = $user_fields->field_middle_name['und']['0']['value'];
  }
  else {
    $middle_name =NULL;
  }
  if (isset($user_fields->field_last_name['und']['0']['value'])) { 
    $last_name = $user_fields->field_last_name['und']['0']['value'];
  }  
  else {
    $last_name = NULL;  
  }
  if (isset($user_fields->field_university_program['und']['0']['value'])) { 
    $university_program = $user_fields->field_university_program['und']['0']['value'];
  }  
  else {
    $university_program = NULL;  
  }

  $applicant_name = $first_name . ' ' . $middle_name . ' ' . $last_name;
  $output =  array();
  
  $output['name'] = array(
    '#type' => 'markup',
    '#markup' => '<h2>Applicant: ' . $applicant_name . '<br>
                  School: ' . $university_program . '</h2>',
  );

  if ($query_select['secg_complete'] != 1 && $userid == $user->uid) {
    $output['edit'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="edit-section"><a href="/program-application">Edit this application</a></div>',
      );
    }

  if ($query_select['seca_complete'] == 1) {
    $output['step-1'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section A: General Information</h2>
        <div class="step-question"><strong>Street Address:</strong> ' . $query_select['street_address'] . '</div>
        <div class="step-question"><strong>City:</strong> ' . $query_select['city'] . '</div>
        <div class="step-question"><strong>State:</strong> ' . $query_select['state'] . '</div>
        <div class="step-question"><strong>Zip:</strong> ' . $query_select['zip'] . '</div>
        <div class="step-question"><strong>Country:</strong> ' . $query_select['country'] . '</div>
        <div class="step-question"><strong>Citizenship</strong>: ' . ($query_select['us_citizen'] ? 'United States' : $query_select['citizen_other']) . '</div>
        </div>',
    );     
  }
  else {
    $output['step-1'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section A: General Information</h2>
        <div class="step-incomplete">Step not yet completed.</div>
        </div>',
    );        
  }
  
  if ($query_select['secb_complete'] == 1) {
    $education_school = unserialize($query_select['education_school']);
    $education_date = unserialize($query_select['education_date']);
    $education_location = unserialize($query_select['education_location']);
    $education_degree = unserialize($query_select['education_degree']);
    $count_array = count($education_school);
    
    if ($count_array == 0) {
      $count_array++;
    }
    
    $output['step-2-table-start'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section B: Education</h2>
      <table>
      <tr><th>School</th><th>Dates</th><th>Location</th><th>Degree</th><tr>',  
    );
    
    $row_class = 'even';
    
    for ($i = 1; $i <= $count_array; $i++) {
      if($i%2 == 0) {
        $row_class = 'even';
      }
      else
      {
        $row_class = 'odd';
      }
      
      $output['step-2-row' .$i] = array(
        '#type' => 'markup',
        '#markup' => '<tr class="' . $row_class . '"><td>' .
        $education_school[$i] . '</td><td>' .
        $education_date[$i] . '</td><td>' .
        $education_location[$i] . '</td><td>' .
        $education_degree[$i] . '</td></tr>',
      );
    }

    $output['step-2-table-end'] = array(
      '#type' => 'markup',
      '#markup' => '</table>',  
    );   
  }
  else {
    $output['step-2'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section B: Education</h2>
        <div class="step-incomplete">Step not yet completed.</div>
        </div>',
    );        
  }
  
  if ($query_select['secc_complete'] == 1) {
    $israel_program = unserialize($query_select['israel_program']);
    $israel_date = unserialize($query_select['israel_date']);
    $israel_focus = unserialize($query_select['israel_focus']);
    $israel_role = unserialize($query_select['israel_role']);

    $count_array = count($israel_program);
    
    if ($count_array == 0) {
      $count_array++;
    }
    
    $output['step-3-table-start'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section C: Israel Experience</h2>
      <table>
      <tr><th>Program</th><th>Dates</th><th>Program Focus</th><th>Role</th><tr>',  
    );
    
    $row_class = 'even';
    
    for ($i = 1; $i <= $count_array; $i++) {
      if($i%2 == 0) {
        $row_class = 'even';
      }
      else
      {
        $row_class = 'odd';
      }
      
      $output['step-3-row' .$i] = array(
        '#type' => 'markup',
        '#markup' => '<tr class="' . $row_class . '"><td>' .
        $israel_program[$i] . '</td><td>' .
        $israel_date[$i] . '</td><td>' .
        $israel_focus[$i] . '</td><td>' .
        $israel_role[$i] . '</td></tr>',
      );
    }

    $output['step-3-table-end'] = array(
      '#type' => 'markup',
      '#markup' => '</table>',  
    );   
  }
  else {
    $output['step-3'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section C: Israel Experience</h2>
        <div class="step-incomplete">Step not yet completed.</div>
        </div>',
    );        
  }

  if ($query_select['secd_complete'] == 1) {
    $curric_program = unserialize($query_select['curric_program']);
    $curric_date = unserialize($query_select['curric_date']);
    $curric_role = unserialize($query_select['curric_role']);

    $count_array = count($curric_program);
    
    if ($count_array == 0) {
      $count_array++;
    }
    
    $output['step-4-table-start'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section D: Israel Programming/Curriculum</h2>
      <table>
      <tr><th>Program/Project</th><th>Dates</th><th>Role</th><tr>',  
    );
    
    $row_class = 'even';
    
    for ($i = 1; $i <= $count_array; $i++) {
      if($i%2 == 0) {
        $row_class = 'even';
      }
      else
      {
        $row_class = 'odd';
      }
      
      $output['step-4-row' .$i] = array(
        '#type' => 'markup',
        '#markup' => '<tr class="' . $row_class . '"><td>' .
        $curric_program[$i] . '</td><td>' .
        $curric_date[$i] . '</td><td>' .
        $curric_role[$i] . '</td></tr>',
      );
    }

    $output['step-4-table-end'] = array(
      '#type' => 'markup',
      '#markup' => '</table>',  
    );   
  }
  else {
    $output['step-4'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section D: Israel Programming/Curriculum</h2>
        <div class="step-incomplete">Step not yet completed.</div>
        </div>',
    );        
  }
  
  if ($query_select['sece_complete'] == 1) {
    $output['step-5'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section E: Work Experience</h2>
        <div class="step-question"><strong>Uploaded CV/Resume:</strong> <a href="/' . variable_get("file_public_path", conf_path() . "/files/") .  $query_select['cv_file_path'] . '">' . $query_select['cv_file_path'] . '</a></div>
        </div>',
    );     
  }
  else {
    $output['step-5'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section E: Work Experience</h2>
        <div class="step-incomplete">Step not yet completed.</div>
        </div>',
    );        
  }
  
  if ($query_select['secf_complete'] == 1) {
    $output['step-6'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section F: Essay</h2>
        <div class="step-question">Essay: </div>
        <div class="step-answer">' . $query_select['essay'] . '</div>
        </div>',
    );     
  }
  else {
    $output['step-6'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section F: Essay</h2>
        <div class="step-incomplete">Step not yet completed.</div>
        </div>',
    );
  }

  if ($query_select['secg_complete'] == 1) {
    $output['step-7'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section G: Declaration</h2>
        <div class="step-answer">This application has been submitted and can no longer be edited.</div>
        </div>',
    );     
  }
  else {
    $output['step-7'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Section G: Declaration</h2>
        <div class="step-incomplete">This application has not yet been submitted and can still be edited.</div>
        </div>',
    );
  }  
      
  return $output;
}
