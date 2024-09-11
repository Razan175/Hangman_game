/*The hangman game is one of the most famous games played on computers. The Rules of the game are as follows:

1-There is given a word with omitted characters and you need to guess the characters to win the game.
2-Only 3 chances are available and if you win the Man survives or Man gets hanged.
*/
// PROJ1

#include <time.h>
#include <stdlib.h>
#include <string.h>


#include "proj.c"

#define WORDS_COUNT 4

struct WordWithHint {  
  char* word;
  char* hint;
};

enum bool guessed[26];

int main() {
    struct WordWithHint arr[WORDS_COUNT] = {
    	{"Madrid", "Capital of a country in Europe"},
    	{"Spoon", "Something we use while eating"},
    	{"University", "A place where we hate to go :((("},
    	{"Youtube", "A website we use to watch videos"},
    };

    puts("HANGMAN GAME ^_^");

    srand(time(0));
    struct WordWithHint ranWord =  arr[rand() % WORDS_COUNT];
    int wordSize = strlen(ranWord.word);

    printf("We will help you with a hint : %s",ranWord.hint);
    
    int trials = 3;
    char gLetter;
    int flag;

    while(trials)
    {
        puts("");
        DrawHangman(trials);
        DisplayWord(ranWord.word, guessed);
        
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
            if (toupper(ranWord.word[i]) == gLetter)
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
                if (guessed[toupper(ranWord.word[i]) - 'A'] == false)
                {
                     printf("Nice guess! %i trial(s) left", trials);
                    break;
                }
                else if (i == wordSize - 1)
                {
                    trials = 0;
                    puts("Yaaaaaaaayy , you guessed it right");
                    printf("The word is: %s\n", ranWord.word);
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