#include <cs50.h>
#include <stdio.h>

int main(void) {
    int height;

    // Repeat until the user provides a valid input (between 1 and 8)
    do {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print the pyramid
    for (int i = 1; i <= height; i++) {
        // Print spaces
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }

        // Print hashes
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}