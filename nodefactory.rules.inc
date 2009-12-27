<?php

/**
 * @file
 * Node Factory rules support.
 */

/**
 * Implementation of hook_rules_action_info()
 */
function nodefactory_rules_action_info() {
  return array(
    'rules_action_file_set_author' => array(
      'label' => t('Set the file author'),
      'arguments' => array(
        'file' => array('type' => 'file', 'label' => t('File')),
        'author' => array('type' => 'user', 'label' => t('User, who is set as author')),
      ),
      'module' => 'nodefactory',
    ),
    'rules_action_file_load_author' => array(
      'label' => t('Load the file author'),
      'arguments' => array(
        'file' => array('type' => 'file', 'label' => t('File')),
      ),
      'new variables' => array(
        'author' => array(
          'type' => 'user',
          'label' => t('File author'),
          'label callback' => 'rules_action_file_load_author_variable_label',
        ),
      ),
      'module' => 'nodefactory',
    ),
    'rules_action_load_file' => array(
      'label' => t('Load file by id'),
      'arguments' => array(
        'fid' => array('type' => 'number', 'label' => t('File ID')),
      ),
      'new variables' => array(
        'file_loaded' => array(
          'type' => 'file',
          'label' => t('Loaded file'),
          'label callback' => 'rules_action_load_file_variable_label',
        ),
      ),
      'module' => 'nodefactory',
    ),
  );
}

/**
 * Implementation of hook_rules_condition_info()
 */
function nodefactory_rules_condition_info() {
  $items = array();
  $items['rules_condition_file_is_type'] = array(
    'arguments' => array(
      'file' => array('type' => 'file', 'label' => t('File')),
    ),
    'module' => 'System',
    'label' => t('File has type'),
    'help' => t('Evaluates to TRUE, if the given file has one of the selected file types.'),
  );
  return $items;
}

/**
 * Implementation of hook_rules_data_type_info()
 */
function nodefactory_rules_data_type_info() {
  return array(
    'file' => array(
      'label' => t('File'),
      'class' => 'rules_data_type_file',
      'savable' => TRUE,
      'identifiable' => TRUE,
    ),
  );
}

/**
 * Defines the file type
 */
class rules_data_type_file extends rules_data_type {
  function save() {
    $file = &$this->get();
    drupal_write_record('files', $file, array('fid'));
    return TRUE;
  }

  function load($fid) {
    return db_fetch_object(db_query('SELECT fid,uid,filename,filepath,filemime,filesize,status,timestamp FROM {files} WHERE fid = %d', $fid));
  }

  function get_identifier() {
    $file = &$this->get();
    return $file->fid;
  }
}

/**
 * Condition: Check for selected file types
 */
function rules_condition_file_is_type(&$file, $settings) {
  static $regexps;

  if (!isset($regexps[$settings['filemime']])) {
    $regexps[$settings['filemime']] = '/^('. preg_replace(array('/(\r\n?|\n)/', '/\\\\\*/'), array('|', '.*'), preg_quote($settings['filemime'], '/')) .')$/';
  }
  return (preg_match($regexps[$settings['filemime']], $file->filemime) > 0) ? TRUE : FALSE;
}

/**
 * Modifies a file as configured
 */
function rules_action_file_set_author($file, $author) {
  $file->uid = $author->uid;
  return array('file' => $file);
}

/**
 * Loads the file author
 */
function rules_action_file_load_author($file) {
  return array('author' => user_load($file->uid));
}

/**
 * Loads a file
 */
function rules_action_load_file($fid) {
  return array('file_loaded' => db_fetch_object(db_query('SELECT fid,uid,filename,filepath,filemime,filesize,status,timestamp FROM {files} WHERE fid = %d', $fid)));
}
