#pragma once

#ifndef ANSII_LIB_H
#define ANSII_LIB_H


#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS  1
    #include <windows.h>

    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
        #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif


    #define WIN_ERR exit(GetLastError())
#endif

#include <stdio.h>

    #ifdef _WIN32
    /**
     * @brief The handle for the standard output stream.
     * 
     */
    static HANDLE stdOutHandle;

    /**
     * @brief The initial state of the output stream.
     * 
     */
    static DWORD outModeInitial;

    /**
     * @brief Sets the Windows console to allow virtual terminal codes.
     * 
     */
    void setupConsole(void){
        DWORD outMode = 0;
        stdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

        if(stdOutHandle == INVALID_HANDLE_VALUE) { WIN_ERR; }

        if(!GetConsoleMode(stdOutHandle, &outMode)) { WIN_ERR; }

        outModeInitial = outMode;

        // Allow virtual terminal codes.
        outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

        if(!SetConsoleMode(stdOutHandle, outMode)) { WIN_ERR; }
        
    }

    /**
     * @brief Resets the console to the inital state without the virtual terminal codes.
     * 
     */
    void resetConsole(void){

        //Resets the console attributes to white text and black background.
        printf("\x1b[0m");

        //Resets the console mode to it's initial state.
        if(!SetConsoleMode(stdOutHandle, outModeInitial)) { WIN_ERR; }
    }

    #else
    
    /**
     * @brief Resets the console to the inital state without the virtual terminal codes.
     * 
     */
    void resetConsole(void){
        //Resets the console attributes to white text and black background.
        printf("\x1b[0m");
    }

    #endif

    /* ===================================== COLOUR/GRAPHICS MODE ===================================== */

    /**
     * @brief The codes of the Colour Sequences.
     * 
     */
    enum Colours{
        //Text Colours
        TXT_BLACK = 30,
        TXT_RED = 31,
        TXT_GREEN = 32,
        TXT_YELLOW = 33,
        TXT_BLUE = 34,
        TXT_MAGENTA = 35,
        TXT_CYAN = 36,
        TXT_WHITE = 37,

        TXT_DEFAULT = 39,

        //Background Colours
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
     * @brief Sets the text colour using the 8 ANSII values inside the Colours enum.
     * @param code the colour code accepts values from the Colour enum.
     * 
     */
    #define SET_8_VALUE_COLOUR(code) printf("\x1b[%dm", code)

    /**
     * @brief Sets the text colour using the 0 - 255 range.
     * @param code the colour code accepts values from the 0 - 255 range.
     * 
     */
    #define SET_256_TXT_COLOUR(code) printf("\x1b[38;5;%dm", code)
    /**
     * @brief Sets the background colour using the 0 - 255 range.
     * @param code the colour code accepts values from the 0 - 255 range.
     * 
     */
    #define SET_256_BKG_COLOUR(code) printf("\x1b[38;5;%dm", code)

    /**
     * @brief Sets the text colour using RGB values.
     * @param r the red channel only accepts values from the 0-255 range.
     * @param g the green channel only accepts values from the 0-255 range.
     * @param b the blue channel only accepts values from the 0-255 range.
     * @b NOTE: Only works on some terminals.
     */
    #define SET_RGB_TXT_COLOUR(r, g, b) printf("\x1b[38;2;%d;%d;%dm", r, g, b)
    
    /**
     * @brief Sets the background colour using RGB values.
     * @param r the red channel only accepts values from the 0-255 range.
     * @param g the green channel only accepts values from the 0-255 range.
     * @param b the blue channel only accepts values from the 0-255 range.
     * @b NOTE: Only works on some terminals. 
     */
    #define SET_RGB_BKG_COLOUR(r, g, b) printf("\x1b[48;2;%d;%d;%dm", r, g, b)

    /**
     * @brief The codes of the Graphics Sequences.
     * 
     */
    enum GRAPHIC_MODE{
        //Graphic sequences.
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

        //Reset sequences.
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

    /**
     * @brief Sets the graphic mode using the codes inside the GRAPHIC_MODE enum
     * @param code The code from the GRAPHIC_MODE enum
     * 
     */
    #define SET_GRAPHIC_MODE(code) printf("\x1b[%dm", code)

    /**
     * @brief Resets all graphics modes and colours.
     * 
     */
    #define RESET_GRAPHICS_MODES printf("\x1b[0m")

    /* ===================================== SCREEN MODE ===================================== */

    /**
     * @brief The codes of the Screen Sequences.
     * 
     */
    enum SCREEN_CODE{
        MONOCHROME_40_25 = 0,
        COLOUR_40_25 = 1,
        
        MONOCHROME_80_25 = 2,
        COLOUR_80_25 = 3,
        
        MONOCHROME_320_200 = 5,
        COLOUR4_320_200 = 4,
        COLOUR16_320_200 = 13,
        COLOUR256_320_200 = 19,

        MONOCHROME_640_200 = 6,
        COLOUR_640_200 = 14,

        MONOCHROME_640_350 = 15,
        COLOUR_640_350 = 16,

        MONOCHROME_640_480 = 17,
        COLOUR_640_480 = 18,

        LINE_WRAP = 7
    };

    /**
     * @brief Sets the screen mode using the SCREEN_CODE enum.
     * @param code the SCREEN_CODE enum value.
     * @b NOTE: Given any value above 20, the command will set the screen size to the value.
     */
    #define SET_SCREEN_MODE(code) printf("\x1b[=%dh", code)
    
    /**
     * @brief Resets the screen mode using the SCREEN_CODE enum.
     * @param code the SCREEN_CODE enum value.
     */
    #define RESET_SCREEN_MODE(code) printf("\x1b[=%dl", code)

    /**
     * @brief Moves cursor to the (line, column) position.
     * @param line The line to move the cursor to.
     * @param column The column to move the cursor to.
     * 
     */
    #define MOVE_CURSOR_TO_POS(line, column) printf("\x1b[%d;%dH", line, column)

    /**
     * @brief Moves cursor up by a number of lines.
     * @param lines The number of lines to move the cursor by.
     * 
     */
    #define MOVE_CURSOR_UP_BY_LINES(lines) printf("\x1b[%dA", lines)
    /**
     * @brief Moves cursor down by a number of lines.
     * @param lines The number of lines to move the cursor by.
     * 
     */
    #define MOVE_CURSOR_DOWN_BY_LINES(lines) printf("\x1b[%dB", lines)
    
    /**
     * @brief Moves cursor right by a number of columns.
     * @param columns The number of columns to move the cursor by.
     * 
     */
    #define MOVE_CURSOR_RIGHT_BY_COLUMNS(columns) printf("\x1b[%dC", columns)
    /**
     * @brief Moves cursor left by a number of columns.
     * @param columns The number of columns to move the cursor by.
     * 
     */
    #define MOVE_CURSOR_LEFT_BY_COLUMS(columns) printf("\x1b[%dD", columns)
    
    /**
     * @brief Moves cursor down by a number of lines, at the beginning of the line.
     * @param lines The number of lines to move the cursor by.
     * 
     */
    #define MOVE_CURSOR_BEGINNING_LINE_DOWN_BY_LINES(lines) printf("\x1b[%dE", lines)
    /**
     * @brief Moves cursor up by a number of lines, at the beginning of the line.
     * @param lines The number of lines to move the cursor by.
     * 
     */
    #define MOVE_CURSOR_BEGINNING_LINE_UP_BY_LINES(lines) printf("\x1b[%dF", lines)

    /**
     * @brief Moves cursor to column.
     * @param column The column where the cursor is moved.
     * 
     */
    #define MOVE_CURSOR_TO_COLUMN(column) printf("\x1b[%dG", column)

    /* ===================================== ERASE MODE ===================================== */

    /**
     * @brief The codes of the Erase Sequence.
     * 
     */
    enum ERASE_CODE{
        ERASE_TO_END = 0,
        ERASE_TO_BEGINNING = 1,
        ERASE_ALL = 3,
    };

    /**
     * @brief Erases the screen based on the value from the ERASE_CODE enum.
     * @param code The code from the ERASE_CODE enum.
     * 
     */
    #define ERASE_IN_SCREEN(code) printf("\x1b[%dJ", code)
    /**
     * @brief Erases the line based on the value from the ERASE_CODE enum.
     * @param code The code from the ERASE_CODE enum.
     * @b NOTE: The cursor won't move positions after the erase.
     * 
     */
    #define ERASE_IN_LINE(code) printf("\x1b[%dK", code)

    /**
     * @brief Erases the visible screen
     * 
     */
    #define ERASE_SCREEN printf("\x1b[H\x1b[J")

#endif