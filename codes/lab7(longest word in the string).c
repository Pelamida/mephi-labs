#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_string[1000];
    char *word;
    char *longest_word = NULL;
    int longest_length = 0;

    fgets(input_string, sizeof(input_string), stdin);
    word = strtok(input_string, " \t\n");
    while (word != NULL) {
        printf("%s\n", word);
        int current_length = strlen(word);
        if (current_length > longest_length) {
            longest_length = current_length;
            longest_word = word;
        }
        word = strtok(NULL, " \t\n");
    }
    printf("\n%s\n", longest_word);
    return 0;
}
