<?php
/**
 * @file
 * Views definitions for 'example'
 */
 
/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function sealedair_wso2_store_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'sealedair_wso2_store'),
    ),
    'handlers' => array(
      // The name of my handler
      'sealedair_wso2_store_handler_custom_field' => array(
        // The name of the handler we are extending.
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
 
/**
 * Implements hook_views_data().
 */
function sealedair_wso2_store_views_data() {
  $data = array();
  // Add Example group
  $data['sealedair_wso2_store']['table']['group'] = t('Sealedair Wso2 store');
  $data['sealedair_wso2_store']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  // Add custom field
  $data['sealedair_wso2_store']['subscription'] = array(
    'title' => t('Subscription'),
    'help' => t('Provides a Subscription form.'),
    'field' => array(
      'handler' => 'sealedair_wso2_store_handler_custom_field',
    ),
  );
  return $data;
}
