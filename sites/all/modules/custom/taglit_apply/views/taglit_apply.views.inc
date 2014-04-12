<?php

/**
 * @file
 * Views integration for the Taglit Application custom module
 */

/**
 * Implements hook_views_data()
 *
 */
function taglit_apply_views_data() {
  $data = array(
    'taglit_apply' => array(  // Taglit Apply Custom table
      'table' => array(
        'group' => 'Taglit Fellows',      // Groupname Taglit Fellows
        'base' => array(
          'field' => 'taglit_apply_id',  //Primary key
          'title' => 'Taglit Apply Table',
          'help' => 'Data from the custom Taglit Fellows Application Module'
        ),
        'join' => array (
          'users' => array(
            'left_field' => 'uid',
            'field' => 'uid',
          ),
        ),
      ),
     
       //Description of taglit_apply_id
      'taglit_apply_id' => array(  
        'title' => t('Application ID'),
        'help' => t('Unique ID in the Taglit_apply table'),
        'field' => array(
          'click sortable' => TRUE,  
        ),
        //Filter handler for filtering records by mydons_custom_id     
        'filter' => array(
          'handler' => 'views_handler_filter_numeric'   
        ),  
        'sort' => array(
          'handler' => 'views_handler_sort'       
        )
      ),
      
      //Description of taglit_apply_uid field
      'uid' => array(      
        'title' => t('Userid'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
        'relationship' => array(
          'base' => 'users', // The name of the table to join with.
          'base field' => 'uid', // The name of the field on the joined table.field' => uid,
          'handler' => 'views_handler_relationship',
          'label' => t('The User which has completed the application'),
          'title' => t('User'),
          'help' => t('More information on this relationship'),
        ),           
      ),
      
      //Description of taglit_apply_referred field
      'referred' => array(           
        'title' => t('Referred by'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),

      //Description of Street Address field
      'street_address' => array(           
        'title' => t('Address'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),

      //Description of City field
      'city' => array(           
        'title' => t('City'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),

      //Description of State field
      'state' => array(           
        'title' => t('State'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),

      //Description of Country field
      'country' => array(           
        'title' => t('Country'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),

      //Description of ZIP field
      'zip' => array(           
        'title' => t('Zip'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
 
      //Description of Mobile Phone field
      'mobile_phone' => array(           
        'title' => t('Phone'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),      

      //Description of Languages field
      'languages' => array(           
        'title' => t('Languages'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
 
      //Description of Other Skills field
      'other_skills' => array(           
        'title' => t('Other Skills'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of Jewish Elementary field
      'jewish_elementary' => array(           
        'title' => t('Jewish Elementary'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of Jewish High School field
      'jewish_highschool' => array(           
        'title' => t('Jewish High School'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of Languages field
      'languages' => array(           
        'title' => t('Languages'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of Jewish Supplementary field
      'jewish_supplementary' => array(           
        'title' => t('Jewish Supplementary'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      
      //Description of Jewish Camp field
      'jewish_camp' => array(           
        'title' => t('Jewish Camp'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      
      //Description of Camp Name field
      'jewish_camp_name' => array(           
        'title' => t('Camp Name'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of Jewish Youth Group field
      'jewish_youthgroup' => array(           
        'title' => t('Jewish Youth Group'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),

      //Description of Youth Group Name field
      'jewish_youthgroup_name' => array(           
        'title' => t('Youth Group Name'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of Jewish Background field
      'jewish_background' => array(           
        'title' => t('Jewish Background'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of BRI Alum field
      'israel_birthright' => array(           
        'title' => t('BRI Alum'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of BRI TO field
      'israel_birthright_provider' => array(           
        'title' => t('BRI TO'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of BRI Staff field
      'israel_birthright_staff' => array(           
        'title' => t('BRI Staff'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),

      //Description of BRI Staff Num Times field
      'israel_birthright_staff_num' => array(           
        'title' => t('BRI Staff Num Times'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of BRI Staff TO field
      'israel_birthright_staff_provider' => array(           
        'title' => t('BRI Staff TO'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of Professional Status field
      'prof_status' => array(           
        'title' => t('Professional Status'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),

      //Description of Educational Status field
      'ed_status' => array(           
        'title' => t('Educational Status'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of School field
      'ed_school_name' => array(           
        'title' => t('School'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of Employer field
      'prof_employer' => array(           
        'title' => t('Employer'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),
      
      //Description of Position field
      'prof_position' => array(           
        'title' => t('Position'),
        'field' => array(
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string'
        ),
        'sort' => array(
          'handler' => 'views_handler_sort'
        ),
      ),

    ),
  );
  
  return $data;
}

function taglit_apply_views_data_alter() {
  // This example adds a relationship to table {foo}, so that 'foo' views can
  // add this table using a relationship. Because we don't want to write over
  // the primary key field definition for the {foo}.fid field, we use a dummy
  // field name as the key.
  $data['taglit_apply']['dummy_name'] = array(
    'title' => t('User That filled out the app'),
    'help' => t('Example help'),
    'relationship' => array(
      'base' => 'users', // Table we're joining to.
      'base field' => 'uid', // Field on the joined table.
      'field' => 'uid', // Real field name on the 'foo' table.
      'handler' => 'views_handler_relationship',
      'label' => t('Alter Label'),
      'title' => t('Title seen when adding relationship'),
      'help' => t('More information about relationship.'),
    ),
  );
}