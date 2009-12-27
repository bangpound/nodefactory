<?php

/**
 * @file
 * Administrative settings for nodefactory.module.
 */

/**
 * Settings form.
 *
 * @return
 *   A system settings form.
 */
function nodefactory_settings() {
  file_check_directory(variable_get('nodefactory_import_path', file_directory_temp() . '/nodefactory'), FILE_CREATE_DIRECTORY);
  $form['nodefactory_import_path'] = array(
   '#type' => 'textfield',
   '#title' => t('Import Path'),
   '#description' => t("The directory to import media files from. Drupal will need to have write access to this directory so that files can be moved.") .'<br />'
      . t("<strong>Note:</strong> a path begining with a <kbd>/</kbd> indicates the path is relative to the server's root, one starting without specifies a path relative to Drupal's root. I.e. <kbd>/tmp/image</kbd> would be the temp directory off the root while <kbd>tmp/image</kbd> would be inside Drupal's directory."),
   '#default_value' => variable_get('nodefactory_import_path', file_directory_temp() . '/nodefactory'),
   '#required' => TRUE,
  );

  return system_settings_form($form);
}
