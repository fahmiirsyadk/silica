module S = Silica.HTML;

// -- DATA
let animals = ["macan","hiu","kura-kura","panda"];
let bodyStyle = {|style="margin: 0; padding: 0; box-sizing: border-box;"|};
let articleStyle = {|style="background: pink; color: white;"|};

// -- LOGIC
let listAnimal = animals |> List.map(animal => S.li("", S.text(animal)))
let oper = 2 + 4;
let day =
  switch (Js.Date.make()->Js.Date.getDay) {
  | 1.0 => "Senin"
  | 2.0 => "Selasa"
  | 3.0 => "Rabu"
  | 4.0 => "Kamis"
  | 5.0 => "Jumat"
  | 6.0 => "Sabtu"
  | 7.0 => "Minggu"
  | _ => "Error date"
  };

// -- HEAD
let head = S.head("", [
			S.title("", S.text("Aerogel SSG"))
		]);

// -- BODY
let body = S.body( bodyStyle, [
			S.h1("", S.text("THIS IS THE AEROGEL SSG")),
			S.h2("", S.text({j|Selamat hari $day|j})),
			S.article( articleStyle, [
				"note: this is allowed", // passing raw string
				listAnimal |> S.ol({|style="padding: 20px 0;"|})
			])
		]);

// -- Footer
let footer = S.footer("", [
			S.p("", S.text({js|Made with ❤️|js}))
		]);

// -- MAIN
let main = [head, body, footer] |> S.html("");

Node_fs.writeFileSync("result.html", main, `utf8);