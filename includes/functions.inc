<?php

/**
 * Returns the path of the controller file.
 */
function controller($path) {
  $path = '../controllers/' . $path . '.php';
  if (file_exists($path)) {
    return $path;
  }
  else {
    return '../controllers/error.php';
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
  // Let views and layouts get controller vars.
  extract($controller->vars);
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
  return empty($url) ? 'index' : $url;
}

/**
 * Gets the URL arg.
 */
function arg($num) {
  $args = explode('/', $_GET['q']);
  return $args[$num];
}
