/*******************
 * FILENAME: program#5jp.c

 * YOUR NAME: Juan Pinzón

 * DESCRIPTION: This program computes the value of a word by summing the values of its letters

*********************/
#include <stdio.h>
#include <ctype.h>  // toupper function

// Function to get the Scrabble value of a letter
int getScrabbleValue(char letter) {
    letter = toupper(letter);  // Convert to uppercase

    if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'L' || letter == 'N' || letter == 'O' || letter == 'R' || letter == 'S' || letter == 'T' || letter == 'U') {
        return 1;
    } else if (letter == 'D' || letter == 'G') {
        return 2;
    } else if (letter == 'B' || letter == 'C' || letter == 'M' || letter == 'P') {
        return 3;
    } else if (letter == 'F' || letter == 'H' || letter == 'V' || letter == 'W' || letter == 'Y') {
        return 4;
    } else if (letter == 'K') {
        return 5;
    } else if (letter == 'J' || letter == 'X') {
        return 8;
    } else if (letter == 'Q' || letter == 'Z') {
        return 10;
    }

    return 0; // For invalid letters (shouldn't happen)
}

int main() {
    char word[100];
    int totalValue = 0;

    // Ask the user for a word
    printf("Enter a word: ");
    scanf("%s", word);

    // Calculate the value of the word
    for (int i = 0; word[i] != '\0'; i++) {
        // Add the Scrabble value of the current letter to the total value
        totalValue += getScrabbleValue(word[i]);
    }
  
    printf("Scrabble value: %d\n", totalValue);

    return 0;
}
