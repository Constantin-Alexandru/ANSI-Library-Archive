import {
  Effects,
  Clear,
  gotoXY,
  SetEffect,
  goDownN,
  goLeftN,
  SetColor,
  Colors,
  SetText256Color,
  SetBackground256Color,
  SetRGBTextColorObj,
  SetRGBBackgroundColorObj,
  Reset,
  goRightN,
  goUpN,
} from "ansi-lib";

const write = process.stdout.write.bind(process.stdout);

const pause = async () => {
  process.stdin.setRawMode(true);
  return new Promise((resolve) =>
    process.stdin.once("data", () => {
      process.stdin.setRawMode(false);
      resolve();
    }),
  );
};

async function nextScreen() {
  write("Press any key to continue...\n");
  await pause();

  Clear();
  gotoXY(0, 0);
}

Clear();
SetEffect(Effects.BOLD);
write("ANSI LIB SHOWCASE");
SetEffect(Effects.BOLD);
goDownN(3);
goLeftN(50);

write(
  "This project was created to showcase the ANSI LIBRARY and it's features.\n",
);

write("The main feature of this library is the ability to change colors.\n");

goDownN(2);

await nextScreen();

write(
  "You have a predefined set of colors that can be used for both background \
and foreground:\n\n",
);

for (let text_color = 30; text_color < 38; text_color++) {
  SetColor(text_color);
  for (let background_color = 40; background_color < 48; background_color++) {
    SetColor(background_color);
    write(`${text_color}`);
    SetColor(Colors.BKG_DEFAULT);
  }
  write("\n");
  SetColor(Colors.TXT_DEFAULT);
}

await nextScreen();

write(
  "You have the 256-color mode that can be used for both \
background and foreground:\n\n",
);

for (let color = 0; color < 256; color++) {
  if (color % 16 === 0) {
    write("\n");
  }
  SetText256Color(color);
  SetBackground256Color(255 - color);
  write(`${color.toString().padStart(3, " ")}`);
}

write("\n");

Reset();
await nextScreen();

write(
  "Some terminals also support Truecolor values for background \
and foreground:\n\n",
);

for (let iterations = 0; iterations < 10; iterations++) {
  const rgb = {
    r: Math.floor(Math.random() * 256),
    g: Math.floor(Math.random() * 256),
    b: Math.floor(Math.random() * 256),
  };
  const bkg_rgb = { r: 255 - rgb.r, g: 255 - rgb.g, b: 255 - rgb.b };

  SetRGBTextColorObj(rgb);
  SetRGBBackgroundColorObj(bkg_rgb);

  write(
    `${rgb.r.toString().padStart(3, " ")} - \
${rgb.g.toString().padStart(3, " ")} - \
${rgb.b.toString().padStart(3, " ")}\n`,
  );
}

Reset();
await nextScreen();

write("The library also offers effects that can be applie to text:\n\n");

SetEffect(Effects.BOLD);
write("- BOLD\n");
SetEffect(Effects.BOLD_RESET);

SetEffect(Effects.DIM);
write("- DIM\n");
SetEffect(Effects.DIM_RESET);

SetEffect(Effects.ITALIC);
write("- ITALIC\n");
SetEffect(Effects.ITALIC_RESET);

SetEffect(Effects.INVERSE);
write("- INVERSE\n");
SetEffect(Effects.INVERSE_RESET);

SetEffect(Effects.HIDDEN);
write("- HIDDEN");
SetEffect(Effects.HIDDEN_RESET);
write("(HIDDEN)\n");

SetEffect(Effects.UNDERLINE);
write("- UNDERLINE\n");
SetEffect(Effects.UNDERLINE_RESET);

SetEffect(Effects.STRIKETHROUGH);
write("- STRIKETHROUGH\n");
SetEffect(Effects.STRIKETHROUGH_RESET);

SetEffect(Effects.DOUBLE_UNDERLINE);
write("- DOUBLE_UNDERLINE\n");
SetEffect(Effects.DOUBLE_UNDERLINE_RESET);

Reset();
await nextScreen();

write("You can also use the library to travel around with the cursor:\n\n");

write("Press any key to travel around\n");

await pause();

goDownN(5);

await pause();

goRightN(5);

await pause();

goUpN(5);

await pause();

goLeftN(5);

await pause();

await nextScreen();

Reset();
process.exit();
