<html>
  <head>
    <?php print HTML::title(setting('SYSTEM.SITE')); ?>
    <?php print HTML::css('//netdna.bootstrapcdn.com/twitter-bootstrap/2.3.1/css/bootstrap-combined.min.css', 'external'); ?>
    <?php print HTML::css('4bytes'); ?>
  </head>
  <body>
    <?php print $content; ?>
    <?php print HTML::js('//code.jquery.com/jquery-1.8.3.js', 'external'); ?>
    <?php print HTML::js('//netdna.bootstrapcdn.com/twitter-bootstrap/2.3.1/js/bootstrap.min.js', 'external'); ?>
  </body>
</html>
