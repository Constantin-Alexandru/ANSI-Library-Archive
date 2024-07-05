#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ansi_lib.h"

void nextScreen(void) {
  printf("Press any key to continue...\n");

  getchar();

  ClearScreen(ALL);
  gotoXY(0, 0);
}

int main(int argc, char const *argv[]) {
  setupConsole();
  ClearScreen(ALL);

  SetEffect(BOLD);
  printf("ANSI LIB SHOWCASE");
  SetEffect(BOLD_RESET);
  goDownN(3);
  goLeftN(50);

  printf("This project was created to showcase the ANSI LIBRARY and it's "
         "features.\n");

  printf("The main feature of this library is the ability to change colors.\n");

  goDownN(2);

  nextScreen();

  printf("You have a predefined set of colors that can be used for both "
         "background and "
         "foreground:\n\n");

  for (int text_color = 30; text_color < 38; text_color++) {
    SetColor((Colors)text_color);
    for (int background_color = 40; background_color < 48; background_color++) {
      // if (background_color - text_color == 10) continue;

      SetColor((Colors)background_color);
      printf("  %d", text_color);
      SetColor((Colors)BKG_DEFAULT);
    }
    printf("\n");
    SetColor((Colors)TXT_DEFAULT);
  }

  nextScreen();

  printf("You have the 256-color mode that can be used for both background and "
         "foreground:\n\n");

  for (int color = 0; color < 256; color++) {
    if (color % 16 == 0)
      printf("\n");
    SetText256Color(color);
    SetBackground256Color(255 - color);
    printf("%*d ", 3, color);
  }

  printf("\n");

  nextScreen();

  printf("Some terminals also support Truecolor values for background and "
         "foreground:\n\n");

  srand(time(NULL));

  for (int iter = 0; iter < 10; iter++) {
    uint r = rand() % 256;
    uint g = rand() % 256;
    uint b = rand() % 256;

    SetTextRGBColor(r, g, b);
    SetBackgroundRGBColor(255 - r, 255 - g, 255 - b);
    printf("%*d - %*d - %*d\n", 3, r, 3, g, 3, b);
  }
  Reset();
  nextScreen();

  printf("The library also offers effects that can be applied to text:\n\n");

  SetEffect(BOLD);
  printf("- BOLD\n");
  SetEffect(BOLD_RESET);

  SetEffect(DIM);
  printf("- DIM\n");
  SetEffect(DIM_RESET);

  SetEffect(ITALIC);
  printf("- ITALIC\n");
  SetEffect(ITALIC_RESET);

  SetEffect(INVERSE);
  printf("- INVERSE\n");
  SetEffect(INVERSE_RESET);

  SetEffect(HIDDEN);
  printf("- HIDDEN");
  SetEffect(HIDDEN_RESET);
  printf("(HIDDEN)\n");

  SetEffect(UNDERLINE);
  printf("- UNDERLINE\n");
  SetEffect(UNDERLINE_RESET);

  SetEffect(STRIKETHROUGH);
  printf("- STRIKETHROUGH\n");
  SetEffect(STRIKETHROUGH_RESET);

  SetEffect(DOUBLE_UNDERLINE);
  printf("- DOUBLE UNDERLINE\n");
  SetEffect(DOUBLE_UNDERLINE_RESET);

  nextScreen();

  printf("You can also use the library to travel around with the cursor:\n\n");

  printf("Press any key to travel around");

  getchar();

  goDownN(5);

  getchar();

  goRightN(5);

  getchar();

  goUpN(5);

  getchar();

  goLeftN(5);

  printf("\n\n");

  nextScreen();

  resetConsole();
  return 0;
}
