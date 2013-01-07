<?php

/**
 * Useful session class.
 */
class Session {

  /**
   * Set a cookie.
   *
   * @param $name
   * @param $val
   * @param $expire
   */
  function set($name, $val) {
    if (!isset($_SESSION)) {
      session_start();
      $_SESSION[$name] = $val;
    }
  }

  /**
   * Get a cookie.
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
