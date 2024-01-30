#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ansi_lib.h"

void nextScreen(void) {
  printf("Press any key to continue...\n");

  getchar();

  ERASE_ENTIRE_SCREEN();
  MOVE_CURSOR_TO_POSITION(0, 0);
}

int main(int argc, char const *argv[]) {
  setupConsole();
  ERASE_ENTIRE_SCREEN();

  SET_EFFECT(BOLD);
  printf("ANSI LIB SHOWCASE");
  SET_EFFECT(BOLD_RESET);
  MOVE_CURSOR_DOWN_BY_N(3);
  MOVE_CURSOR_LEFT_BY_N(50);

  printf(
      "This project was created to showcase the ANSI LIBRARY and it's "
      "features.\n");

  printf("The main feature of this library is the ability to change colors.\n");

  MOVE_CURSOR_DOWN_BY_N(2);

  nextScreen();

  printf(
      "You have 4-bit colors that can be used for both background and "
      "foreground:\n\n");

  for (int text_color = 30; text_color < 38; text_color++) {
    SET_FOUR_BIT_COLOR((enum COLOR_4_BIT)text_color);
    for (int background_color = 40; background_color < 48; background_color++) {
      // if (background_color - text_color == 10) continue;

      SET_FOUR_BIT_COLOR((enum COLOR_4_BIT)background_color);
      printf("  %d", text_color);
      SET_FOUR_BIT_COLOR((enum COLOR_4_BIT)BKG_DEFAULT);
    }
    printf("\n");
    SET_FOUR_BIT_COLOR((enum COLOR_4_BIT)TXT_DEFAULT);
  }

  nextScreen();

  printf(
      "You have 8-bit colors that can be used for both background and "
      "foreground:\n\n");

  for (int color = 0; color < 256; color++) {
    if (color % 16 == 0) printf("\n");
    SET_EIGHT_BIT_TEXT_COLOR_NUM(color);
    SET_EIGHT_BIT_BKG_COLOR_NUM(255 - color);
    printf("%*d ", 3, color);
  }

  printf("\n");

  nextScreen();

  printf(
      "Some terminals also support Truecolor values for background and "
      "foreground:\n\n");

  srand(time(NULL));

  for (int iter = 0; iter < 10; iter++) {
    uint r = rand() % 256;
    uint g = rand() % 256;
    uint b = rand() % 256;

    SET_RGB_TEXT_COLOR(r, g, b);
    SET_RGB_BKG_COLOR(255 - r, 255 - g, 255 - b);
    printf("%*d - %*d - %*d\n", 3, r, 3, g, 3, b);
  }
  RESET_TEXT();
  nextScreen();

  printf("The library also offers effects that can be applied to text:\n\n");

  SET_EFFECT(BOLD);
  printf("- BOLD\n");
  SET_EFFECT(BOLD_RESET);

  SET_EFFECT(DIM);
  printf("- DIM\n");
  SET_EFFECT(DIM_RESET);

  SET_EFFECT(ITALIC);
  printf("- ITALIC\n");
  SET_EFFECT(ITALIC_RESET);

  SET_EFFECT(INVERSE);
  printf("- INVERSE\n");
  SET_EFFECT(INVERSE_RESET);

  SET_EFFECT(HIDDEN);
  printf("- HIDDEN");
  SET_EFFECT(HIDDEN_RESET);
  printf("(HIDDEN)\n");

  SET_EFFECT(UNDERLINE);
  printf("- UNDERLINE\n");
  SET_EFFECT(UNDERLINE_RESET);

  SET_EFFECT(STRIKETHROUGH);
  printf("- STRIKETHROUGH\n");
  SET_EFFECT(STRIKETHROUGH_RESET);

  SET_EFFECT(DOUBLE_UNDERLINE);
  printf("- DOUBLE UNDERLINE\n");
  SET_EFFECT(DOUBLE_UNDERLINE_RESET);

  nextScreen();

  printf("You can also use the library to travel around with the cursor:\n\n");

  printf("Press any key to travel around");

  getchar();

  MOVE_CURSOR_DOWN_BY_N(5);

  getchar();

  MOVE_CURSOR_RIGHT_BY_N(5);

  getchar();

  MOVE_CURSOR_UP_BY_N(5);

  getchar();

  MOVE_CURSOR_LEFT_BY_N(5);

  printf("\n\n");

  nextScreen();

  resetConsole();
  return 0;
}