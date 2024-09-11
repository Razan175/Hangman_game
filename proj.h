#include <stdio.h>
#include <ctype.h>

enum bool
{ 
    false, 
    true 
};

void DrawHangman(int);
void DisplayWord(const char [], const enum bool []);
