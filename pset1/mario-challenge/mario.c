#include <cs50.h>
#include <stdio.h>

int main(void) {
    // Prompt the user for the height of the pyramid
    int height;

    do {
        height = get_int("Height: "); // Get an integer input from the user
    }
    while (height < 1 || height > 8); // Ensure the height is between 1 and 8

    // Generate the two pyramids
    for (int i = 1; i <= height; i++) {
        // Print spaces for the left pyramid
        for (int j = i; j < height; j++) {
            printf(" ");
        }

        // Print the left pyramid hashes
        for (int j = 1; j <= i; j++) {
            printf("#");
        }

        // Print the space between the two pyramids
        printf("  ");

        // Print the right pyramid hashes
        for (int j = 1; j <= i; j++) {
            printf("#");
        }

        // Move to the next line for the next row of hashes
        printf("\n");
    }

    return 0;
}