<?php
/**
 * @file
 * apis_doc.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function apis_doc_user_default_roles() {
  $roles = array();

  // Exported role: Consumer.
  $roles['Consumer'] = array(
    'name' => 'Consumer',
    'weight' => 3,
  );

  // Exported role: Provider.
  $roles['Provider'] = array(
    'name' => 'Provider',
    'weight' => 4,
  );

  return $roles;
}
