#include <stdio.h>
#include <cs50.h>

int main(void) {
    // Get the initial population size from the user
    int start_size;

    do {
        start_size = get_int("Start size: ");
    }
    // Ensure that the start size is at least 9
    while (start_size < 9);

    // Get the final population size from the user
    int end_size;
    do {
        end_size = get_int("End size: ");
    }
    // Ensure that the end size is at least as large as the start size
    while (end_size < start_size);

    // Calculate the number of years it takes for the population to grow to the end size
    int years = 0;
    while (start_size < end_size) {
        // Update the population: n/3 new llamas are born, n/4 llamas die
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years++;
    }
    
    printf("Years: %i\n", years);
}
