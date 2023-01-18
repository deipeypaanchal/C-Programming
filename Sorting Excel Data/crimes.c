/*

>> This program is designed to sort the states by rate of all violent crimes, in descending order
>> User is prompted for an input file to collect the data which is further sorted in the output file

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100

// Creating a structure called state
struct state
{
	char name[50];
	int population;
	double assault, murder, rape, robbery;
};
// Creating a structure called total
struct total
{
	double final;
};
struct total crime[51];

void sort_states(struct state list[], int n);

// Main function
int main(void)
{

	FILE *fptr1, *fptr2;

	// Initializing char value for the file names
	char input[150], output[150] = "sorted_";

	int n = 0, i = 0;

	// Prompting user for the input file name
	printf("Enter input file name: ");
	scanf("%s", input);

	// Opening the file to read the data
	fptr1 = fopen(input, "r");

	// Printing error if the file is NULL (does not exist)
	if (fptr1 == NULL)
	{
		printf("Error in opening file\n");
		return 1;
	}

	// Concatenating "sorted_" to the existing input file name
	strcat(output, input);

	// Printing error if the file is NULL
	fptr2 = fopen(output, "w");
	if (fptr2 == NULL)
	{
		printf("Error in opening file\n");
		return 1;
	}

	struct state sList[MAX_LEN + 1];

	// Using fscanf and fprintf in while loop to read and write data
	while (EOF != fscanf(fptr1, "%[^,], %d, %lf, %lf, %lf, %lf\n", sList[n].name, &sList[n].population, &sList[n].assault, &sList[n].murder, &sList[n].rape, &sList[n].robbery))
	{
		n++;
	}

	// Using void function to sort the states
	sort_states(sList, n);

	while (i < n)
	{
		fprintf(fptr2, "%s, %d, %.1lf, %.1lf, %.1lf, %.1lf\n", sList[i].name, sList[i].population, sList[i].assault, sList[i].murder, sList[i].rape, sList[i].robbery);
		i++;
	}

	// Printing output file name and closing the opened files
	printf("Output file name: %s\n", output);
	fclose(fptr1);
	fclose(fptr2);

	return 0;
}

// Void function that sorts the states by rate of all violent crimes
// This function includes a while and for loop to get the desired results
void sort_states(struct state list[], int n)
{
	int i = 0, j;

	while (i < n)
	{
		crime[i].final = list[i].assault + list[i].murder + list[i].rape + list[i].robbery;
		i++;
	}

	struct state s;
	struct total c;

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (crime[i].final < crime[j].final)
			{

				s = list[i];
				list[i] = list[j];
				list[j] = s;

				c = crime[i];
				crime[i] = crime[j];
				crime[j] = c;
			}
		}
	}
}
