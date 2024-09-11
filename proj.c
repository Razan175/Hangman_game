#include "proj.h"

void DisplayWord(const char word[], const enum bool guessed[]){
    printf("letter Guessed so far: ");
    for (int i = 0; word[i]; i++)
    {
        if (guessed[toupper(word[i]) - 'A'])
            printf("%c", word[i]);
        else
            printf(" _");
    }
    puts("");
    
}

void DrawHangman(int tries) {

    puts("");
    puts("  =======");
    puts("  |     |");

    if (tries < 3)
    {
        puts("  |     o");
        puts("  |    \\|/");
    }
    else
    {    
        puts("  |");
        puts("  |");
    }

    if (tries > 1)
    {
        puts("  |");
        puts("  |");
    }
    else
    {
        puts("  |     |");
        puts("  |    / \\ ");
    }

    puts("=====");
}
