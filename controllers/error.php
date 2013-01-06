<?php

/**
 * Error controller is loaded when no other controller is found.
 */
class ErrorController {

  public $vars = array();

  function view() {
    // Send 404 header.
    header("HTTP/1.0 404 Not Found");
    return layout('error');
  }

}
