<html>
  <head>
    <?php print HTML::title(setting('SYSTEM.SITE')); ?>
    <?php print HTML::css('bootstrap'); ?>
    <?php print HTML::css('bootstrap-responsive'); ?>
    <?php print HTML::css('4bytes'); ?>
  </head>
  <body>
    <?php print $content; ?>
    <?php print HTML::js('http://code.jquery.com/jquery-1.8.3.js', 'external'); ?>
    <?php print HTML::js('bootstrap'); ?>
  </body>
</html>
