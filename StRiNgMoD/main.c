#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char string[100];
    char sTrInG[100];
    int lastLetter = 0;

    printf("Hi! \nEnter phrase to modify: \n");
    fgets(string, 100, stdin);

    for(i = 0; i < sizeof(string); i++)
    {
        if(string[i] == ' ')
        {
            sTrInG[i] = string[i];
            continue;
        }
        else if(lastLetter % 2 == 0)
        {
            sTrInG[i] = toupper(string[i]);
            lastLetter++;
        }
        else if(lastLetter % 2 == 1)
        {
            sTrInG[i] = tolower(string[i]);
            lastLetter++;
        }
    }

    printf("\nNeW fUnNy PhRaSe: \n");
    puts(sTrInG);

    return 0;
}
