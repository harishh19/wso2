<?php
/**
 * @file
 * Definition of sealedair_wso2_store_handler_custom_field
 */
  
/**
 * Provides a custom views field.
 */
class sealedair_wso2_store_handler_custom_field extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
  
  function query() {
    // do nothing -- to override the parent query.
  }
  
  function render($data) {
    // If the devel module is enabled, you may view all of the
    // data provided by fields previously added in your view.
    // Insert PHP code here, or display greeting.
    $subscription_form = drupal_get_form('wso_api_store_get_api_subscription_form', $data->nid);
    $output = drupal_render($subscription_form);
     return $output;
  }
}
