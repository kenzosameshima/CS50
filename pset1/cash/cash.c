#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void) {
    // Variable to hold the user's input
    float change;

    // Prompt the user for a valid amount of change
    do {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    // Convert the amount to cents (round to avoid floating-point imprecision)
    int cents = round(change * 100);

    // Initialize a variable to count the number of coins
    int coin_count = 0;

    // Array of coin denominations (quarter, dime, nickel, penny)
    int coins[] = {25, 10, 5, 1};

    // Iterate through the coin denominations
    for (int i = 0; i < 4; i++) {
        while (cents >= coins[i]) {
            cents -= coins[i];
            coin_count++;
        }
    }

    printf("%d coins\n", coin_count);
}