<?php

/**
 * @file
 * Forms for nodefactory's rules.
 */

/**
 * Action set file author - Label callback
 */
function rules_action_file_set_author_label($settings, $argument_labels) {
  return t('Set the author of @file to @author', $argument_labels);
}

/**
 * Action load file author - Label callback
 */
function rules_action_file_load_author_label($settings, $argument_labels) {
  return t('Load the @file author', $argument_labels);
}

/**
 * Action load file author label callback
 */
function rules_action_file_load_author_variable_label($settings, $argument_labels) {
  return t('@file author', $argument_labels);
}

/**
 * Action load file - Label callback
 */
function rules_action_load_file_label($settings, $argument_labels) {
  return t('Load file @fid', $argument_labels);
}

/**
 * Action load file author label callback
 */
function rules_action_load_file_variable_label($settings, $argument_labels) {
  return t('Load the @file', $argument_labels);
}

/**
 * Condition: Check for content types - Configuration form
 */
function rules_condition_file_is_type_form($settings, &$form) {
  $form['settings']['filemime'] = array(
    '#type' => 'textarea',
    '#title' => t('MIME types'),
    '#default_value' => $settings['filemime'],
    '#description' =>  t("Enter one MIME type per line. The '*' character is a wildcard. Example MIME types are %image for all images and %pdf for a PDF file.", array('%image' => 'image/*', '%pdf' => 'application/pdf')),
    '#required' => TRUE,
  );
}
