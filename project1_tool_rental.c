/*
Author: Deepey Panchal
U-Number: U80305771

This program calculates and prints the charges of a tool rental company.
The user should enter the selection, hours, and print the charge.
There is a minimum fee for up to four hours and an additional hourly fee if that limit exceeds.
There is also a maximum charge for rental per day.
*/

#include <stdio.h>

int main()
{
    // Declaring the variables as int data type

    int tool, hours, amount, hourlyWage, minimum, maximum, revisedM, adjustedM;

    printf("Please select from the following menu: 1.Electric Pressure Washer 2.Commercial Carpet Extractor, 3.Chainsaw, 4.Drain Cleaner.\n");

    // Prompting user to enter their tool selection from the menu
    printf("Enter tool selection: ");
    scanf("%d", &tool);

    // This if-else statement helps to terminate program if the user input is invalid
    if (tool > 4 || tool < 1)
    {
        printf("Invalid input. The input should be in the range of 1 to 4.\n");
    }
    else
    {
        // Prompting user to enter the number of hours
        printf("Enter hours rented: ");
        scanf("%d", &hours);

        // Switch case is used here because each tool has different four hour minimum, per day maximum, and hourly charges
        switch (tool)
        {
        // Washer
        case 1:
            hourlyWage = 4;
            minimum = 28;
            maximum = 41;
            break;
        // Commercial Carpet Extractor
        case 2:
            hourlyWage = 3;
            minimum = 25;
            maximum = 35;
            break;
        // Chainsaw
        case 3:
            hourlyWage = 5;
            minimum = 32;
            maximum = 48;
            break;
        // Drain Cleaner
        case 4:
            hourlyWage = 6;
            minimum = 51;
            maximum = 78;
            break;
        // Do nothing
        default:
            break;
        }

        // Customer would be charged the four hour minimum amount if they use it for 0 - 4 hours
        if (hours <= 4)
        {
            amount = minimum;
        }
        // If customer uses it for 4 - 24 hours, the amount won't exceed per day maximum
        else if (hours > 4 && hours < 24)
        {
            amount = (minimum + ((hours - 4) * hourlyWage));
            if (amount > maximum)
            {
                amount = maximum;
            }
        }
        // If the customer uses it for more than 24 hours, the amount will be calculated precisely considering per day maximum charge
        else if (hours >= 24)
        {
            revisedM = (hours % 24) * hourlyWage;
            if (revisedM >= maximum)
            {
                adjustedM = maximum;
            }
            else
            {
                adjustedM = (hours % 24) * hourlyWage;
            }
            amount = ((hours / 24) * maximum) + (adjustedM);
        }
        printf("Amount due ($): %d\n", amount);
    }
    return 0;
}