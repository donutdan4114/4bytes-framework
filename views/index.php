<div class="hero-unit">
  <?=
  HTML::img(LOGO_PATH, array(
    'id' => 'logo',
    'class' => 'pull-right',
    'width' => 220,
  ));
  ?>
  <h1>Hello, world!</h1>

  <p>The 4bytes Framework comes with Twitter bootstrap and jQuery.<br/>Check out the
    <a href="http://twitter.github.com/bootstrap/getting-started.html#examples" target="_blank">bootstrap documentation</a>.
  </p>

  <p>
    Also, <?= HTML::link('check out a sub-page', 'contact') ?>, and see how easy it is to code with 4bytes.
  </p>
</div>
