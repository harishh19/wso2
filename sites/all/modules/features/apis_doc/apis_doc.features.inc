<?php
/**
 * @file
 * apis_doc.features.inc
 */

/**
 * Implements hook_views_api().
 */
function apis_doc_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function apis_doc_image_default_styles() {
  $styles = array();

  // Exported image style: api_image.
  $styles['api_image'] = array(
    'label' => 'Api image',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 225,
          'height' => 105,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function apis_doc_node_info() {
  $items = array(
    'apis_doc' => array(
      'name' => t('APIs Doc'),
      'base' => 'node_content',
      'description' => t('APIs Docs Description'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
