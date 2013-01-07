<?php

/**
 * Useful session class.
 */
class Session {

  /**
   * Set a session variable.
   *
   * @param $name
   * @param $val
   */
  function set($name, $val) {
    if (!isset($_SESSION)) {
      session_start();
      $_SESSION[$name] = $val;
    }
  }

  /**
   * Get a session variable.
   *
   * @param $var
   *
   * @return string
   */
  function get($var) {
    session_start();
    return $_SESSION[$var];
  }

}
