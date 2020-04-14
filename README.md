# Silica
> highly under development ( experimental )

Basically export reasonml file into html string, inspired from purescript-halogen, elm and reaml. Instead populate DOM, just export the html.

## Usage
run the project `yarn start`
execute the file with node `node file.bs.js`


## Example
basic example :
```reason
module S = Silica.HTML;
module P = Silica.Property;

let main = 
  S.div([], [
    S.h1([P.style("color: red;")], S.text("JUDUL TITLE")),
    S.p([], S.text("deskripsi"))
  ]);
```

complex example ( return as html file) :
```reason
module S = Silica.HTML;
module P = Silica.Property;

// DATA
let animals = ["macan", "hiu", "kura-kura", "panda"];

// LOGIC
let listAnimal = animals |> List.map(animal => S.li([], S.text(animal)));

let main =
  S.div([P.style("padding: 20px; background-color: pink;")],
    [
      S.h1([], S.text("FORM JUDUL")),
      S.label([ P.for_("newslatter-email-input")], S.text("Email")),
      S.input(
        [ P.type_("email") // TODO VARIANT
        , P.id("newslatter-email")
        , P.name("email")
        , P.placeholder("you@example.com")
        , P.required(true) ]
        , [])
        , S.ol([], listAnimal)
    ]);

let head = 
  S.head([], [
    S.title([], S.text("judul_browser"))
    , S.meta([ P.charset("utf-8")], [])
    , S.meta([ 
      P.property("og:title")
      , P.content("Silica test")],[])
  ]);

let body = [main] |> S.body([P.style("margin: 0; padding: 0;")]);

[head, body] |> S.html([]) |> Node_fs.writeFileSync("result.html", _, `utf8);
```

## TODO:
- [ ] a11y support
- [ ] single tag 
