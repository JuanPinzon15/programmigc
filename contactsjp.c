/*******************
 * FILENAME: contactsjp.c

 * YOUR NAME: Juan Pinzon 

 * DESCRIPTION: This program allow the user to add contacts, list them, search by name, sort the list, and exit the program.

*********************/
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 20
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15

// Function prototypes (declarations)
void add_contact(char names[][MAX_NAME_LEN], char phones[][MAX_PHONE_LEN], int ages[], int *count);
void list_contacts(char names[][MAX_NAME_LEN], char phones[][MAX_PHONE_LEN], int ages[], int count);
void find_contact(char names[][MAX_NAME_LEN], char phones[][MAX_PHONE_LEN], int ages[], int count);

// Function to wait for user input after invalid option
void pressanykey() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Invalid choice. Press any key to continue...");
    getchar(); // Wait for user input
    printf("\n\n\n");
}

//Entry point of the program
int main(void) {
    // Arrays to store contact information
    char namelist[MAX_CONTACTS][MAX_NAME_LEN];
    char phonelist[MAX_CONTACTS][MAX_PHONE_LEN];
    int agelist[MAX_CONTACTS];
    int contact_count = 0;
    int choice;

    // Menu loop
    do {
        // Display menu options
        printf("\n======================\nContact Manager\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Search by name\n\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Get user choice

        // Execute function based on choice
        switch (choice) {
            case 1:
                add_contact(namelist, phonelist, agelist, &contact_count);
                break;
            case 2:
                list_contacts(namelist, phonelist, agelist, contact_count);
                break;
            case 3:
                find_contact(namelist, phonelist, agelist, contact_count);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                pressanykey();  // Handle invalid input
        }
    } while (choice != 0);  // Loop until user chooses to exit

    return 0;
}

// -----------------------------
// Function Implementations
// -----------------------------

// Function to add a new contact to the list
void add_contact(char names[][MAX_NAME_LEN], char phones[][MAX_PHONE_LEN], int ages[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    // Temporary variables to store input before copying
    char temp_name[MAX_NAME_LEN];
    char temp_phone[MAX_PHONE_LEN];
    int temp_age;

    // Prompt the user for the contact's name
    printf("Enter name: ");
    scanf(" %[^\n]", temp_name); // Reading string with spaces for the name

    // Prompt the user for the contact's phone
    printf("Enter phone number: ");
    scanf(" %[^\n]", temp_phone); // Reading string with spaces for the phone number

    // Prompt the user for the contact's age
    printf("Enter age: ");
    scanf("%d", &temp_age); // Reading age as an integer

    // Store inputs into the arrays using strcpy
    strcpy(names[*count], temp_name);
    strcpy(phones[*count], temp_phone);
    ages[*count] = temp_age; // Direct assignment for age

    (*count)++; // Increment the contact count
    printf("Contact added successfully!\n");
}

// Function to list all contacts
void list_contacts(char names[][MAX_NAME_LEN], char phones[][MAX_PHONE_LEN], int ages[], int count) {
    // If no contacts to show
    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    // Display each contact
    printf("\nContact List:\n");
    for (int i = 0; i < count; i++) {
        // Using pointer arithmetic for ages as a variation
        printf("Name: %s, Phone: %s, Age: %d\n", names[i], phones[i], *(ages + i));
    }
}

// Function to search contacts
void search_contacts(char names[][MAX_NAME_LEN], char phones[][MAX_PHONE_LEN], int ages[], int count) {
    // If no contacts available
    if (count == 0) {
        printf("No contacts to search.\n");
        return;
    }
  
    // Prompt for the name to search
    char search_name[MAX_NAME_LEN];
    printf("Enter the name to search: ");
    scanf(" %[^\n]", search_name);

    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], search_name) == 0) {
            printf("Contact found: Name: %s, Phone: %s, Age: %d\n", names[i], phones[i], ages[i]);
            return;
        }
    }

    // If contact is not found
    printf("Contact not found.\n");
}

// Function to sort contacts
void sort_contacts(char names[][MAX_NAME_LEN], char phones[][MAX_PHONE_LEN], int ages[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) { // Compare names alphabetically
                // Swap names
                char temp_name[MAX_NAME_LEN];
                strcpy(temp_name, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp_name);

                // Swap phones
                char temp_phone[MAX_PHONE_LEN];
                strcpy(temp_phone, phones[j]);
                strcpy(phones[j], phones[j + 1]);
                strcpy(phones[j + 1], temp_phone);

                // Swap ages
                int temp_age = ages[j];
                ages[j] = ages[j + 1];
                ages[j + 1] = temp_age;
            }
        }
    }
}
