#include <stdio.h>


#ifdef _WIN32
    #include <Windows.h>
#else 
    #include <unistd.h>
#endif

#include "../ansi_lib.h"

#define HELLO_WORLD printf("Hello, World!")
#define HELLO_WORLDn printf("Hello, World!\n")

/**
 * NOTE: If buffer overflows, the ERASE functions doesn't erase prior to the last shown line.
 * 
 */

int main()
{

#ifdef _WIN32
    setupConsole();
#endif

    /* TESTING COLOURS */

    printf("======== TESTING COLOURS ========\n");

    printf("    ==== 8 VALUE COLOUR ==== \n");

    SET_8_VALUE_COLOUR(BKG_WHITE);
    SET_8_VALUE_COLOUR(TXT_BLACK);
    HELLO_WORLDn;

    SET_8_VALUE_COLOUR(BKG_CYAN);
    SET_8_VALUE_COLOUR(TXT_RED);
    HELLO_WORLDn;

    SET_8_VALUE_COLOUR(BKG_MAGENTA);
    SET_8_VALUE_COLOUR(TXT_GREEN);
    HELLO_WORLDn;

    SET_8_VALUE_COLOUR(BKG_BLUE);
    SET_8_VALUE_COLOUR(TXT_YELLOW);
    HELLO_WORLDn;

    SET_8_VALUE_COLOUR(BKG_YELLOW);
    SET_8_VALUE_COLOUR(TXT_BLUE);
    HELLO_WORLDn;

    SET_8_VALUE_COLOUR(BKG_GREEN);
    SET_8_VALUE_COLOUR(TXT_MAGENTA);
    HELLO_WORLDn;

    SET_8_VALUE_COLOUR(BKG_RED);
    SET_8_VALUE_COLOUR(TXT_CYAN);
    HELLO_WORLDn;

    SET_8_VALUE_COLOUR(BKG_BLACK);
    SET_8_VALUE_COLOUR(TXT_WHITE);
    HELLO_WORLDn;

    sleep(1);
    
    RESET_GRAPHICS_MODES;
    MOVE_CURSOR_TO_POS(0, 0);
    ERASE_SCREEN;

    printf("======== TESTING COLOURS ========\n");

    printf("    ==== 256 VALUE COLOUR ==== \n");

    for(size_t i = 0; i < 15; i++)
    {
        SET_256_BKG_COLOUR(255 - i);
        SET_256_TXT_COLOUR(i);
        HELLO_WORLDn;
    }


    sleep(1);

    RESET_GRAPHICS_MODES;
    MOVE_CURSOR_TO_POS(0, 0);
    ERASE_SCREEN;


    printf("======== TESTING COLOURS ========\n");

    printf("    ==== RGB VALUE COLOUR ==== \n");

    for(size_t r = 0; r < 15; r++)
    {
        SET_RGB_BKG_COLOUR(255 - r, 255, 255);
        SET_RGB_TXT_COLOUR(r, 0, 0);
        HELLO_WORLD;
    }

    
    for(size_t g = 0; g < 15; g++)
    {
        SET_RGB_BKG_COLOUR(255, 255 - g, 255);
        SET_RGB_TXT_COLOUR(0, g, 0);
        HELLO_WORLD;
    }

    for(size_t b = 0; b < 15; b++)
    {
        SET_RGB_BKG_COLOUR(255, 255, 255 - b);
        SET_RGB_TXT_COLOUR(0, 0, b);
        HELLO_WORLD;
    }

    sleep(1);

    RESET_GRAPHICS_MODES;
    MOVE_CURSOR_TO_POS(0, 0);
    ERASE_SCREEN;

    resetConsole();
}