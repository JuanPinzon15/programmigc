/*******************
 * FILENAME: program#6jp.c

 * YOUR NAME: Juan Pinzón

 * DESCRIPTION: This program prints the values of each data type in bytes

*********************/
#include <stdio.h>

// Print the values of each data type in bytes
int main() {
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    
    return 0;
}
