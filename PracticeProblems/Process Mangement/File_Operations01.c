#include <stdio.h> // Standard input/output library for functions like printf, fopen, fclose, etc.
#include <stdlib.h> // Standard library for general utilities like perror, exit, etc.
#include <string.h> // String manipulation library for functions like strlen, etc.
#include <pthread.h> // POSIX threads library for multi-threading functionalities.

// Function executed by Thread One: Writes a specific string to "text.txt".
void *write_file(void *arg) {
    // Open "text.txt" in write mode ('w'). If the file doesn't exist, it's created. If it exists, its content is truncated.
    FILE *file = fopen("text.txt", "w");
    // Check if file opening/creation was successful.
    if (file == NULL) {
        // Print an error message to stderr if the file could not be created.
        perror("Error creating file");
        // Exit the thread, returning NULL as the exit status.
        pthread_exit(NULL);
    }

    // Define the text string to be written to the file.
    char *text = "They must hunger in winter that will not work in summer";
    // Write the defined text string to the file.
    fprintf(file, "%s", text);
    // Close the file, flushing any buffered data.
    fclose(file);

    // Print a message indicating what Thread One has done.
    printf("Thread One: Created 'text.txt' and wrote text:\n%s\n", text);

    // Exit the thread, returning NULL as the exit status.
    pthread_exit(NULL);
}

// Function to capitalize the first and last letter of each word in a string.
void capitalize(char *str) {
    // Get the length of the input string.
    int len = strlen(str);
    // Iterate through each character of the string.
    for (int i = 0; i < len; i++) {
        // Check if the current character is the first character of the string or follows a space.
        // This condition identifies the beginning of a word.
        if (i == 0 || str[i - 1] == ' ') {
            // Check if the current character is a lowercase letter.
            if (str[i] >= 'a' && str[i] <= 'z') {
                // Convert the lowercase letter to uppercase by subtracting 32 (ASCII difference).
                str[i] -= 32;
            }
        }
        // Check if the current character is the last character of the string or precedes a space.
        // This condition identifies the end of a word.
        if ((i + 1 == len || str[i + 1] == ' ') && str[i] >= 'a' && str[i] <= 'z') {
            // Convert the lowercase letter to uppercase by subtracting 32 (ASCII difference).
            str[i] -= 32;
        }
    }
}

// Function executed by Thread Two: Reads "text.txt", capitalizes its content, and writes to "text_capitalized.txt".
void *capitalize_file(void *arg) {
    // Open "text.txt" in read mode ('r').
    FILE *file = fopen("text.txt", "r");
    // Check if file opening was successful.
    if (file == NULL) {
        // Print an error message to stderr if the file could not be opened.
        perror("Error opening file");
        // Exit the thread, returning NULL as the exit status.
        pthread_exit(NULL);
    }

    // Declare a buffer to store the content read from the file.
    char buffer[256];
    // Read a line from the file into the buffer.
    fgets(buffer, sizeof(buffer), file);
    // Close the file.
    fclose(file);

    // Call the capitalize function to modify the content in the buffer.
    capitalize(buffer);

    // Open "text_capitalized.txt" in write mode ('w').
    file = fopen("text_capitalized.txt", "w");
    // Check if file opening/creation was successful.
    if (file == NULL) {
        // Print an error message to stderr if the file could not be created.
        perror("Error creating capitalized file");
        // Exit the thread, returning NULL as the exit status.
        pthread_exit(NULL);
    }

    // Write the capitalized content from the buffer to the new file.
    fprintf(file, "%s", buffer);
    // Close the file.
    fclose(file);

    // Print a message indicating what Thread Two has done, including the capitalized text.
    printf("Thread Two: %s\n", buffer);

    // Exit the thread, returning NULL as the exit status.
    pthread_exit(NULL);
}

// Helper function to reverse a single word within a string.
void reverse_word(char *start, char *end) {
    // Loop while the start pointer is before the end pointer.
    while (start < end) {
        // Swap characters pointed to by start and end.
        char temp = *start;
        *start = *end;
        *end = temp;
        // Move start pointer forward and end pointer backward.
        start++;
        end--;
    }
}

// Function to reverse the order of words in a string.
void reverse_words(char *str) {
    // Pointer to mark the beginning of the current word.
    char *start = str;
    // Iterate through the string until the null terminator is found.
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if the current character is a space or if it's the end of the string.
        // These conditions mark the end of a word.
        if (str[i] == ' ' || str[i + 1] == '\0') {
            // Reverse the word found between 'start' and the character before the space/null terminator.
            // If it's the end of the string, reverse up to the current character (str[i]).
            reverse_word(start, (str[i + 1] == '\0') ? &str[i] : &str[i - 1]);
            // Move 'start' to the beginning of the next word (after the space).
            start = &str[i + 1];
        }
    }
}

// Function executed by Thread Three: Reads "text_capitalized.txt", reverses words, and writes to "text_reversed.txt".
void *reverse_file(void *arg) {
    // Open "text_capitalized.txt" in read mode ('r').
    FILE *file = fopen("text_capitalized.txt", "r");
    // Check if file opening was successful.
    if (file == NULL) {
        // Print an error message to stderr if the file could not be opened.
        perror("Error opening capitalized file");
        // Exit the thread, returning NULL as the exit status.
        pthread_exit(NULL);
    }

    // Declare a buffer to store the content read from the file.
    char buffer[256];
    // Read a line from the file into the buffer.
    fgets(buffer, sizeof(buffer), file);
    // Close the file.
    fclose(file);

    // Call the reverse_words function to modify the content in the buffer.
    reverse_words(buffer);

    // Open "text_reversed.txt" in write mode ('w').
    file = fopen("text_reversed.txt", "w");
    // Check if file opening/creation was successful.
    if (file == NULL) {
        // Print an error message to stderr if the file could not be created.
        perror("Error creating reversed file");
        // Exit the thread, returning NULL as the exit status.
        pthread_exit(NULL);
    }

    // Write the word-reversed content from the buffer to the new file.
    fprintf(file, "%s", buffer);
    // Close the file.
    fclose(file);

    // Print a message indicating what Thread Three has done, including the reversed text.
    printf("Thread Three: %s\n", buffer);

    // Exit the thread, returning NULL as the exit status.
    pthread_exit(NULL);
}

// Main function where the program execution begins.
int main() {
    // Declare three pthread_t variables to store thread IDs.
    pthread_t thread1, thread2, thread3;

    // Create Thread One. It will execute the 'write_file' function.
    pthread_create(&thread1, NULL, write_file, NULL);
    // Wait for Thread One to complete its execution before proceeding.
    pthread_join(thread1, NULL);

    // Create Thread Two. It will execute the 'capitalize_file' function.
    // This thread will run after Thread One has finished writing the file.
    pthread_create(&thread2, NULL, capitalize_file, NULL);
    // Wait for Thread Two to complete its execution before proceeding.
    pthread_join(thread2, NULL);

    // Create Thread Three. It will execute the 'reverse_file' function.
    // This thread will run after Thread Two has finished capitalizing the file.
    pthread_create(&thread3, NULL, reverse_file, NULL);
    // Wait for Thread Three to complete its execution before proceeding.
    pthread_join(thread3, NULL);

    // Print a message indicating that all threads have finished.
    printf("All threads completed.\n");
    // Return 0 to indicate successful program execution.
    return 0;
}