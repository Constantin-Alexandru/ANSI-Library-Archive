#include <stdio.h>


#ifdef _WIN32
    #include <Windows.h>
#else 
    #include <unistd.h>
#endif

#include "../ansi_lib.h"

#define HELLO_WORLD printf("Hello, World!")
#define HELLO_WORLDn printf("Hello, World!\n")
#define newline printf("\n")

/**
 * NOTE: If buffer overflows, the ERASE functions doesn't erase prior to the last shown line.
 * 
 */

int main()
{

#ifdef _WIN32
    setupConsole();
#endif

    /* TESTING GRAPHIC MODE */

    printf("======== TESTING GRAPHIC MODE ========\n");

    SET_GRAPHIC_MODE(BOLD_MODE);

    printf("BOLD");
    newline;

    SET_GRAPHIC_MODE(BOLD_MODE_RESET);

    SET_GRAPHIC_MODE(DIM_MODE);

    printf("DIM");
    newline;

    SET_GRAPHIC_MODE(DIM_MODE_RESET);

    SET_GRAPHIC_MODE(ITALIC_MODE);

    printf("ITALIC");
    newline;

    SET_GRAPHIC_MODE(ITALIC_MODE_RESET);

    SET_GRAPHIC_MODE(UNDERLINE_MODE);

    printf("UNDERLINE");
    newline;

    SET_GRAPHIC_MODE(UNDERLINE_MODE_RESET);

    SET_GRAPHIC_MODE(BLINKING_MODE);

    printf("BLINKING");
    newline;

    SET_GRAPHIC_MODE(BLINKING_MODE_RESET);

    SET_GRAPHIC_MODE(INVERSE_MODE);

    printf("INVERSE");
    newline;

    SET_GRAPHIC_MODE(INVERSE_MODE_RESET);

    SET_GRAPHIC_MODE(HIDDEN_MODE);

    printf("HIDDEN");
    newline;

    SET_GRAPHIC_MODE(HIDDEN_MODE_RESET);

    SET_GRAPHIC_MODE(STRIKETHROUGH_MODE);

    printf("STRIKETHROUGH");
    newline;

    SET_GRAPHIC_MODE(STRIKETHROUGH_MODE_RESET);

    SET_GRAPHIC_MODE(DOUBLE_UNDERLINE_MODE);

    printf("DOUBLE_UNDERLINE");
    newline;

    SET_GRAPHIC_MODE(DOUBLE_UNDERLINE_MODE_RESET);

    resetConsole();
}