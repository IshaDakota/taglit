<?php

function taglit_apply_seca_form($form, $form_state) {
  global $user; //Get the current user.
  
  taglit_apply_check_app_exists($user);
  
  $query_select = db_select('taglit_apply') //Query the database to see of the user has a record.
  ->fields('taglit_apply')
  ->condition('uid', $user->uid, '=')
  ->execute()
  ->fetchAssoc();
  
  if ($query_select['country'] != 'Canada' && $query_select['country'] != 'United States' && $query_select['country'] != 'Israel') {
	  $country = 'Other';
	  $country_other = $query_select['country'];
  }
  else {
	  $country = $query_select['country'];
	  $country_other = NULL;
  }
    
  $us_states = array(
		'AL'=>"Alabama",
    'AK'=>"Alaska", 
    'AZ'=>"Arizona", 
    'AR'=>"Arkansas", 
    'CA'=>"California", 
    'CO'=>"Colorado", 
    'CT'=>"Connecticut", 
    'DE'=>"Delaware", 
    'DC'=>"District Of Columbia", 
    'FL'=>"Florida", 
    'GA'=>"Georgia", 
    'HI'=>"Hawaii", 
    'ID'=>"Idaho", 
    'IL'=>"Illinois", 
    'IN'=>"Indiana", 
    'IA'=>"Iowa", 
    'KS'=>"Kansas", 
    'KY'=>"Kentucky", 
    'LA'=>"Louisiana", 
    'ME'=>"Maine", 
    'MD'=>"Maryland", 
    'MA'=>"Massachusetts", 
    'MI'=>"Michigan", 
    'MN'=>"Minnesota", 
    'MS'=>"Mississippi", 
    'MO'=>"Missouri", 
    'MT'=>"Montana",
    'NE'=>"Nebraska",
    'NV'=>"Nevada",
    'NH'=>"New Hampshire",
    'NJ'=>"New Jersey",
    'NM'=>"New Mexico",
    'NY'=>"New York",
    'NC'=>"North Carolina",
    'ND'=>"North Dakota",
    'OH'=>"Ohio", 
    'OK'=>"Oklahoma", 
    'OR'=>"Oregon", 
    'PA'=>"Pennsylvania", 
    'RI'=>"Rhode Island", 
    'SC'=>"South Carolina", 
    'SD'=>"South Dakota",
    'TN'=>"Tennessee", 
    'TX'=>"Texas", 
    'UT'=>"Utah", 
    'VT'=>"Vermont", 
    'VA'=>"Virginia", 
    'WA'=>"Washington", 
    'WV'=>"West Virginia", 
    'WI'=>"Wisconsin", 
    'WY'=>"Wyoming"
    );
    
    $canadian_states = array( 
    "BC"=>"British Columbia", 
    "ON"=>"Ontario", 
    "NL"=>"Newfoundland and Labrador", 
    "NS"=>"Nova Scotia", 
    "PE"=>"Prince Edward Island", 
    "NB"=>"New Brunswick", 
    "QC"=>"Quebec", 
    "MB"=>"Manitoba", 
    "SK"=>"Saskatchewan", 
    "AB"=>"Alberta", 
    "NT"=>"Northwest Territories", 
    "NU"=>"Nunavut",
    "YT"=>"Yukon Territory"
    );

  $form = array();
  
  $form['address'] = array(
    '#type' => 'textfield',
    '#title' => t('Street Address'),
    '#size' => 100,
		'#maxlength' => 200,
    '#required' => TRUE,
    '#default_value' => $query_select['street_address'],
  );
  $form['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 50,
		'#maxlength' => 100,
    '#required' => TRUE,
    '#default_value' => $query_select['city'],
  );
  $form['country'] = array(
    '#type' => 'select',
    '#title' => t('Country'),
    '#required' => TRUE,
    '#options' => array(
      'United States' => t('United States'),
      'Canada' => t('Canada'),
      'Israel' => t('Israel'),
      'Other' => t('Other'),
    ),
    '#default_value' => $country,
  );
  $form['country-other'] = array(
    '#type' => 'textfield',
    '#title' => t('Country Name'),
    '#size' => 50,
		'#maxlength' => 100,
    '#default_value' => $country_other,
    '#states' => array(
	    'visible' => array(  // Action to take: Make visible.
	      ':input[name="country"]' => array('value' => t('Other')),
	    ),
	  ),
  );
  $form['state-us'] = array(
    '#type' => 'select',
    '#title' => t('State'),
    '#options' => $us_states,
    '#default_value' => $query_select['state'],
    '#states' => array(
	    'visible' => array(  // Action to take: Make visible.
	      ':input[name="country"]' => array('value' => t('United States')),
	    ),
	  ),
  );
  $form['state-can'] = array(
    '#type' => 'select',
    '#title' => t('State'),
    '#options' => $canadian_states,
    '#default_value' => $query_select['state'],
    '#states' => array(
	    'visible' => array(  // Action to take: Make visible.
	      ':input[name="country"]' => array('value' => t('Canada')),
	    ),
	  ),
  );  
 $form['zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Zip Code'),
    '#size' => 10,
		'#maxlength' => 10,
    '#default_value' => $query_select['zip'],
  );

 $form['mobile-phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Phone Number'),
    '#size' => 15,
		'#maxlength' => 15,
    '#required' => TRUE,		
    '#default_value' => $query_select['mobile_phone'],
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  return $form;
}

function taglit_apply_seca_form_submit($form, &$form_state) {
	global $user;
	  
  if (isset($form_state['values']['state-us'])) {
	  $state = $form_state['values']['state-us'];
  }
  elseif (isset($form_state['values']['state-can'])) {
	  $state = $form_state['values']['state-can'];
  }
  else {
	  $state = NULL;
  }  
  if ($form_state['values']['country'] == 'Other') {
	  $country = $form_state['values']['country-other'];
  }
  else {
	  $country = $form_state['values']['country'];
  }
    
  $query = db_update('taglit_apply')
  	->fields(
  		array(
	    	'street_address' 	=> 	$form_state['values']['address'],
				'city' 	=> $form_state['values']['city'],
				'country' => $country,
				'state' => $state,
				'zip' 	=> $form_state['values']['zip'],
				'mobile_phone' 	=> $form_state['values']['mobile-phone'],
				'seca_complete' => 1
			)
		)
  ->condition('uid', $user->uid, '=')
  ->execute();
  
  $form_state['redirect'] = 'program-application';
}
