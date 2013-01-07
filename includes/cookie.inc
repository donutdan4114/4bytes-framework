<?php
/**
 * Useful cookie class.
 */
class Cookie {

  /**
   * Set a cookie.
   *
   * @param $name
   * @param $val
   * @param $expire
   */
  function set($name, $val, $expire = FALSE) {
    if (setting('COOKIE.ENCRYPT')) {
      $val = encrypt($val);
    }
    setcookie($name, $val, $expire, '/');
  }

  /**
   * Get a cookie.
   *
   * @param $var
   *
   * @return string
   */
  function get($var) {
    $val = $_COOKIE[$var];
    if (setting('COOKIE.ENCRYPT')) {
      $val = decrypt($val);
    }
    return $val;
  }

}
