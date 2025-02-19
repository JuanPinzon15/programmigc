#include <stdio.h>

int main() {
    int area_code;

    // Prompt user for area code input
    printf("Enter the area code: ");
    scanf("%d", &area_code);

    switch (area_code) {
        case 229: printf("Major city: Albany\n");
                  break;
        case 404:
        case 470:
        case 678:
        case 770: printf("Major city: Atlanta\n");
                  break;
        case 478: printf("Major city: Macon\n");
                  break;
        case 706:
        case 762: printf("Major city: Columbus\n");
                  break;
        case 912: printf("Major city: Savannah\n");
                  break;
        default:  printf("Area code not recognized\n");
                  break;
    }

    return 0;
}
