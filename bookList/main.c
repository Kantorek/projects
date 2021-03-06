#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

int main()
{
    int i = 0;
    int number = 0;
    char cnt;
    char title[1000];
    int pages;
    int days;
    int titleLen;
    float pPD;


    FILE * fPointer;
    fPointer = fopen("bookList.txt", "a");
    //fprintf(fPointer, "Nr \t Title \t\t\t\t\t\t Pages \t Days \t Pages per Day \n");
    // printf("Nr \t Title \t\t Pages \t Days \t Pages per Day \n");

    do
    {
        printf("Enter a number of book: ");
        scanf(" %d", &number);
        printf("\n");
        printf("Enter a title: ");
        scanf(" ");
        gets(title);
        titleLen = strlen(title); //13, 21, 29, 37, 45 signs to next \t
        //printf("Title length: %d \n", titleLen);

        printf("\n");
        printf("Enter number of pages: ");
        scanf(" %d", &pages);
        printf("\n");
        printf("Enter number of days: ");
        scanf(" %d", &days);
        printf("\n");


        pPD = (float)pages / (float)days;

        fprintf(fPointer, "%d \t ", number);
        fputs(title, fPointer);

        if(titleLen < 5)
            fprintf(fPointer, "\t\t\t\t\t");
        else if(titleLen < 13)
            fprintf(fPointer, "\t\t\t\t");
        else if(titleLen < 21)
            fprintf(fPointer, "\t\t\t");
        else if(titleLen < 29)
            fprintf(fPointer, "\t\t");
        else if(titleLen < 37)
            fprintf(fPointer, "\t");
        else
            fprintf(fPointer, "");


        fprintf(fPointer, " \t %d \t %d \t %.2f\n", pages, days, pPD);

        printf("Do you want to continue? (y/n)\n");
        scanf(" %s", &cnt);

    }
    while(cnt == 'y');

    fclose(fPointer);

    return 0;
}

