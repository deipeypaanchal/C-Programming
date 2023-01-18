#include "student.h"    // Importing student.h
#include "readline.h"   // Importing readline.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student *add(struct student *list)
{
    // malloc is used to store the new student info
    struct student *new_node = malloc(sizeof(struct student));

    // Storing the details specific details that include first name, last name, email, instrument and group
    printf("Enter student last name: ");
    read_line(new_node->first, NAME_LEN);
    printf("Enter student first name: ");
    read_line(new_node->last, NAME_LEN);
    printf("Enter email address: ");
    read_line(new_node->email, NAME_LEN);
    printf("Enter instrument: ");
    read_line(new_node->instrument, NAME_LEN);
    printf("Enter group: ");
    read_line(new_node->group, NAME_LEN);

    // If the list is Null...
    if (list == NULL)
    {
        new_node->next = NULL;
        list = new_node;
    }
    // else loop with *temporary to interate through
    else
    {
        struct student *temporary = list;
        while (1)
        {
            // Comparing to avoid any duplicates and stopping the user from doing that by printing a message
            if (strcmp(new_node->email, temporary->email) == 0 && strcmp(new_node->last, temporary->last) == 0)
            {
                printf("\nUser Already Exists!\n");
                free(new_node);
                return list;
            }
            // if statement to break at the last element of the linked list
            if (temporary->next == NULL)
            {
                break;
            }
            temporary = temporary->next;
        }
        new_node->next = NULL;
        temporary->next = new_node;
    }
    return list;
}

void search(struct student *list)
{
    char first_search[NAME_LEN];
    char last_search[NAME_LEN];

    printf("Enter First Name: ");
    read_line(first_search, NAME_LEN);
    printf("Enter Last Name: ");
    read_line(last_search, NAME_LEN);

    struct student *temporary = list;
    int result = 0;
    while (1)
    {
        // If statement to print matches
        if (strcmp(first_search, temporary->first) == 0 && strcmp(last_search, temporary->last) == 0)
        {
            printf("%s\t%s\t%s\t%s\t%s\n", temporary->first, temporary->last, temporary->email, temporary->instrument, temporary->group);
            result++;
        }
        // If statement to print if the student is not found
        if (temporary->next == NULL)
        {
            if (result == 0)
            {
                printf("Student Not Found\n");
            }
            break;
        }
        temporary = temporary->next;
    }
}

void print_list(struct student *list)
{
    struct student *temporary = list;
    // Printing the list
    while (temporary != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\n", temporary->first, temporary->last, temporary->email, temporary->instrument, temporary->group);
        temporary = temporary->next;
    }
}

void clear_list(struct student *list)
{
    struct student *temporary = list;
    // Clearing the list and freeing the memory if it doesn't exist
    if (temporary->next == NULL)
    {
        free(temporary);
    }
    else
    {
        clear_list(temporary->next);
        free(temporary);
    }
}

struct student *remove_from_list(struct student *list)
{
    struct student *new = malloc(sizeof(struct student));
    // Prompting user for the first name, last name, and the email of the student to remove from the list
    printf("Enter student last name: ");
    read_line(new->first, NAME_LEN);
    printf("Enter student first name: ");
    read_line(new->last, NAME_LEN);
    printf("Enter student email: ");
    read_line(new->email, NAME_LEN);
    int c = 0;
    // Creating two pointers ptr and temporary...
    struct student *ptr = list;
    struct student *temporary;
    // If the first value is NULL which means the list is empty, program would return NULL
    if(ptr == NULL){
        printf("No students in the list\n");
        return NULL;
    }
    // For loop is used to iterate through the list till it reaches the last node with the NULL value
    for (ptr = list, temporary = list; ptr != NULL;){
        // If the user entry matches with the existing data in the linked list, we would remove it
        // String compare is used for that purpose
        if(strcmp(new->first, ptr->first) == 0 && strcmp(new->last, temporary->last) == 0 && strcmp(new->email, temporary->email) == 0){
            // We need extra if else statement here to make sure if the head is removed, the program functions correctly
            if(temporary == ptr){
                //list will be temporary->next
                list = temporary->next;
            }
            else{
                //temporary->next will get the same as ptr->next
                temporary->next = ptr->next;
            }
            // Incrementing the counter
            c++;
            // Printing a message with the student's details which is being removed
            printf("%s\t%s\t%s\t%s\t%s is removed.\n", ptr->first, ptr->last, ptr->email, ptr->instrument, ptr->group);
            // and then removing it from the list using free()
            free(ptr);
            return list;
        }
        // When the string compare is not 0 i.e. the student doesn't matches the list, the loop moves forward
        else{
            temporary = ptr;
            ptr = ptr->next;
        }   
    }
    // If the student is not in the list. Printing a message.
    if (c == 0){
        printf("Student not found. Please try again.\n");
        return list;
    }
    //returning the list
    return list;
}
