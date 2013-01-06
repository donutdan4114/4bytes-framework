<?php

define('DJP_URL', 'http://danieljpepin.com');
define('GITHUB', 'http://donutdan4114.github.com/4bytes-framework/');

// Initialize the controller.
$controller = new IndexController();

/**
 * This code gets run when the path is /
 */
class IndexController {

  public $vars = array();

  public function __construct() {
    // global $db;
    /**
     * You can set vars for layouts and views.
     *   $this->vars['my_var'] = 'my_value';
     *
     * The $db variable provides access to the JSON simple DB.
     *   $db->get('settings', 'SYSTEM.SALT');
     *   $db->set('user', $uid = 4, array(
     *     'fname' = 'Bob',
     *     'lname' = 'Saget',
     *   ));
     */
    $this->vars['directory_size'] = round(disk_total_space('../') / (1024 * 1024 * 1024), 1);
  }

}
