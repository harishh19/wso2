<?php
/**
 * @file
 * apps.features.inc
 */

/**
 * Implements hook_views_api().
 */
function apps_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function apps_node_info() {
  $items = array(
    'apps' => array(
      'name' => t('Apps'),
      'base' => 'node_content',
      'description' => t('Sealedair Wso2 applications'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
