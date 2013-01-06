<?php

define('DJP_URL', 'http://danieljpepin.com');
define('GITHUB', 'http://donutdan4114.github.com/4bytes-framework/');

/**
 * This code gets run when the path is /index/
 */
class IndexController {

  private $vars = array();

  public function __construct() {
    $this->vars = array(
      'size' => round(disk_total_space('../') / (1024 * 1024 * 1024), 1)
    );
  }

  public function view() {
    return layout('index', $this->vars);
  }

}
