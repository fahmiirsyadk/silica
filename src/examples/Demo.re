module S = Silica.HTML;

// -- DATA
let animals = ["macan","hiu","kura-kura","panda"];
let bodyStyle = {|style="margin: 0; padding: 0; box-sizing: border-box;"|};
let articleStyle = {|style="background: pink; color: white;"|};

// -- LOGIC
let listAnimal = animals |> List.map(animal => S.li("", S.text(animal)))
let oper = 2 + 4;


// HEAD
let head = S.head("", [
			S.title("", S.text("Aerogel SSG"))
		]);

// BODY
let body = S.body( bodyStyle, [
			S.h1("", S.text("THIS IS THE AEROGEL SSG")),
			S.article( articleStyle, [
				"note: this is allowed", // passing raw string
				listAnimal |> S.ol({|style="padding: 20px 0;"|})
			])
		]);

// Footer
let footer = S.footer("", [
			S.p("", S.text("made with " ++ {js|❤️|js}))
		]);

// -- VIEW
let main = [head, body, footer] |> S.html("");

main |> Js.log;