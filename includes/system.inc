<?php
/**
 * @file system.inc
 *
 * This file has all of the functions that 4bytes requires.
 *
 */

/**
 * Returns the path of the controller file.
 */
function include_controller($path) {
  // Need to check routes with this path.
  $route = getRoute($path);
  if ($route) {
    $controller = $route['controller'];
    $method = $route['method'];
    $args = $route['args'];
  }
  else {
    $controller = arg(0);
    $method = arg(1);
    $args = args();
  }
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
  // If all else fails...
  return error_controller();
}

/**
 * Gets the error controller HTML.
 * @return string Error page HTML.
 */
function error_controller() {
  include '../controllers/error.php';
  $class = 'ErrorController';
  $controller = new $class();
  return $controller->view();
}

/**
 * Renders a view.
 */
function view($view, $args = array()) {
  return html('view', $view, $args);
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
  // Load global controller file.
  global $controller;
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
 * Gets URL path.
 */
function path() {
  // Filter out numbers.
  $url = $_GET['q'];
  $args = explode('/', $_GET['q']);
  foreach ($args as $arg) {
    if (is_numeric($arg)) {
      $url = str_replace('/' . $arg, NULL, $url);
    }
  }
  return $url;
}

/**
 * Adds a route to the system.
 *
 * @param $path
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
      if (preg_match($key, $path)) {
        return $routes[$key];
      }
    }

    return NULL;
  }
}

/**
 * Gets the URL arg.
 */
function arg($num) {
  $args = explode('/', $_GET['q']);
  if (isset($args[$num])) {
    return $args[$num];
  }
  else {
    return NULL;
  }
}

/**
 * Returns args. Does not include controller and method information.
 */
function args() {
  $args = explode('/', $_GET['q']);
  $count = count($args);
  $start = 2;
  $return = array();
  for ($i = $start; $i < $count; $i++) {
    $return[] = $args[$i];
  }
  return $return;
}
