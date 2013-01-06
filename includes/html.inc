<?php

/**
 * Helper class that has useful functions for printing HTML.
 */
class HTML {

  public static function title($html, $options = array()) {
    return '<title ' . self::getOptionsHtml($options) . '>' . $html . '</title>';
  }

  public static function meta($options = array()) {
    return '<meta ' . self::getOptionsHtml($options) . ' />';
  }

  public static function js($src, $type = 'internal') {
    if ($type == 'internal') {
      return '<script src="/js/' . $src . '.js" type="text/javascript"></script>';
    }
    else {
      return '<script src="' . $src . '" type="text/javascript"></script>';
    }
  }

  public static function css($href) {
    return '<link href="/css/' . $href . '.css" rel="stylesheet" type="text/css" />';
  }

  public static function p($html, $options = array()) {
    return self::tag('p', $html, $options);
  }

  public static function header($html, $options = array()) {
    return self::tag('header', $html, $options);
  }

  public static function h1($html, $options = array()) {
    return self::tag('h1', $html, $options);
  }

  public static function tag($tag, $html, $options) {
    return '<' . $tag . ' ' . self::getOptionsHtml($options) . '>' . $html . '</' . $tag . '>';
  }

  public static function getOptionsHtml($options) {
    $html = "";
    foreach ($options as $name => $o) {
      if (is_array($o)) {
        $subs = "";
        foreach ($o as $sub) {
          $subs .= $sub . ' ';
        }
        $o = $subs;
      }
      $html .= $name . '="' . $o . '" ';
    }
    return $html;
  }

}
