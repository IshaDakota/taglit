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
      submit your application for the Taglit Fellows 
      Program. You may complete work in one section and then return at 
      a later point to complete additional sections. The entire application 
      must be complete by May 15, 2014.') . '</p>',
    ),
  );
  if ($app_complete == 'N') {
    $output[] = array(
      'section-seven' => array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('When you have completed sections 1 - 6, an additional section 
        (Section 7: Declaration) will appear. After you sign and submit the 
        declaration, your application will be locked and you will no longer 
        be able to edit any sections.') . '</p>',
      ),
    );
  }
  $output[] = array(
    'quest_list' => array(
      '#type' => 'markup',
      '#markup' => '<ul class = "application-sections">
        <li class = "' . ($query_select['seca_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section 1: General Information'), 'program-application/section-a') . '</li>
        <li class = "' . ($query_select['secb_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section 2: Education' ), 'program-application/section-b') . '</li>
        <li class = "' . ($query_select['secc_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section 3: Israel Experience'), 'program-application/section-c') . '</li>
        <li class = "' . ($query_select['secd_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section 4: Professional Development in Jewish and Israel Education'), 'program-application/section-d') . '</li>
        <li class = "' . ($query_select['sece_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section 5: Work Experience & References'), 'program-application/section-e') . '</li>
        <li class = "' . ($query_select['secf_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Section 6: Essay'), 'program-application/section-f') . '</li>'
        . ($app_complete == 'Y' ? '<li class = "' . ($query_select['secg_complete'] == 1 ? 'section-complete' : 'section-incomplete') . 
        '">' . l(t('Section 7: Declaration'), 'program-application/section-g') . '</li>' : '') .
           '</ul>',
    ),
    
    'closing' => array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('If you have any questions about your application, please 
      contact Aliza Goodman at 847-418-8336 or ') . 
      '<a href="mailto:aliza@theicenter.org">aliza@theicenter.org</a></p>'
    ),
  );
  
  // For a specific user
  if (user_access('access accepted', $user)) {
    $output[] = array (
      'accepted' => array(
        '#type' => 'markup',
        '#markup' => '<h2>Status: Congratulations on being accepted as a Taglit Fellow!</h2>
         <p>Please complete the following:
         <ul class = "application-sections">
         <li class = "' . ($query_select['secagmt_complete'] == 1 ? 'section-complete' : 'section-incomplete') . '">' .
          l(t('Confirm your acceptance and submit the Letter of Agreement by Monday, July 7'), 'program-application/agreement-letter') . '</li>
          
          <li class="section-incomplete">' . l(t('Confirm your attendance at the seminar by completing the
           online registration by Friday, July 11'),  
          'http://taglitfellowsaugust2014.eventbrite.com') . '</li>
          </ul>

    <p>Once we receive your letter of agreement and confirmation, we will be in touch with 
    instructions on how to you to book your travel to Chicago. Upon receiving the travel information 
    email, you will have up to 3 days to contact our travel agent to book your ticket. Please note that 
    we will be covering all expenses associated with the workshop, including transportation costs, 
    room and board.</p>', 
      )  
    );
  }  
  return $output;
}

/**
 * Render the page for the Section A of the Application.
 */
