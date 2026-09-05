#include <stdio.h>      // Allows use of printf, fgets, etc.
#include <string.h>     // Allows use of strcmp and strstr

int main() {
    char input[256];    // Buffer to store user input (up to 255 chars + null terminator)

    // Infinite loop that keeps asking for input
    while (1) {

        printf("Enter something: ");   // Prompt the user

        // Use fgets to read a line of input from stdin
        // fgets stores the newline character, so the string may end with '\n'
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // If fgets fails (e.g., EOF), break the loop
            break;
        }

        // Remove the newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Check if the user typed "exit"
        // strcmp returns 0 when strings are equal
        if (strcmp(input, "exit") == 0) {
            break;   // End the loop and exit the program
        }

        // Check if the input contains the word "hello"
        // strstr returns a pointer to the first occurrence of "hello", or NULL if not found
        if (strstr(input, "hello") != NULL) {
            printf("Hi there! Nice to see you.\n");
        }
        else {
            // Echo the user's input back to them
            printf("You said: %s\n", input);
        }
    }

    // Program ends here
    printf("Goodbye!\n");
    return 0;
}
