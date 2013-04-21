<?php
/**
 * This code gets run when the path is /contact
 */
class ContactController {

  public function __construct() {
    // Put code in here you want to run every time this controller is hit.
  }

  /**
   * This function gets hit at /contact/view
   * @return string
   */
  public function view() {
    // Display contact view.
    return layout('index', array('content' => view('contact')));
  }

}
