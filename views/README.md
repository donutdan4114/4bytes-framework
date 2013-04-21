## Views
**Views are portions of HTML, typically larger than blocks, and are not usually considered reusable.**

You can easily get a view's HTML with `view('about')`.

You can pass arguments to views, and they will be available in the view as variables.
```
print view('about', array(
  'the cake' => false,
));
```