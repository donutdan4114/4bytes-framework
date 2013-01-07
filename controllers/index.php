<?php

/**
 * Constants for pages should be defined in the controller.
 */
define('DJP_URL', 'http://danieljpepin.com');
define('GITHUB', 'http://donutdan4114.github.com/4bytes-framework/');

/**
 * This code gets run when the path is /index/
 */
class IndexController {

  public function __construct() {
    // Put code in here you want to run every time this controller is hit.
  }

  /**
   * This function gets hit at /index/view
   * @return string
   */
  public function view() {
    // Get the size of the framework on the disk.
    $size = round(disk_total_space('../') / (1024 * 1024 * 1024), 1);
    $vars['content'] = view('index', array('size' => $size));
    return layout('index', $vars);
  }

}
