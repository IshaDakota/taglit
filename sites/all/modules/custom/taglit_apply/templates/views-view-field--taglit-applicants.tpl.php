<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php 

switch($field->field_alias) {

  case 'taglit_apply_israel_birthright':
    
    switch($row->taglit_apply_israel_birthright) {
      case 0:
        print('No');
        break;
      case 1:
        print('Yes');
        break;
    }
    break;
    
  case 'taglit_apply_israel_birthright_staff':
    
    switch($row->taglit_apply_israel_birthright_staff) {
      case 2:
        print('No');
        break;
      case 1:
        print('Yes');
        break;
    }
    break;    

  case 'taglit_apply_jewish_background':
    
    switch($row->taglit_apply_jewish_background) {
      case 0:
        print('Just Jewish');
        break;
      case 1:
        print('Conservative');
        break;
      case 2:
        print('Orthodox');
        break;
      case 3:
        print('Reform');
        break;
      case 4:
        print('Reformative');
        break;
      case 5:
        print('Secular Humanist');
        break;
      case 6:
        print('Reconstructionist');
        break;
      case '7':
        print('Traditional');
        break;        
      case 8:
        print('Not Jewish');
        break;
      case 9:
        print('Other');
        break;
      case 10:
        print('Another Religion');
        break;  
    }
    break;

  case 'taglit_apply_jewish_youthgroup':
    
    switch($row->taglit_apply_jewish_youthgroup) {
      case 0:
        print('No');
        break;
      case 1:
        print('Yes');
        break;
    }
    break;

  case 'taglit_apply_prof_status':
    
    switch($row->taglit_apply_prof_status) {
      case 1:
        print('Student');
        break;
      case 2:
        print('Grad/Prof');
        break;
      case 3:
        print('Both');
        break;
    }
    break; 

  case 'taglit_apply_ed_status':
    
    switch($row->taglit_apply_ed_status) {
      case 1:
        print('Some undergraduate work completed');
        break;
      case 2:
        print('Undergraduate degree completed');
        break;
      case 3:
        print('Some graduate work completed');
        break;
      case 4:
        print('Graduate degree completed');
        break;
    }
    break; 

  default:
    print $output;
    break;
}
