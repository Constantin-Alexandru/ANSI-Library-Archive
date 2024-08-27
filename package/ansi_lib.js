const assert = require("node:assert/strict");
const process = require("node:process");

/** @type {string} */
const ESC = "\x1b[";

/** @enum {number} */
exports.Colors = {
  RESET: 0,

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

/** @enum {number} */
exports.Effects = {
  BOLD: 1,
  DIM: 2,
  ITALIC: 3,
  UNDERLINE: 4,
  BLINKING: 5,
  INVERSE: 7,
  HIDDEN: 8,
  STRIKETHROUGH: 9,
  DOUBLE_UNDERLINE: 21,

  BOLD_RESET: 22,
  DIM_RESET: 22,
  ITALIC_RESET: 23,
  UNDERLINE_RESET: 24,
  DOUBLE_UNDERLINE_RESET: 24,
  BLINKING_RESET: 25,
  INVERSE_RESET: 27,
  HIDDEN_RESET: 28,
  STRIKETHROUGH_RESET: 29,
};

/**
 * Sets the color of the terminal to the specified colors
 *
 * @param {Colors} color - The color to set the
 */
exports.SetColor = function (color) {
  process.stdout.write(`${ESC}${color}m`);
};

/**
 * Sets the text color of the terminal using an 8-bit value
 *
 * @params {number} color - The color as an 8-bit value (0 - 255)
 */
exports.SetText256Color = function (color) {
  assert(color < 256, "Error: value of color should be an 8-bit value (0-255)");

  process.stdout.write(`${ESC}38;5;${color}m`);
};

/**
 * Sets the background color of the terminal using an 8-bit value
 *
 * @params {number} color - The color as an 8-bit value (0 - 255)
 */
exports.SetBackground256Color = function (color) {
  assert(color < 256, "Error: value of color should be an 8-bit value (0-255)");

  process.stdout.write(`${ESC}48;5;${color}m`);
};

/**
 * @typedef {Object} RGB
 * @property {number} r - The red layer
 * @property {number} g - The green layer
 * @property {number} b - The blue layer
 */

/**
 * Sets the text color of the terminal using an rgb value
 *
 * @param {RGB} rgb - The rgb color
 */
exports.SetRGBTextColor = function (rgb) {
  process.stdout.write(`${ESC}38;2;${rgb.r};${rgb.g};${rgb.b}m`);
};

/**
 * Sets the text color of the terminal using an rgb value
 *
 * @param {number} r - The red layer
 * @param {number} g - The green layer
 * @param {number} b - The blue layer
 */
exports.SetRGBTextColor = function (r, g, b) {
  SetRGBTextColor({ r: r, g: g, b: b });
};

/**
 * Sets the background color of the terminal using an rgb value
 *
 * @param {RGB} rgb - The rgb color
 */
exports.SetRGBBackgroundColor = function (rgb) {
  process.stdout.write(`${ESC}48;2;${rgb.r};${rgb.g};${rgb.b}m`);
};

/**
 * Sets the background color of the terminal using an rgb value
 *
 * @param {number} r - The red layer
 * @param {number} g - The green layer
 * @param {number} b - The blue layer
 */
exports.SetRGBBackgroundColor = function (r, g, b) {
  SetRGBBackgroundColor({ r: r, g: g, b: b });
};

/**
 * Sets a text effect
 *
 * @param {Effects} effect
 */
exports.SetEffect = function (effect) {
  process.stdout.write(`${ESC}${effect}m`);
};

/**
 * Resets the console to the default values.
 */
exports.Reset = function () {
  process.stdout.write(`${ESC}${Colors.RESET}m`);
};

/**
 * Jumps to the specified coordinated inside the console.
 *
 * @param {number} x - the x coordinate (the column).
 * @param {number} y - the y coordinate (the row).
 */
exports.gotoXY = function (x, y) {
  process.stdout.write(`${ESC}${x};${y}H`);
};

/**
 * Jumps up n lines in the console.
 *
 * @param {number} n - the number of lines to jump
 */
exports.goUpN = function (n) {
  process.stdout.write(`${ESC}${n}A`);
};

/**
 * Jumps down n lines in the console.
 *
 * @param {number} n - the number of lines to jump
 */
exports.goDownN = function (n) {
  process.stdout.write(`${ESC}${n}B`);
};

/**
 * Jumps left n columns in the console.
 *
 * @param {number} n - the number of columns to jump
 */
exports.goLeftN = function (n) {
  process.stdout.write(`${ESC}${n}D`);
};

/**
 * Jumps right n columns in the console.
 *
 * @param {number} n - the number of columns to jump
 */
exports.goRightN = function (n) {
  process.stdout.write(`${ESC}${n}C`);
};

/** @enum {number} */
exports.EraseMode = {
  TO_BOTTOM: 0,
  TO_END: 0,
  TO_TOP: 1,
  TO_BEGINNING: 1,
  ALL: 2,
};

/**
 * Clears the entire screen based on the mode.
 *
 * @param {EraseMode} mode - The erase mode.
 */
exports.ClearScreen = function (mode) {
  process.stdout.write(`${ESC}${mode}J`);
};

/**
 * Clears the entire screen based on the mode.
 */
exports.ClearScreen = function () {
  ClearScreen(EraseMode.ALL);
};

/**
 * Clears the entire line based on the mode.
 *
 * @param {EraseMode} mode - The erase mode.
 */
exports.ClearLine = function (mode) {
  process.stdout.write(`${ESC}${mode}K`);
};
