const ESC = "\x1b[";

exports.COLOR_4_BIT = {
  TXT_BLACK: 30,
  TXT_RED: 31,
  TXT_GREEN: 32,
  TXT_YELLOW: 33,
  TXT_BLUE: 34,
  TXT_MAGENTA: 35,
  TXT_CYAN: 36,
  TXT_WHITE: 37,

  TXT_DEFAULT: 39,

  BKG_BLACK: 40,
  BKG_RED: 41,
  BKG_GREEN: 42,
  BKG_YELLOW: 43,
  BKG_BLUE: 44,
  BKG_MAGENTA: 45,
  BKG_CYAN: 46,
  BKG_WHITE: 47,

  BKG_DEFAULT: 49,
};

exports.SET_FOUR_BIT_COLOR = function (color) {
  console.log(`${ESC}${color}m`);
};

exports.COLOR_8_BIT = {
  BLACK: 0,
  WHITE: 15,

  DARK_RED: 1,
  DARK_GREEN: 2,
  DARK_YELLOW: 3,
  DARK_BLUE: 4,
  DARK_CYAN: 6,
  DARK_GRAY: 8,

  PURPLE: 5,
  GRAY: 7,
  RED: 9,
  GREEN: 10,
  YELLOW: 11,
  BLUE: 12,
  PINK: 13,
  CYAN: 14,
};

exports.SET_EIGHT_BIT_TEXT_COLOR = function (color) {
  console.log(`${ESC}38;5;${color}m`);
};

exports.SET_EIGHT_BIT_BKG_COLOR = function (color) {
  console.log(`${ESC}48;5;${color}m`);
};

exports.TEXT_EFFECTS = {
  BOLD: 1,
  DIM: 2,
  ITALIC: 3,
  BLINKING: 5,
  INVERSE: 7,
  HIDDEN: 8,
  UNDERLINE: 4,
  STRIKETHROUGH: 9,
  DOUBLE_UNDERLINE: 21,

  BOLD_RESET: 22,
  DIM_RESET: 22,
  ITALIC_RESET: 23,
  BLINKING_RESET: 25,
  INVERSE_RESET: 27,
  HIDDEN_RESET: 28,
  UNDERLINE_RESET: 24,
  STRIKETHROUGH_RESET: 29,
  DOUBLE_UNDERLINE_RESET: 24,
};

exports.SET_EFFECT = function (effect) {
  console.log(`${ESC}${effect}m`);
};

exports.RESET_TEXT = function () {
  console.log(`${ESC}0m`);
};

exports.MOVE_CURSOR_TO_POSITION = function (line, column) {
  console.log(`${ESC}${line};${column}H`);
};

exports.MOVE_CURSOR_UP_BY_N = function (n) {
  console.log(`${ESC}${n}A`);
};

exports.MOVE_CURSOR_DOWN_BY_N = function (n) {
  console.log(`${ESC}${n}B`);
};

exports.MOVE_CURSOR_RIGHT_BY_N = function (n) {
  console.log(`${ESC}${n}C`);
};

exports.MOVE_CURSOR_LEFT_BY_N = function (n) {
  console.log(`${ESC}${n}D`);
};

exports.ERASE_MODE = {
  TO_END: 0,
  TO_BEGINNING: 1,
  ALL: 2,
};

exports.ERASE_SCREEN = function (mode) {
  console.log(`${ESC}${mode}J`);
};

exports.ERASE_LINE = function (mode) {
  console.log(`${ESC}${mode}K`);
};

exports.ERASE_ENTIRE_SCREEN = function () {
  console.log(`${ESC}2J`);
};
