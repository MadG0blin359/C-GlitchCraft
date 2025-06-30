#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *write_file(void *arg) {
    FILE *file = fopen("text.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        pthread_exit(NULL);
    }

    char *text = "They must hunger in winter that will not work in summer";
    fprintf(file, "%s", text);
    fclose(file);

    printf("Thread One: Created 'text.txt' and wrote text:\n%s\n", text);

    pthread_exit(NULL);
}

void capitalize(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (i == 0 || str[i - 1] == ' ') {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] -= 32;
            }
        }
        if ((i + 1 == len || str[i + 1] == ' ') && str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

void *capitalize_file(void *arg) {
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        pthread_exit(NULL);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    capitalize(buffer);

    file = fopen("text_capitalized.txt", "w");
    if (file == NULL) {
        perror("Error creating capitalized file");
        pthread_exit(NULL);
    }

    fprintf(file, "%s", buffer);
    fclose(file);

    printf("Thread Two: %s\n", buffer);

    pthread_exit(NULL);
}

void reverse_word(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverse_words(char *str) {
    char *start = str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i + 1] == '\0') {
            reverse_word(start, (str[i + 1] == '\0') ? &str[i] : &str[i - 1]);
            start = &str[i + 1];
        }
    }
}

void *reverse_file(void *arg) {
    FILE *file = fopen("text_capitalized.txt", "r");
    if (file == NULL) {
        perror("Error opening capitalized file");
        pthread_exit(NULL);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    reverse_words(buffer);

    file = fopen("text_reversed.txt", "w");
    if (file == NULL) {
        perror("Error creating reversed file");
        pthread_exit(NULL);
    }

    fprintf(file, "%s", buffer);
    fclose(file);

    printf("Thread Three: %s\n", buffer);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, write_file, NULL);
    pthread_join(thread1, NULL);

    pthread_create(&thread2, NULL, capitalize_file, NULL);
    pthread_join(thread2, NULL);

    pthread_create(&thread3, NULL, reverse_file, NULL);
    pthread_join(thread3, NULL);

    printf("All threads completed.\n");
    return 0;
}

