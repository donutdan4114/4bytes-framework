<div class="hero-unit">
  <?=
  HTML::img(LOGO_PATH, array(
    'id' => 'logo',
    'class' => 'pull-right',
    'width' => 220,
  ));
  ?>
  <h1>Page Not Found</h1>

  <p>
    We couldn't find the page you're looking for.<br/>
    Check out <?= HTML::link('our homepage', 'homepage') ?>.
  </p>
</div>
