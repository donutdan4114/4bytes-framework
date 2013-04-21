<?php
/**
 * @file system.inc
 *
 * This file has all of the functions that 4bytes requires.
 *
 */

/**
 * Trims all whitespace characters, even unicode.
 *
 * @param string $str
 *   String to strip whitespace from.
 *
 * @return string
 *   Returns the trimmed string.
 */
function utrim($str) {
  return preg_replace('/^[\pZ\pC]+|[\pZ\pC]+$/u', '', $str);
}

/**
 * Returns the path of the controller file.
 */
function include_controller($path) {
  // Need to check routes with this path.
  $route = getRoute($path);
  if ($route) {
    $controller = $route['controller'];
    $method = $route['method'];
  }
  else {
    $controller = arg(0);
    $method = arg(1);
  }
  $args = args($controller, $method);
  if ($html = controller($controller, $method, $args)) {
    return $html;
  }
  // If all else fails...
  return controller("error", "view", $args);
}

/**
 * Returns a controller's HTML.
 *
 * @param $controller
 * @param $method
 * @param $args
 *
 * @return bool|mixed
 */
function controller($controller, $method, $args) {
  $path = '../controllers/' . $controller . '.php';
  if (file_exists($path)) {
    include $path;
    $class = ucfirst($controller) . 'Controller';
    $controller = new $class(arg(2));
    $method = empty($method) ? "view" : $method;
    if (is_callable(array($controller, $method))) {
      return call_user_func_array(array($controller, $method), $args);
    }
  }
  return FALSE;
}

function GET($key) {
  return $_GET[$key];
}

function POST($key) {
  return $_POST[$key];
}

function REQUEST($key) {
  return $_REQUEST[$key];
}

/**
 * Encrypt a string.
 *
 * @param $str
 * @param null $seed
 *
 * @return string
 */
function encrypt($str, $seed = NULL) {
  if (empty($seed)) {
    $seed = setting('SYSTEM.ENCRYPT_KEY');
  }
  $block = mcrypt_get_block_size('des', 'ecb');
  $pad = $block - (strlen($str) % $block);
  $str .= str_repeat(chr($pad), $pad);
  return base64_encode(mcrypt_encrypt(MCRYPT_RIJNDAEL_256, $seed, utrim($str), MCRYPT_MODE_ECB));
}

/**
 * Decrypt a string.
 *
 * @param $str
 * @param null $seed
 *
 * @return string
 */
function decrypt($str, $seed = NULL) {
  if (empty($seed)) {
    $seed = setting('SYSTEM.ENCRYPT_KEY');
  }
  $str = mcrypt_decrypt(MCRYPT_RIJNDAEL_256, $seed, base64_decode($str), MCRYPT_MODE_ECB);
  $block = mcrypt_get_block_size('des', 'ecb');
  $pad = ord($str[($len = strlen($str)) - 1]);
  return utrim(substr($str, 0, strlen($str) - $pad));
}

/**
 * Renders a view.
 */
function view($view, $args = array()) {
  return html('view', $view, $args);
}

/**
 * Renders a block.
 */
function block($block, $args = array()) {
  return html('block', $block, $args);
}

/**
 * Renders a layout.
 */
function layout($layout, $args = array()) {
  return html('layout', $layout, $args);
}

/**
 * Utility function for printing HTML.
 */
function html($type, $file, $args) {
  $type = $type . 's';
  if (file_exists('../' . $type . '/' . $file . '.php')) {
    $path = '../' . $type . '/' . $file . '.php';
  }
  elseif (file_exists('../' . $type . '/' . $file . '.php')) {
    $path = '../' . $type . '/' . $file . '/index.php';
  }
  else {
    $path = '../' . $type . '/error.php';
  }
  ob_start();
  extract($args);
  require $path;
  $html = ob_get_contents();
  ob_end_clean();
  return $html;
}

/**
 * Gets the request_uri from the server.
 * @return string
 */
function request_uri() {
  $path = substr($_SERVER['REQUEST_URI'], 1);
  if (!$path) {
    $path = '';
  }
  return $path;
}

/**
 * Gets URL path.
 * Basically just an alias for request_uri().
 */
function path() {
  return request_uri();
}

/**
 * Adds a route to the system.
 *
 * @param $name Name of the URL. This is the name you can use to easily create
 *   links.
 * @param $paths Array of paths that match the route.
 * @param $info Array of information. Controller and method should be passed.
 */
function addRoute($paths, $info) {
  global $routes;
  foreach ($paths as $path) {
    $routes[$path] = $info;
  }
}

/**
 * Add a setting to the global namespace.
 *
 * @param $var
 * @param $val
 */
function addSetting($var, $val) {
  global $settings;
  $settings[$var] = $val;
}

/**
 * Get a setting from the global namespace.
 * Essentially this is just an alias for $settings.
 *
 * @param $var
 *
 * @return mixed
 */
function setting($var) {
  global $settings;
  return $settings[$var];
}

function getRoute($path) {
  global $routes;
  if (isset($routes[$path])) {
    return $routes[$path];
  }
  else {
    // Check to see if there is a regex match.
    foreach ($routes as $key => $r) {
      if ($r['regex'] === TRUE) {
        if (preg_match($key, $path)) {
          return $routes[$key];
        }
      }
    }

    return NULL;
  }
}

/**
 * Gets the URL arg.
 */
function arg($num) {
  $args = explode('/', request_uri());
  if (isset($args[$num])) {
    return $args[$num];
  }
  else {
    return NULL;
  }
}

/**
 * Returns args by filtering out the controller/method information.
 */
function args($controller, $method) {
  $args = explode('/', request_uri());
  $count = count($args);
  for ($i = 0; $i < $count; $i++) {
    if ($args[$i] == $controller || $args[$i] == $method) {
      unset($args[$i]);
    }
  }
  return $args;
}
