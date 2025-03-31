/*******************
 * FILENAME: program#6ch9jp.c

 * YOUR NAME: Juan Pinzon

 * DESCRIPTION: This program ask the user to enter a value for x, then calls the function to compute the value of the polynomial, and then displays the value returned by the function.
*********************/
#include <stdio.h>

// Recursive function to calculate x^n
int power(int x, int n) {
    if (n == 0) 
        return 1;
    else
        return x * power(x, n - 1);
}

// Function to evaluate the polynomial
int polynomial(int x) {
    return (3 * power(x, 5)) + 
           (2 * power(x, 4)) - 
           (5 * power(x, 3)) - 
           (power(x, 2)) + 
           (7 * x) - 6;
}

int main() {
    int x;
    
    // Get input from user
    printf("Enter a value for x: ");
    scanf("%d", &x);

    // Compute and display the polynomial result
    printf("The value of the polynomial is: %d\n", polynomial(x));

    return 0;
}
