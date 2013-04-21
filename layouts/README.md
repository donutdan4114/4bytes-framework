## Layouts
**These HTML files should be the main wrapper for your views. Layouts should contain the `<head>` and `<body>` tags.**

Typically, your controller will return layouts.
`return layout('main')`

You can pass arguments to the `layout` function.

```
return layout('main', array(
  'content' => view('about'),
));
```