/*
Author: Deepey Panchal
U-Number: U80305771

This C program stimulates a simple dice game. It is a two players game.
After throwing the dice, the player whose value is greater wins the round.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // srand() function generates different sequences of random numbers
    srand(time(NULL));

    int num1, num2;

    // Initializing int values for lower and upper number of the dice
    int lower = 1;
    int upper = 6;

    // This code below generates the dice number
    num1 = (rand() % (upper - lower + 1)) + lower;
    num2 = (rand() % (upper - lower + 1)) + lower;

    // if-else statement is used to print the game results
    if (num1 > num2)
    {
        printf("Player 1's number is %d, Player 2's number is %d. Player 1 wins!\n", num1, num2);
    }
    else if (num1 < num2)
    {
        printf("Player 1's number is %d, Player 2's number is %d. Player 2 wins!\n", num1, num2);
    }
    else
    {
        printf("Player 1's number is %d, Player 2's number is %d. The game is drawn!\n", num1, num2);
    }
    return 0;
}