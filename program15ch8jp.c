/*******************
 * FILENAME: program15ch8jp.c

 * YOUR NAME: Juan Pinzon

 * DESCRIPTION: This program encrypts a message using a Caesar cipher.

*********************/
#include <stdio.h>
#include <ctype.h>   // For isupper() and islower() functions
#include <string.h>   // For strcspn() function

// Function prototype for the encryption function
void encrypt(char *message, int shift);

int main() {
    char message[81];  // Array to store the message (max 80 characters + null terminator)
    int shift;         // To store the shift amount

    // Prompt the user to enter a message to be encrypted
    printf("Enter message to be encrypted: ");
    fgets(message, sizeof(message), stdin); 

    // Remove the newline character that fgets() might store at the end of the input
    message[strcspn(message, "\n")] = '\0';

    // Prompt the user to enter the shift amount between 1 and 25
    printf("Enter shift amount (1 - 25): ");
    scanf("%d", &shift);

    // Call the encrypt function to modify the message using the Caesar cipher
    encrypt(message, shift);

    // Display the encrypted message to the user
    printf("Encrypted message: %s\n", message);
    
    return 0;  // The program ended
}

// Function to encrypt a message using the Caesar cipher
void encrypt(char *message, int shift) {
    // Loop through each character in the message until the null terminator is reached
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];  // Store the current character for processing

        // Check if the character is a letter
        if (isupper(ch)) { // Encrypt uppercase letters
            message[i] = ((ch - 'A') + shift) % 26 + 'A';
        else if (islower(ch)) { // Encrypt lowercase letters
            message[i] = ((ch - 'a') + shift) % 26 + 'a';
        }
    }
}
