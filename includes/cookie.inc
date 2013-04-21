<?php
/**
 * Useful cookie class.
 */
class Cookie {

  /**
   * Sets a cookie.
   *
   * Will use encryption and secure methods if they are set.
   * @file settings.php
   *
   * @param string $name
   *   Name of the cookie.
   * @param string $val
   *   Value to set in the cookie.
   * @param int $expire
   *   Expiration time.
   * @param array $args
   *   Misc arguments to pass to setcookie function.
   *
   * @return bool
   *   Returns TRUE if the cookie has been sent to the user.
   *
   * @see setcookie
   */
  function set($name, $val, $expire = 0, $args = array()) {
    if (setting('COOKIE.ENCRYPT')) {
      $val = encrypt($val);
    }
    if (setting('COOKIE.SECURE')) {
      $val .= setting('COOKIE.SEPARATOR') . self::hash($val) . 'timestamp:' . REQUEST_TIME;
    }
    return setcookie($name, $val, $expire, $args['path'], $args['domain'], $args['secure'], $args['httponly']);
  }

  /**
   * Gets a cookie and validates it.
   *
   * @param $name
   *   Name of the cookie to get.
   *
   * @return mixed
   *   Will return the cookie value if it is valid.
   */
  function get($name) {
    $val = $_COOKIE[$name];
    if (setting('COOKIE.SECURE')) {
      if (!self::is_secure($val)) {
        return FALSE;
      }
      preg_match("/^(.*)" . setting('COOKIE.SEPARATOR') . "/", $val, $values);
      $val = $values[1];
    }
    if (setting('COOKIE.ENCRYPT')) {
      $val = decrypt($val);
    }
    return $val;
  }

  /**
   * Determines whether or not a cookie has been altered.
   *
   * @param string $val
   *   Cookie value to check if it is secure.
   *
   * @return bool
   *   Returns TRUE if the cookie value is secure.
   */
  function is_secure($val) {
    // Gets the actual value from the secure cookie.
    $sep = setting('COOKIE.SEPARATOR');
    preg_match("/^(.*){$sep}/", $val, $values);
    preg_match("/timestamp:(.+)$/", $val, $times);
    preg_match("/{$sep}(.+)timestamp:/", $val, $hashes);
    if (!(empty($values[1]) || empty($times[1]) || empty($hashes[1]))) {
      // So far, we have a match for everything, time to check the magic.
      $compare_hash = self::hash($values[1], $times[1]);
      if ($compare_hash === $hashes[1]) {
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Creates a secure hash for validating cookies.
   *
   * @param string $val
   *   String to hash.
   *
   * @param int $time
   *   Timestamp of when the cookie was created.
   *
   * @return string
   */
  function hash($val, $time = REQUEST_TIME) {
    return hash('md2', $val . setting('SYSTEM.SALT') . $time);
  }

}
