#include <stdio.h>
#include <cs50.h>

// Function prototypes
int is_valid(long number);
int get_length(long number);
long get_prefix(long number, int digits);

int main(void) {
    // Prompt the user for a credit card number
    long number = get_long("Number: ");
    
    // Check if the card is valid using the Luhn algorithm
    if (!is_valid(number)) {
        printf("INVALID\n");
        return 0;
    }

    // Determine the length of the number
    int length = get_length(number);
    
    // Extract the prefix based on the length of the card
    long prefix;
    if (length == 13) {
        prefix = get_prefix(number, 1); // VISA (13 digits)
    } else if (length == 15) {
        prefix = get_prefix(number, 2); // AMEX (15 digits)
    } else if (length == 16) {
        prefix = get_prefix(number, 2); // MASTERCARD (16 digits)
    } else {
        printf("INVALID\n");
        return 0;
    }

    // Check the starting digits to determine the card type
    if (length == 15 && (prefix == 34 || prefix == 37)) {
        printf("AMEX\n");
    }
    else if (length == 16 && (prefix >= 51 && prefix <= 55)) {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && prefix / 10 == 4) {
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    }
}

// Function to check if the card number is valid using the Luhn algorithm
int is_valid(long number) {
    int sum = 0;
    int should_double = 0; // 0 for false, 1 for true

    // Loop through the digits of the number from right to left
    while (number > 0) {
        int digit = number % 10;  // Get the last digit
        number /= 10;  // Remove the last digit

        if (should_double) {
            digit *= 2;
            // If the product is greater than 9, subtract 9 to get the sum of digits
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        should_double = !should_double;  // Alternate between doubling and not doubling
    }

    // Return true if the sum modulo 10 is 0 (valid), false otherwise
    return sum % 10 == 0;  // Simplified return statement
}

// Function to calculate the length of the card number
int get_length(long number) {
    int length = 0;
    while (number > 0) {
        number /= 10;
        length++;
    }
    return length;
}

// Function to extract the first 'digits' number of digits from the card number
long get_prefix(long number, int digits) {
    long divisor = 1;
    for (int i = 0; i < digits; i++) {
        divisor *= 10;
    }
    return number / divisor;
}
