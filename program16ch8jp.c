/*******************
 * FILENAME: program16ch8jp.c

 * YOUR NAME: Juan Pinzon

 * DESCRIPTION: This program tests wether two words are anagrams.

*********************/
#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26  // 26 letters in the alphabet

void read_word(int counts[ALPHABET_SIZE]);
int is_anagram(int counts[ALPHABET_SIZE]);

int main(void) {
    int letter_counts[ALPHABET_SIZE] = {0};  // Array to track letter occurrences

    printf("Enter first word: ");
    read_word(letter_counts);  // Increment letter counts

    printf("Enter second word: ");
    read_word(letter_counts);  // Decrement letter counts

    // Check if the array now contains only zeros
    if (is_anagram(letter_counts))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}
// Reads a word and updates letter frequency array
void read_word(int counts[ALPHABET_SIZE]) {
    char ch;
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {  // Ignore non-alphabetic characters
            ch = tolower(ch);  // Convert to lowercase
            counts[ch - 'a']++;  // Increment count for this letter
        }
    }
}

// Checks if all elements in the array are zero
int is_anagram(int counts[ALPHABET_SIZE]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (counts[i] != 0) // If any count is not zero, words are not anagrams
            return 0;  // Not an anagram
    }
    return 1;  // Anagram
}
