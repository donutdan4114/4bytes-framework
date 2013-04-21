<html>
<head>
  <?= HTML::title($title) ?>
  <?= HTML::css('//netdna.bootstrapcdn.com/twitter-bootstrap/2.3.1/css/bootstrap-combined.min.css', 'external') ?>
  <?= HTML::css('4bytes') ?>
</head>
<body>
<?= block('nav') ?>
<div class="container">
  <?= $content; ?>
</div>
<hr/>
<?= block('footer') ?>
<?= HTML::js('//code.jquery.com/jquery-1.8.3.js', 'external') ?>
<?= HTML::js('//netdna.bootstrapcdn.com/twitter-bootstrap/2.3.1/js/bootstrap.min.js', 'external') ?>
</body>
</html>
