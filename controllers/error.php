<?php

// Initialize this controller.
$controller = new ErrorController();


/**
 * Error controller is loaded when no other controller is found.
 */
class ErrorController {

  public $vars = array();

  function __construct() {
    // Send 404 header.
    header("HTTP/1.0 404 Not Found");
  }

}
