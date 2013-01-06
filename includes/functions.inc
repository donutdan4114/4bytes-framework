<?php

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
    return call_user_func_array(array($controller, $method), $args);

  }
  else {
    include '../controllers/error.php';
    $class = 'ErrorController';
    $controller = new $class();
    return $controller->view();
  }
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

function getRoute($path) {
  global $routes;
  if (isset($routes[$path])) {
    return $routes[$path];
  }
  else {
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
  $return = array();
  for ($i = 2; $i < $count; $i++) {
    $return[] = $args[$i];
  }
  return $return;
}
