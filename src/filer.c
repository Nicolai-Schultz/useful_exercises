#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read k words from a file and store them in an array
int getwords(FILE *ifp, int k, char **words) {
    if (ifp == NULL) {
        printf("Could not open file\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < k; i++) {
        words[i] = malloc(100 * sizeof(char)); // Allocate memory for each word
        if (fscanf(ifp, "%99s", words[i]) != 1) { // Limit to 99 chars to avoid overflow
            printf("Error reading word %d\n", i + 1);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int main(void) {
    FILE *ifp = fopen("first_file.txt", "r");
    if (ifp == NULL) {
        printf("Could not open file\n");
        return EXIT_FAILURE;
    }

    int num_words = 2; // Number of words to read
    char **array_of_words = malloc(num_words * sizeof(char *)); // Allocate memory for the array of pointers

    if (getwords(ifp, num_words, array_of_words) == EXIT_FAILURE) {
        fclose(ifp);
        free(array_of_words);
        return EXIT_FAILURE;
    }

    // Print the words
    printf("Words read from file:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", array_of_words[i]);
        free(array_of_words[i]); // Free memory for each word
    }

    free(array_of_words); // Free memory for the array of pointers
    fclose(ifp); // Close the file

    return 0;
}