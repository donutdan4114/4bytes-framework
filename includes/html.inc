<?php

/**
 * Helper class that has useful functions for printing HTML.
 */
class HTML {

  public static function title($html, $options = array()) {
    return '<title ' . self::getOptionsHtml($options) . '>' . $html . '</title>';
  }

  public static function comment($str) {
    return "<!-- " . $str . " -->";
  }

  public static function doctype($type = 'html', $options = array()) {
    return "<!DOCTYPE $type " . self::getOptionsHtml($options) . ">";
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

  public static function hr() {
    return "<hr />";
  }

  public static function p($html, $options = array()) {
    return self::tag('p', $html, $options);
  }

  public static function br($count = 1) {
    return str_repeat("<br />", $count);
  }

  public static function img($src, $options = array()) {
    return '<img src="' . $src . '" ' . self::getOptionsHtml($options) . ' />';
  }

  public static function link($html, $options = array()) {
    return self::tag('a', $html, $options);
  }

  public static function code($html, $options = array()) {
    return self::tag('code', $html, $options);
  }

  public static function iframe($html, $options = array()) {
    return self::tag('iframe', $html, $options);
  }

  public static function quote($html, $options = array()) {
    return self::tag('blockquote', $html, $options);
  }

  public static function aside($html, $options = array()) {
    return self::tag('aside', $html, $options);
  }

  public static function span($html, $options = array()) {
    return self::tag('span', $html, $options);
  }

  public static function div($html, $options = array()) {
    return self::tag('div', $html, $options);
  }

  public static function article($html, $options = array()) {
    return self::tag('article', $html, $options);
  }

  public static function section($html, $options = array()) {
    return self::tag('section', $html, $options);
  }

  public static function footer($html, $options = array()) {
    return self::tag('footer', $html, $options);
  }

  public static function header($html, $options = array()) {
    return self::tag('header', $html, $options);
  }

  public static function h1($html, $options = array()) {
    return self::tag('h1', $html, $options);
  }

  public static function h2($html, $options = array()) {
    return self::tag('h2', $html, $options);
  }

  public static function h3($html, $options = array()) {
    return self::tag('h3', $html, $options);
  }

  public static function h4($html, $options = array()) {
    return self::tag('h4', $html, $options);
  }

  public static function h5($html, $options = array()) {
    return self::tag('h5', $html, $options);
  }

  public static function h6($html, $options = array()) {
    return self::tag('h6', $html, $options);
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
