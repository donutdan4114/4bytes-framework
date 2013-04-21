<?php

/**
 * Error controller is loaded when no other controller is found.
 */
class ErrorController {

  public $vars = array();

  function view() {
    header("HTTP/1.0 404 Not Found");
    return layout('main', array(
        'content' => view('error'),
        'title' => "Page Not Found")
    );
  }

}
