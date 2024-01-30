const ansi_lib = require("ansi-lib/ansi_lib");
const process = require("node:process");

ansi_lib.ERASE_ENTIRE_SCREEN();
ansi_lib.MOVE_CURSOR_TO_POSITION(0, 0);

ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.BOLD);
console.log("ANSI LIB SHOWCASE");
ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.BOLD_RESET);
ansi_lib.MOVE_CURSOR_DOWN_BY_N(3);
ansi_lib.MOVE_CURSOR_LEFT_BY_N(50);

console.log(
  "This project was created to showcase the ANSI LIBRARY and its features.\n"
);

console.log(
  "The main feature of this library is the ability to change colors.\n"
);

ansi_lib.MOVE_CURSOR_DOWN_BY_N(2);

console.log(
  "You have 4-bit colors that can be used for both background and foreground: \n\n"
);

for (text_color = 30; text_color < 38; text_color++) {
  ansi_lib.SET_FOUR_BIT_COLOR(text_color);
  for (background_color = 40; background_color < 48; background_color++) {
    ansi_lib.SET_FOUR_BIT_COLOR(background_color);
    process.stdout.write(`${text_color.toString().padStart(4, " ")}`);
    ansi_lib.SET_FOUR_BIT_COLOR(ansi_lib.COLOR_4_BIT.BKG_DEFAULT);
  }
  console.log();
  ansi_lib.SET_FOUR_BIT_COLOR(ansi_lib.COLOR_4_BIT.TXT_DEFAULT);
}

ansi_lib.MOVE_CURSOR_DOWN_BY_N(2);

console.log(
  "You have 8-bit colors that can be used for both background and foreground: \n\n"
);

for (color = 0; color < 256; color++) {
  if (color % 16 == 0) console.log();
  ansi_lib.SET_EIGHT_BIT_TEXT_COLOR(color);
  ansi_lib.SET_EIGHT_BIT_BKG_COLOR(255 - color);
  process.stdout.write(`${color.toString().padStart(4, " ")}`);
}

console.log();

ansi_lib.MOVE_CURSOR_DOWN_BY_N(2);

console.log(
  "Some terminals also support Truecolor values for background and foreground: \n\n"
);

for (iter = 0; iter < 10; iter++) {
  r = Math.floor(Math.random() * 255);
  g = Math.floor(Math.random() * 255);
  b = Math.floor(Math.random() * 255);

  ansi_lib.SET_RGB_TEXT_COLOR(r, g, b);
  ansi_lib.SET_RGB_BKG_COLOR(255 - r, 255 - g, 255 - b);
  process.stdout.write(
    `${r.toString().padStart(3, " ")} - ${g.toString().padStart(3, " ")} - ${b
      .toString()
      .padStart(3, " ")}`
  );
  ansi_lib.RESET_TEXT();
  console.log();
}

ansi_lib.MOVE_CURSOR_DOWN_BY_N(2);

console.log("The library also offers effects that can be applied to text:\n\n");

ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.BOLD);
console.log("- BOLD");
ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.BOLD_RESET);

ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.DIM);
console.log("- DIM");
ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.DIM_RESET);

ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.ITALIC);
console.log("- ITALIC");
ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.ITALIC_RESET);

ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.BLINKING);
console.log("- BLINKING");
ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.BLINKING_RESET);

ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.INVERSE);
console.log("- INVERSE");
ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.INVERSE_RESET);

ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.HIDDEN);
process.stdout.write("- HIDDEN");
ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.HIDDEN_RESET);
console.log("(HIDDEN)");

ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.UNDERLINE);
console.log("- UNDERLINE");
ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.UNDERLINE_RESET);

ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.STRIKETHROUGH);
console.log("- STRIKETHROUGH");
ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.STRIKETHROUGH_RESET);

ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.DOUBLE_UNDERLINE);
console.log("- DOUBLE UNDERLINE");
ansi_lib.SET_EFFECT(ansi_lib.TEXT_EFFECTS.DOUBLE_UNDERLINE_RESET);
