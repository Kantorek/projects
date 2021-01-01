#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int diceRoll()
{
    return rand() % 6 + 1;
}

void loadingRolls()
{
    printf("\nRolling the dice...\n");
    Sleep(500);
    printf(".\n");
    Sleep(500);
    printf(".\n");
    Sleep(500);
    printf(".\n\n");
    Sleep(500);
}

int main()
{
    int roll1, roll2, roll3;
    int sum1, sum2;
    char enter = 0;
    char bet;

    srand ( time(NULL));

    printf("Losowanko!\nPress enter to start ");
    while (enter != '\r' && enter != '\n')
            enter = getchar();

    loadingRolls();

    roll1 = diceRoll();
    roll2 = diceRoll();
    roll3 = diceRoll();

    sum1 = roll1 + roll2 + roll3;

    printf("The sum is: %d\n", sum1);
    printf("The next sum will be greater, lower or the same? (g/l/s)\n");
    scanf(" %s", &bet);
    bet = tolower(bet);

    loadingRolls();

    roll1 = diceRoll();
    roll2 = diceRoll();
    roll3 = diceRoll();

    sum2 = roll1 + roll2 + roll3;

    if(sum2 > sum1 && bet == 'g')
        printf("U win, the sum is greater");
    else if(sum2 == sum1 && bet == 's')
        printf("U win, the sum is the same");
    else if(sum2 < sum1 && bet == 'l')
        printf("U win, the sum is lower");
    else
        printf("U lose, the next sum is %d", sum2);

    return 0;
}
