#ifndef ANSI_LIB_H
#define ANSI_LIB_H

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
inline void setupConsole(void) {
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
inline void resetConsole(void) {
  printf("\x1b[0m");
  if (!SetConsoleMode(stdOutputHandle, outputModeInitial)) {
    WIN_ERR;
  }
}

#else

/**
 * @brief Sets the console to an initial state
 */
inline void setupConsole(void) {}

/**
 * @brief Resets the console to the initial state
 */
inline void resetConsole(void) { printf("\x1b[0m"); }

#endif

/* ===== TEXT EFFECTS =====*/

/**
 * @brief The 4-bit colors supported by the terminal
 */
enum COLOR_4_BIT {
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

  BKG_DEFAULT = 49
};

/**
 * @brief Set the color using the 4-bit color codes
 *
 * @param color the color code value
 */
inline void SET_FOUR_BIT_COLOR(COLOR_4_BIT color) { printf("\x1b[%dm", color); }

/**
 * @brief Contain the first 16 values of the 8-bit color codes
 */
enum COLOR_8_BIT {
  BLACK = 0,
  WHITE = 15,

  DARK_RED = 1,
  DARK_GREEN = 2,
  DARK_YELLOW = 3,
  DARK_BLUE = 4,
  DARK_CYAN = 6,
  DARK_GRAY = 8,

  PURPLE = 5,
  GRAY = 7,
  RED = 9,
  GREEN = 10,
  YELLOW = 11,
  BLUE = 12,
  PINK = 13,
  CYAN = 14
};

#define uchar unsigned char

/**
 * @brief Set the font color using the 8-bit color codes
 *
 * @param color the color code value
 */
inline void SET_EIGHT_BIT_TEXT_COLOR(COLOR_8_BIT color) {
  printf("\x1b[38;5;%dm", color);
}
/**
 * @brief Set the font color using the 8-bit color codes
 *
 *  @param color the color code value
 */
inline void SET_EIGHT_BIT_TEXT_COLOR(uchar color) {
  printf("\x1b[38;5;%dm", color);
}

/**
 * @brief Set the background color using the 8-bit color codes
 *
 * @param color the color code value
 */
inline void SET_EIGHT_BIT_BKG_COLOR(COLOR_8_BIT color) {
  printf("\x1b[48;5;%dm", color);
}
/**
 * @brief Set the background color using the 8-bit color codes
 *
 * @param color the color code value
 */
inline void SET_EIGHT_BIT_BKG_COLOR(uchar color) {
  printf("\x1b[48;5;%dm", color);
}

/**
 * @brief Set the text color based on RGB values
 *
 * @param r the red channel value (0-255).
 * @param g the green channel value (0-255).
 * @param b the blue channel value (0-255).
 *
 * @note Only works in terminals that support Truecolor.
 */
inline void SET_RGB_TEXT_COLOR(uchar r, uchar g, uchar b) {
  printf("\x1b[38;2;%d;%d;%dm", r, g, b);
}

/**
 * @brief Set the text color based on RGB values.
 *
 * @param color an array with 3 values containing the values of the 3 channels:
 * (r, g, b)
 *
 * @note Only works in terminals that support Truecolor.
 */
inline void SET_RGB_TEXT_COLOR(uchar color[3]) {
  printf("\x1b[38;2;%d;%d;%dm", color[0], color[1], color[2]);
}

/**
 * @brief Set the background color based on RGB values
 *
 * @param r the red channel value (0-255).
 * @param g the green channel value (0-255).
 * @param b the blue channel value (0-255).
 *
 * @note Only works in terminals that support Truecolor.
 */
inline void SET_RGB_BKG_COLOR(uchar r, uchar g, uchar b) {
  printf("\x1b[48;2;%d;%d;%dm", r, g, b);
}

/**
 * @brief Set the background color based on RGB values.
 *
 * @param color an array with 3 values containing the values of the 3 channels:
 * (r, g, b)
 *
 * @note Only works in terminals that support Truecolor.
 */
inline void SET_RGB_BACKGROUND_COLOR(uchar color[3]) {
  printf("\x1b[48;2;%d;%d;%dm", color[0], color[1], color[2]);
}

/**
 * @brief The codes for the text effects
 *
 * @note Some of the features are not implemented in all terminals.
 */
enum TEXT_EFFECTS {
  BOLD = 1,
  DIM = 2,
  ITALIC = 3,
  BLINKING = 5,
  INVERSE = 7,
  HIDDEN = 8,
  UNDERLINE = 4,
  STRIKETHROUGH = 9,
  DOUBLE_UNDERLINE = 21,

  BOLD_RESET = 22,
  DIM_RESET = BOLD_RESET,
  ITALIC_RESET = 23,
  BLINKING_RESET = 25,
  INVERSE_RESET = 27,
  HIDDEN_RESET = 28,
  UNDERLINE_RESET = 24,
  STRIKETHROUGH_RESET = 29,
  DOUBLE_UNDERLINE_RESET = UNDERLINE_RESET
};

/**
 * @brief Sets a text effect
 *
 * @param effect the effect to be applied to text.
 */
inline void SET_TRANSFORM(TEXT_EFFECTS effect) { printf("\x1b[%dm", effect); }

/**
 * @brief Reset the effects and colors applied to the terminal.
 */
inline void RESET_TEXT(void) { printf("\x1b[0m"); }

/* ===== CURSOR MOVEMENT =====*/

#define uint unsigned int

/**
 * @brief Move cursor to the coordinates (line, column).
 *
 * @param line the line the cursor will be positioned on
 * @param column the column the cursor will be positioned on
 */
inline void MOVE_CURSOR_TO_POSITION(uint line, uint column) {
  printf("\x1b[%d;%dH", line, column);
}

/**
 * @brief Move cursor up a number of lines
 *
 * @param n the number of lines to move the cursor up by
 */
inline void MOVE_CURSOR_UP_BY_N(uint n) { printf("\x1b[%dA", n); }

/**
 * @brief Move cursor down a number of lines
 *
 * @param n the number of lines to move the cursor down by
 */
inline void MOVE_CURSOR_DOWN_BY_N(uint n) { printf("\x1b[%dB", n); }

/**
 * @brief Move cursor right a number of columns
 *
 * @param n the number of columns to move the cursor up by
 */
inline void MOVE_CURSOR_RIGHT_BY_N(uint n) { printf("\x1b[%dC", n); }

/**
 * @brief Move cursor down a number of lines
 *
 * @param n the number of lines to move the cursor down by
 */
inline void MOVE_CURSOR_LEFT_BY_N(uint n) { printf("\x1b[%dD", n); }

/**
 * @brief The mode in which the erase function will be executed
 *
 */
enum ERASE_MODE {
  TO_END = 0,
  TO_BEGINNING = 1,
  ALL = 2,
};

/**
 * @brief Erases the screen based on the mode selected
 *
 * @param mode the mode in which the erase function will be executed
 */
inline void ERASE_SCREEN(ERASE_MODE mode) { printf("\x1b[%dJ", mode); }

/**
 * @brief Erases the line based on the mode selected
 *
 * @param mode the mode in which the erase function will be executed
 * @note The cursor's position won't be affected by this
 */
inline void ERASE_LINE(ERASE_MODE mode) { printf("\x1b[%dJ", mode); }

/**
 * @brief Erases the entire screen
 *
 */
inline void ERASE_SCREEN(void) { ERASE_SCREEN(ERASE_MODE::ALL); }

#endif