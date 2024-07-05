#ifndef ANSI_LIB_H
#define ANSI_LIB_H

#include <stdio.h>

#define CONTROL_CODE "\x1b["

typedef enum {
  RESET = 0,

  TXT_BLACK = 30,
  TXT_RED = 31,
  TXT_GREEN = 32,
  TXT_YELLOW = 33,
  TXT_BLUE = 34,
  TXT_MAGENTA = 35,
  TXT_CYAN = 36,
  TXT_WHITE = 37,

  TXT_DEFAULT = 39,

  BKG_BLACK = 40,
  BKG_RED = 41,
  BKG_GREEN = 42,
  BKG_YELLOW = 43,
  BKG_BLUE = 44,
  BKG_MAGENTA = 45,
  BKG_CYAN = 46,
  BKG_WHITE = 47,

  BKG_DEFAULT = 49,

} Colors;

typedef enum {
  BOLD = 1,
  DIM = 2,
  ITALIC = 3,
  UNDERLINE = 4,
  BLINKING = 5,
  INVERSE = 7,
  HIDDEN = 8,
  STRIKETHROUGH = 9,
  DOUBLE_UNDERLINE = 21,

  BOLD_RESET = 22,
  DIM_RESET = 22,
  ITALIC_RESET = 23,
  UNDERLINE_RESET = 24,
  DOUBLE_UNDERLINE_RESET = 24,
  BLINKING_RESET = 25,
  INVERSE_RESET = 27,
  HIDDEN_RESET = 28,
  STRIKETHROUGH_RESET = 29,
} Effects;

typedef unsigned char uchar;

extern inline void SetColor(Colors color) {
  printf("%s%dm", CONTROL_CODE, color);
};

extern inline void SetText256Color(uchar color) {
  printf("%s38;5;%dm", CONTROL_CODE, color);
};

extern inline void SetBackground256Color(uchar color) {
  printf("%s48;5;%dm", CONTROL_CODE, color);
};

extern inline void SetTextRGBColor(uchar r, uchar g, uchar b) {
  printf("%s38;2;%d;%d;%dm", CONTROL_CODE, r, g, b);
}

extern inline void SetTextRGBColorArr(uchar rgb[3]) {
  SetTextRGBColor(rgb[0], rgb[1], rgb[2]);
}

extern inline void SetBackgroundRGBColor(uchar r, uchar g, uchar b) {
  printf("%s48;2;%d;%d;%dm", CONTROL_CODE, r, g, b);
}

extern inline void SetBackgroundRGBColorArr(uchar rgb[3]) {
  SetBackgroundRGBColor(rgb[0], rgb[1], rgb[2]);
}

extern inline void SetEffect(Effects effect) {
  printf("%s%dm", CONTROL_CODE, effect);
}

extern inline void Reset() { printf("%s%dm", CONTROL_CODE, RESET); }

typedef unsigned int uint;

extern inline void gotoXY(uint x, uint y) {
  printf("%s%d;%dH", CONTROL_CODE, x, y);
}

// UP, DOWN, RIGHT, LEFT

extern inline void goUpN(uint n) { printf("%s%dA", CONTROL_CODE, n); }

extern inline void goDownN(uint n) { printf("%s%dB", CONTROL_CODE, n); }

extern inline void goRightN(uint n) { printf("%s%dC", CONTROL_CODE, n); }

extern inline void goLeftN(uint n) { printf("%s%dD", CONTROL_CODE, n); }

typedef enum {
  TO_BOTTOM = 0,
  TO_END = 0,
  TO_TOP = 1,
  TO_BEGINNING = 1,
  ALL = 2,
} EraseMode;

extern inline void ClearScreen(EraseMode mode) {
  printf("%s%dJ", CONTROL_CODE, mode);
}

extern inline void Clear() { ClearScreen(ALL); }

extern inline void ClearLine(EraseMode mode) {
  printf("%s%dK", CONTROL_CODE, mode);
}

#ifdef _WIN32

#define _CRT_SECURE_NO_WARNINGS 1

#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

#endif

#define WIN_ERR exit(GetLastError())

#endif

#include <stdio.h>

#ifdef _WIN32

static HANDLE stdOutputHandle;
static DWORD outputModeInitial;

/**
 * @brief Sets the console to an initial state
 */
static void setupConsole(void) {
  DWORD outputMode = 0;

  stdOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  if (stdOutputHandle == INVALID_HANDLE_VALUE) {
    WIN_ERR;
  }

  if (!GetConsoleMode(stdOutputHandle, &outputMode)) {
    WIN_ERR;
  }

  outputModeInitial = outputMode;

  outputMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

  if (!SetConsoleMode(stdOutputHandle, outputMode)) {
    WIN_ERR;
  }
}

/**
 * @brief Resets the console to the initial state
 */
static void resetConsole(void) {
  printf("\x1b[0m");
  if (!SetConsoleMode(stdOutputHandle, outputModeInitial)) {
    WIN_ERR;
  }
}

#else

/**
 * @brief Sets the console to an initial state
 */
static void setupConsole(void) {}

/**
 * @brief Resets the console to the initial state
 */
static void resetConsole(void) { printf("\x1b[0m"); }

#endif

#endif
