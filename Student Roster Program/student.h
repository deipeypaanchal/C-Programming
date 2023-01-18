// student.h is a header file that contains struct student declaration and prototypes for the functions in student.c
// The header file encloses the contents of the header file in an #ifndef-#endif pair to protect the file 

#ifndef STUDENT_H
#define STUDENT_H
#define EMAIL_LEN 100
#define NAME_LEN 30
#define INSTRUMENT_LEN 30
#define GROUP_LEN 30

// struct student
struct student
{
    char first[NAME_LEN + 1];
    char last[NAME_LEN + 1];
    char email[EMAIL_LEN + 1];
    char instrument[INSTRUMENT_LEN + 1];
    char group[GROUP_LEN + 1];
    struct student *next;
};

struct student *add(struct student *list);
struct student *remove_from_list(struct student *list);
void search(struct student *list);
void print_list(struct student *list);
void clear_list(struct student *list);

#endif