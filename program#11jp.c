/*******************
 * FILENAME: program#11jp.c

 * YOUR NAME: Juan Pinzón

 * DESCRIPTION: This program takes a first name and last name entered by the user and displays the last name, a comma, and the first initial, followed by a period

*********************/
#include <stdio.h>

int main() {
    char ch, firstInitial, lastName[100];
    int i = 0;

    // Ask user for the first and last name
    printf("Enter a first and last name: ");
    
    // Read first name and store its initial
    while ((ch = getchar()) == ' ');  // Skip any leading spaces
    firstInitial = ch;  // Take the first letter of the first name as the initial
    while ((ch = getchar()) != ' ' && ch != '\n');  // Ignore rest of the first name

    // Read last name
    i = 0;
    while ((ch = getchar()) == ' ');  // Skip any leading spaces
    while (ch != '\n') {  // Read until newline
        lastName[i++] = ch;
        ch = getchar();
    }
    lastName[i] = '\0';  // End last name string with a null character

    // Print the last name followed by the initial of the first name
    printf("%s, %c.\n", lastName, firstInitial);

    return 0;
}
