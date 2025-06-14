
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "Display.h"

#define WORDS_COUNT 100
#define MAX_WORD_SIZE 10
#define MAX_HINT_SIZE 100

struct WordWithHint{  
  char word[MAX_WORD_SIZE];  
  char hint[MAX_HINT_SIZE];
};

enum bool guessed[26];

int main() {
    puts("HANGMAN GAME ^_^");

    FILE* wordFile = fopen("../Words_File/random_words_with_hints.txt","r");

    if (!wordFile)
    {
        perror("Could not open file\n");
        return 1;
    }
    srand(time(0));
    int n = rand() % WORDS_COUNT + 1;

    struct WordWithHint randWord;
    
    for (int i = 0; i < n; i++)
        fscanf(wordFile,"%s %[^\n]s",randWord.word,randWord.hint);

    fclose(wordFile);
    int wordSize = strlen(randWord.word);
    printf("We will help you with a hint : %s",randWord.hint);
    
    int trials = 3;
    char gLetter;
    int flag;

    while(trials)
    {
        puts("");
        DrawHangman(trials);
        DisplayWord(randWord.word, guessed);
        
        puts("Enter a guess:");

        do
            scanf("%c", &gLetter); 
        while (gLetter == '\n');
        
        gLetter = toupper(gLetter);

        while (!isalpha(gLetter) || (guessed[gLetter - 'A']))
        {
            if (!isalpha(gLetter))
                puts("you entered a non-alphabetic character, try again:");
            else
                puts("Repeated, Try again:");

            do
                scanf("%c", &gLetter); 
            while (gLetter == '\n');
            gLetter = toupper(gLetter);
        }
        
        flag = 0;
        
        for (int i = 0; i < wordSize; i++)
        {
            if (toupper(randWord.word[i]) == gLetter)
            {
                flag = 1;
                break;
            }   
        }

        guessed[gLetter - 'A'] = true;
        

        if (flag)
        {   
           for (int i = 0; i < wordSize; i++)
            {
                if (guessed[toupper(randWord.word[i]) - 'A'] == false)
                {
                     printf("Nice guess! %i trial(s) left", trials);
                    break;
                }
                else if (i == wordSize - 1)
                {
                    trials = 0;
                    puts("Yaaaaaaaayy , you guessed it right");
                    printf("The word is: %s\n", randWord.word);
                }
            }
        }
        else
        {
            trials--;

            if (trials == 0)
                puts("You ran out of trials");
            else
                printf("Wrong guess, %i trial(s) left", trials);
        }        
    }
}