function taglit_apply_seca_page() {
  module_load_include('inc', 'taglit_apply', 'taglit_apply.seca.form');
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
  module_load_include('inc', 'taglit_apply', 'taglit_apply.secb.form');
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
  module_load_include('inc', 'taglit_apply', 'taglit_apply.secc.form');
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Israel Program Information</h2>',
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
  module_load_include('inc', 'taglit_apply', 'taglit_apply.secd.form');
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Professional Development in Jewish and Israel Education</h2>',
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
  module_load_include('inc', 'taglit_apply', 'taglit_apply.sece.form');
	global $user;
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Work Experience & References</h2>',
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
  module_load_include('inc', 'taglit_apply', 'taglit_apply.secf.form');
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Essays</h2>',
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
  module_load_include('inc', 'taglit_apply', 'taglit_apply.secg.form');
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Declaration</h2>',
    ),
    'intro' => array(
      '#type' => 'markup',
      '#markup' => '<p>If offered a position in the Taglit Fellows Program, 
      I agree to meet all of the program requirements 
      including, but not limited to attending seminars, fulfilling the on-line 
      learning requirements, and participating in the mentoring component of the 
      project.</p>
      
      <p>By checking this box you confirm that Taglit Fellows has permission to 
      use any relevant information provided by you. I will contact Taglit Fellows 
      if the use of any information provided should be restricted.</p>

      
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

function taglit_apply_agmt_page() {
  global $user;

  $user_fields=user_load($user->uid);
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

  $applicant_name = $first_name . ' ' . $middle_name . ' ' . $last_name;
  
  module_load_include('inc', 'taglit_apply', 'taglit_apply.agmt.form');
  
  $output =  array(
    'header' => array(
      '#type' => 'markup',
      '#markup' => '<h2 >Letter of Agreement</h2>',
    ),
    'intro' => array(
      '#type' => 'markup',
      '#markup' => '<p>This memorandum of understanding is between The Taglit 
      Fellows Program and ' . $applicant_name . ', 2014 Taglit Fellow (“the fellow”)</p>

      <p>It describes roles and responsibilities for the fellow.

      <p>The goal of the fellowship is to develop an elite cadre of American 
      experiential Jewish educators to enhance Taglit-Birthright Israel 
      experiences and the broader field of Israel and Jewish education.

      <p>Taglit Fellows will work together from July 2014 through December 2014 
      on a number of activities related to intensive professional development 
      for experiential Jewish educators to staff Taglit-Birthright Israel trips. 
      Each fellow will be required to complete the following:

      <ul>
      <li>Fully attend and participate in the upcoming August 24-27, 2014 
      workshop in Chicago, IL.</li>

      <li>Understand that acceptance to the Taglit Fellows program is the 
      first step in being considered for certification as a Taglit Fellow. 
      The Taglit Fellows Educational Committee reserves the right to make 
      a final decision on which participants will receive certification 
      from the program based upon participation and evaluation at the 
      in-person workshop and successful completion of all other commitments 
      and milestones as outlined below.</li>

      <li>Staff a minimum of three Taglit-Birthright Israel trips within three 
      years of completing the program, with a commitment to staff the first 
      of these trips within the first 12 months of the end of the workshop 
      listed above.</li>
      
      <li>The Taglit Fellows, Taglit Birthright Israel nor the iCenter are 
      the employers of the graduates of the Taglit Fellows program with regards 
      to staffing Taglit-Birthright Israel buses following program completion. 
      Employment of Taglit Fellows is by agreement between the Fellow and the 
      specific Taglit-Birthright Israel accredited Trip Organizer.</li>
      </ul>
      
      <p>In addition, each fellow must understand and sign in agreement to the 
      following: 

      <ul>
      <li>Accepting a spot on Taglit Fellows commits me to online and distance 
      learning before and after the August workshop, with milestone achievements 
      (such as educational projects and proof of comprehension of policies and 
      learning concepts).</li>
      
      <li>Post-trip engagement with all of the participants on the bus(es) staffed 
      by a Taglit Fellow will also be a part of their responsibilities as 
      a Taglit Fellow. And, that assisting participants on their continued Jewish 
      journeys beyond their ten-day trip is considered part of the Taglit 
      Fellows mission.</li>
      </ul>',
    ),
    'display_form' => drupal_get_form('taglit_apply_agmt_form'),

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

  $applicant_name = $first_name . ' ' . $middle_name . ' ' . $last_name;
  $output =  array();
  
  $output['name'] = array(
    '#type' => 'markup',
    '#markup' => '<h2>Applicant: ' . $applicant_name . '</h2>',
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
      '#markup' => '<div class="step"><h2>General Information</h2>
        <div class="step-question"><strong>Street Address:</strong> ' . $query_select['street_address'] . '</div>
        <div class="step-question"><strong>City:</strong> ' . $query_select['city'] . '</div>
        <div class="step-question"><strong>State:</strong> ' . $query_select['state'] . '</div>
        <div class="step-question"><strong>Zip:</strong> ' . $query_select['zip'] . '</div>
        <div class="step-question"><strong>Country:</strong> ' . $query_select['country'] . '</div>
        <div class="step-question"><strong>Mobile Phone</strong>: ' . $query_select['mobile_phone'] . '</div>
        </div>',
    );     
  }
  else {
    $output['step-1'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>General Information</h2>
        <div class="step-incomplete">Section not yet completed.</div>
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
      '#markup' => '<div class="step"><h2>Education</h2>
      <table>
      <tr><th>School</th><th>Dates</th><th>Location</th><th>Degree</th></tr>',  
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
    $output['step-2-remainder'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step-question"><strong>Languages:</strong> ' . $query_select['languages'] . '</div>
        <div class="step-question"><strong>Other Skills/Certifications:</strong> ' . $query_select['other_skills'] . '</div>
        <div class="step-question"><strong>Jewish Elementary:</strong> ' . $query_select['jewish_elementary'] . ' years</div>
        <div class="step-question"><strong>Jewish High School:</strong> ' . $query_select['jewish_highschool'] . ' years</div>
        <div class="step-question"><strong>Jewish Supplementary:</strong> ' . $query_select['jewish_supplementary'] . ' years</div>
        <div class="step-question"><strong>Jewish Camp</strong>: ' . $query_select['jewish_camp'] . ' summers' . 
          ($query_select['jewish_camp'] != 0 ?  ' - ' . $query_select['jewish_camp_name'] : '') . ' </div>
        <div class="step-question"><strong>Jewish Youth Group</strong>: ' . 
          ($query_select['jewish_youthgroup'] == 0 ? 'N' : 'Y - ' . $query_select['jewish_youthgroup_name']) . '</div>
        </div>
        <div class="step-question"><strong>Jewish Background:</strong> ' . $query_select['jewish_background'] .'</div>',
        
    );     

  }
  else {
    $output['step-2'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Education</h2>
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
    
    $output['step-3-header'] = array(
        '#type' => 'markup',
        '#markup' => '<div class="step"><h2>Israel Experience</h2>
        <div class="step-question"><strong>BRI Alum</strong>: ' . 
          ($query_select['israel_birthright'] == 0 ? 'N' : 'Y - ' . $query_select['israel_birthright_provider']) . '</div>
        <div class="step-question"><strong>BRI Staff</strong>: ' . 
          ($query_select['israel_birthright_staff'] == 0 ? 'N' : 'Y - ' . $query_select['israel_birthright_staff_num'] . 
          ' times with ' .  $query_select['israel_birthright_staff_provider']) . '</div>'
      );
    
    if ($count_array != 0) {    
      $output['step-3-table-start'] = array(
        '#type' => 'markup',
        '#markup' => '<table>
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
    $output['step-3-footer'] = array(
      '#type' => 'markup',
      '#markup' => '</div>',  
    );   
  }
  else {
    $output['step-3'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Israel Experience</h2>
        <div class="step-incomplete">Step not yet completed.</div>
        </div>',
    );        
  }

  if ($query_select['secd_complete'] == 1) {
    $curric_program = unserialize($query_select['curric_program']);
    $curric_date = unserialize($query_select['curric_date']);
    $curric_role = unserialize($query_select['curric_role']);

    $count_array = count($curric_program);

    $output['step-4-header'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Professional Development</h2>',  
    );
          
    if ($count_array != 0) {
    
      $output['step-4-table-start'] = array(
        '#type' => 'markup',
        '#markup' => '<table>
          <tr><th>Program/Project</th><th>Dates</th><th>Role</th></tr>',  
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
    $output['step-4-footer'] = array(
      '#type' => 'markup',
      '#markup' => '</div>',  
    );
  }
  else {
    $output['step-4'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Israel Programming/Curriculum</h2>
        <div class="step-incomplete">Step not yet completed.</div>
        </div>',
    );        
  }
  
  if ($query_select['sece_complete'] == 1) {
    $output['step-5'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Work Experience</h2>
        <div class="step-question"><strong>Uploaded CV/Resume:</strong> <a href="/' . variable_get("file_public_path", conf_path() . "/files/") .  $query_select['cv_file_path'] . '">' . $query_select['cv_file_path'] . '</a></div>
        <div class="step-question"><strong>References:</strong></div>
        <div class="step-answer">' . nl2br($query_select['recommend']) . '</div>
        
        </div>',
    );     
  }
  else {
    $output['step-5'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Work Experience</h2>
        <div class="step-incomplete">Step not yet completed.</div>
        </div>',
    );        
  }
  
  if ($query_select['secf_complete'] == 1) {
    $output['step-6'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Essays</h2>
        <div class="step-question">Essay #1: </div>
        <div class="step-answer">' . $query_select['essay1'] . '</div>
        <div class="step-question">Essay #2: </div>
        <div class="step-answer">' . $query_select['essay2'] . '</div>
        </div>',
    );     
  }
  else {
    $output['step-6'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Essays</h2>
        <div class="step-incomplete">Step not yet completed.</div>
        </div>',
    );
  }

  if ($query_select['secg_complete'] == 1) {
    $output['step-7'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Declaration</h2>
        <div class="step-question">Referred by: </div>
        <div class="step-answer">' . $query_select['referred'] . '</div>
        <div class="step-answer">This application has been submitted and can no longer be edited.</div>
        </div>',
    );     
  }
  else {
    $output['step-7'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="step"><h2>Declaration</h2>
        <div class="step-incomplete">This application has not yet been submitted and can still be edited.</div>
        </div>',
    );
  }  
      
  return $output;
}

function taglit_apply_complete_page() { 
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
    'body-text' => array(
      '#type' => 'markup',
      '#markup' => '<p>' . t('Congratulations - your application is completed and submitted.') . '</p>
      
      <p>' . t('If you have any questions about your application, please 
      contact Aliza Goodman at 847-418-8336 or ') . 
      '<a href="mailto:aliza@theicenter.org">aliza@theicenter.org</a></p>',
    ),
    'main_link' => array(
      '#type' => 'markup',
      '#markup' => '<div class="next-step">' .
      l(t('Return to Application Page'),
      'program-application') . '</div>',
    ),    
  );
  return $output;
}

