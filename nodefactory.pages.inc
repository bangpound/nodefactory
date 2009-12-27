<?php

/**
 * @file
 * Page and form callbacks for nodefactory module.
 */

/**
 * Theme the nodefactory import form into a table.
 * @param $element
 *   The nodefactory import form.
 * @return
 *   Rendered HTML for the nodefactory import form.
 * @todo Move this to nodefactory.pages.inc.
 */
function theme_nodefactory_import_form($element) {
  $header = array(theme('table_select_header_cell'), t('Filename'), t('Size'), t('Description'));
  $rows = array();

  foreach (element_children($element['files']) as $key) {
    $rows[] = array(
      drupal_render($element['files'][$key]['import']),
      drupal_render($element['files'][$key]['name']),
      drupal_render($element['files'][$key]['size']),
      drupal_render($element['files'][$key]['description']),
    );
  }

  $output = theme('table', $header, $rows);
  $output .= drupal_render($element);
  return $output;
}


/**
 * Generate an import form for media batch nodes.
 * @return
 *   A media import form.
 * @todo Move this to nodefactory.pages.inc.
 * @todo Add module_load_include call to nodefactory_form_media_batch_node_form_alter().
 */
function nodefactory_import_form() {
  $form = array();

  $dirpath = variable_get('nodefactory_import_path', '');
  if (!file_check_directory($dirpath, FILE_CREATE_DIRECTORY)) {
    drupal_set_message(t("You need to configure the import directory on Node Factory module's <a href='!admin-settings-import'>settings page</a>.", array('!admin-settings-import' => url('admin/settings/nodefactory'))), 'error');
    return $form;
  }

  $form['#dirpath'] = $dirpath;
  $form['#theme'] = 'nodefactory_import_form';


  $rdi = new DirectoryIterator($dirpath);
  $files = array();
  foreach ($rdi as $fileinfo) {
    if ($fileinfo->isDot() || $fileinfo->isDir()) {
      continue;
    }

    $file = new stdClass();
    $file->filename = $fileinfo->getFilename();
    $file->filepath = $fileinfo->getPath() . '/' . $file->filename;
    $file->size = $fileinfo->getSize();
    $files[] = $file;
  }

  $file_metadata_modules = module_implements('file_metadata');

  if ($files) {

    // Put the image files into an array for the checkboxes and gather
    // additional information like dimensions and filesizes. Make sure that
    // there's no 0th element, because a checkbox with a zero value is seen as
    // unchecked and won't be imported.
    $index = 0;
    foreach ($files as $file) {
      $index++;
      $filelist[$index] = substr($file->filename, strlen($dirpath) + 1);


      // Allow other modules to supply metadata about the images being imported.
      // hook_file_metadata() may populate the $file properties 'title' and
      // 'description'.
      foreach ($file_metadata_modules as $module) {
        $function = $module . '_file_metadata';
        $function($file);
      }

      // Spit out the import form elements.
      $form['files'][$index]['import'] = array(
        '#type' => 'checkbox',
      );

      $form['files'][$index]['name'] = array(
        '#type' => 'item',
        '#value' => check_plain($file->filename),
      );


      $form['files'][$index]['size'] = array(
        '#type' => 'item',
        '#value' => format_size($file->size),
      );

      $form['files'][$index]['description'] = array(
        '#type' => 'textfield',
        '#size' => 20,
        '#default_value' => '',
      );


     // Form values used for moving the file and placing it in the files table
     $form['files'][$index]['filesize'] = array(
        '#type' => 'value',
        '#value' => $file->size,
      );

      $form['files'][$index]['filename'] = array(
        '#type' => 'value',
        '#value' => $file->filename,
      );

      $form['files'][$index]['filepath'] = array(
        '#type' => 'value',
        '#value' => $file->filepath,
      );


      // If there were problems don't let them import it
      if (count($problems)) {
        $form['files']['import'][$index]['#type'] = 'item';
        $form['files']['errors'][$index] = array(
          '#type' => 'markup',
          '#value' => '<em>'. implode(' ', $problems) .'</em>',
        );
        unset($form['files']['title'][$index]);
        unset($form['files']['body'][$index]);
      }
    }

    $form['pager'] = array('#value' => theme('pager', NULL, $page_size, 0));

    $form['files']['#tree'] = TRUE;


    // Store a copy of the list into a form value so we can compare it to what
    // they submit and not have to worry about files being added or removed
    // from the filesystem.
    $form['file_list'] = array(
      '#type' => 'value',
      '#value' => $filelist,
    );

  }
  else {
    $form['none_found'] = array(
      '#type' => 'item',
      '#value' => '<em>' . t('No files were found.') . '</em>',
    );
  }

  return $form;
}
