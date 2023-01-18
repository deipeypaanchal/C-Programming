/*
Author: Deepey Panchal
U-Number: U80305771

In the multiple rounds of the game, player who won the most of the rounds, is the winner of the game.
In case, if both the players won same number of rounds, the game is drawn.
*/

#include <stdio.h>

int main()
{
    char ch, num1ch, num2ch;

    int num1, num2, operator, answer;

    // Prompting user input
    printf("Enter input: ");
    ch = getchar();

    // While loop is used to avoid the program to end after pressing enter
    while (ch != '\n')
    {
        // To skip spaces and take the first non-space character which would be the number 1
        while (ch == ' ')
        {
            ch = getchar();
        }
        num1ch = ch;
        ch = getchar();
        
        // To skip spaces and take the second non-space character which would be the operator
        while (ch == ' ')
        {
            ch = getchar();
        }
        operator = ch;
        ch = getchar();
        
        // To skip spaces and take the third non-space character which would be the number 2
        while (ch == ' ')
        {
            ch = getchar();
        }
        num2ch = ch;
        ch = getchar();
    
        break;
    }

    // Converting ASCII values into decimal integers
    num1 = ((int)num1ch) - 48;
    num2 = ((int)num2ch) - 48;

    // If-else statement to run the mathematical operations
    if (operator== '*' || operator== '+' || operator== '-')
    {
        // Switch
        switch (operator)
        {
        case '*':
            answer = num1 * num2;
            break;

        case '+':
            answer = num1 + num2;
            break;

        case '-':
            answer = num1 - num2;
            break;
        }
    }
    else
    {
        // Return 0 is used to exit the program when the user input includes any unrecognized operator
        printf("Unrecognized operator\n");
        return 0;
    }

    // Printing final output
    printf("Output: %d\n", answer);
    return 0;
}