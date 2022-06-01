ANSI LIB
=========

Ansi Lib is a 1 header C/C++ library which aims to help the developer take advantage of the [ANSI Escape Codes](https://en.wikipedia.org/wiki/ANSI_escape_code) inside the terminal.

### HOW TO ADD THE LIBRARY TO YOUR PROJECT

In order to use this library, you can add the library as a submodule for your git project using the `git submodule` command, or you can download the header file and add it to your headers folder.

### HOW TO USE THE LIBRARY

In order to use ANSI Lib in your project, you have to include the library in your file using: 
```c 
#include "./path-to-lib/ansi_lib.h" 
```
After that, the library is ready to go

***NOTE:*** On Windows, in order for the project to work, you'll need to call the `setupConsole()` function before any other command working successfully.

***NOTE:*** At the end of the program, in order to reset the console to it's initial state, regardless of Operating System, you have the option of calling the `resetConsole()` function.

#### **COLOUR FUNCTIONS**

There are 3 different functions that allow you to change the colour of your text and 3 functions that allow you to change the colour of the background, each with it's own constraints.

##### **COLOUR ENUM**

```cpp
enum Colours{
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
```

ANSI supports only 8 values in this configuration, each being stored with a value inside the enum.

In order to use this enum, you call the `SET_8_VALUE_COLOUR(value)` function that sets either the text colour or the background colour, based on the value given inside the enum.

`TXT_DEFAULT` and `BKG_DEFAULT` reset the terminal to it's default configurations.

##### **256 COLOURS**

ANSI also supports a 256 value based colouring by calling `SET_256_TXT_COLOUR(value)` and `SET_256_BKG_COLOUR(value)`, the colour of the text, and the background respectively, will be changed according to the given value, value that has to be between 0 and 255.

##### **RGB COLOURS**

Although not supported by all terminals, some terminals allow the user to define a colour using it's RGB value. You can change the colours of the terminal by calling `SET_RGB_TXT_COLOUR(r, g, b)` and `SET_RGB_BKG_COLOUR(r, g, b)`.

#### **GRAPHIC FUNCTIONS**

```cpp
enum GRAPHIC_CODE{
    BOLD_MODE = 1,
    DIM_MODE = 2,
    ITALIC_MODE = 3,
    UNDERLINE_MODE = 4,
    BLINKING_MODE = 5,
    INVERSE_MODE = 7,
    HIDDEN_MODE = 8,
    STRIKETHROUGH_MODE = 9,
    //Only works on some terminals.
    DOUBLE_UNDERLINE_MODE = 21,

    BOLD_MODE_RESET = 22,
    DIM_MODE_RESET = BOLD_MODE_RESET,
    ITALIC_MODE_RESET = 23,
    UNDERLINE_MODE_RESET = 24,
    BLINKING_MODE_RESET = 25,
    INVERSE_MODE_RESET = 27,
    HIDDEN_MODE_RESET = 28,
    STRIKETHROUGH_MODE_RESET = 29,
    //Only works on some terminals
    DOUBLE_UNDERLINE_MODE_RESET = UNDERLINE_MODE_RESET
};
```

The graphic modes affect the way the text is displayed by applying a different effect based on the *GRAPHIC_CODE* value passed to the `SET_GRAPHIC_MODE(value)` function. 

In order to reset one of the Graphic Modes, you will need to call the same function and pass the ***RESET*** value corresponding to the graphic mode you want to disable.

In order to reset all graphic modes, you can call the `RESET_GRAPHICS_MODES()` function.
***NOTE:*** This function resets the colours as well.

#### **CURSOR FUNCTIONS**

The cursor functions allow the developer to move the cursor inside the window.

The library contains the following functions:

```cpp

MOVE_CURSOR_TO_POS(line, column) //Moves cursor to the (line, column) position.

MOVE_CURSOR_UP_BY_LINES(lines) //Moves cursor up by the specified number of lines.

MOVE_CURSOR_DOWN_BY_LINES(lines) //Moves cursor down by the specified number of lines.

MOVE_CURSOR_RIGHT_BY_COLUMNS(columns) //Moves cursor right by a number of columns.

MOVE_CURSOR_LEFT_BY_COLUMS(columns) //Moves cursor left by a number of columns. 

MOVE_CURSOR_BEGINNING_LINE_DOWN_BY_LINES(lines) //Moves cursor down by a number of lines, at the beginning of the line.

MOVE_CURSOR_BEGINNING_LINE_UP_BY_LINES(lines) //Moves cursor up by a number of lines, at the beginning of the line.

MOVE_CURSOR_TO_COLUMN(column) //Moves cursor to specified column.
```

#### **ERASE FUNCTIONS**

ANSI allows erasing of the contents on the screen.

The erase functions have at their center the following enum:

```cpp
enum ERASE_CODE{
    ERASE_TO_END = 0,
    ERASE_TO_BEGINNING = 1,
    ERASE_ALL = 3,
};
```

The erase functions that use the enum are `ERASE_IN_SCREEN(value)` and `ERASE_IN_LINE(value)`.
The direction of the erasing is dependent on the *ERASE_CODE* provided.

The library also provides a function that allows you to clear the entire screen without calling `ERASE_IN_SCREEN(ERASE_ALL)`, due to known issues of the command not working on some terminals. The command `ERASE_SCREEN()` clears the entire visible buffer of the console. 

***NOTE:*** No erase command can erase the lines of the console which are not visible on the screen.
