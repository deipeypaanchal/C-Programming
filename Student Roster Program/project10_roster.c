/*
This file which contains the main function
Header files are imported
*/

#include <stdio.h>
#include "student.h"
#include "readline.h"

// Main function
int main(void)
{
    char code;
    struct student *student_list = NULL;
    printf("Operation Code: a for adding to the list, s for searching"
           ", p for printing the list; q for quit.\n");
    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        // Skips to end of line
        while (getchar() != '\n');
        //Switch cases for the program
        switch (code)
        {
        case 'a':
            printf("==========================================================\n");
            student_list = add(student_list);
            break;
        case 's':
            printf("==========================================================\n");
            search(student_list);
            break;
        case 'p':
            printf("==========================================================\n");
            print_list(student_list);
            break;
        case 'q':
            printf("==========================================================\n");
            clear_list(student_list);
            return 0;
        case 'r':
            printf("==========================================================\n");
            student_list = remove_from_list(student_list);
            break;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }
}
