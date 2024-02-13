#include <stdio.h>
#include <string.h>

#define MAX_WORDS 500
#define MAX_WORD_LENGTH 50

void inputWords(char words[][MAX_WORD_LENGTH], int* numWords);
void sortWords(char* words[], int numWords);
void printWords(char* words[], int numWords);

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char* wordPointers[MAX_WORDS];
    int numWords = 0;

    inputWords(words, &numWords);

    for (int i = 0; i < numWords; i++) wordPointers[i] = words[i];

    sortWords(wordPointers, numWords);
    printWords(wordPointers, numWords);
    printf("\n");
    
    int counts[26] = {0}; 
    for (int i = 0; i < numWords; i++) {
        char firstLetter = wordPointers[i][0];
        int index = firstLetter - 'A';
        counts[index]++;
    }

    // for (int i = 0; i < 26; i++) printf("%c: %d\n", 'A' + i, counts[i]);
    
    int average = numWords/4;
    
    int i=0, sum_surn1 = 0, sum_surn2 = 0, sum_surn3 = 0, sum_surn4 = 0;  
    while (sum_surn1 < average) { sum_surn1 += counts[i]; i++; }
    int border1 = i;
    while (sum_surn2 < average) { sum_surn2 += counts[i]; i++; }
    int border2 = i;
    while (sum_surn3 < average) { sum_surn3 += counts[i]; i++; };
    int border3 = i;
    for (i = border3; i < 26; i++) sum_surn4 += counts[i];
    
    printf("A-%c %d\n%c-%c %d\n%c-%c %d\n%c-Z %d\n", 'A'+border1-1, sum_surn1,
            'A'+border1,'A'+border2-1, sum_surn2, 'A'+border2,'A'+border3-1, sum_surn3,
            'A'+border3, sum_surn4);
    
    return 0;
}

void inputWords(char words[][MAX_WORD_LENGTH], int* numWords) {
    char buffer[MAX_WORD_LENGTH];
    while (*numWords < MAX_WORDS) {
        scanf("%s", buffer);
        if (strcmp(buffer, "\0") == 0) break;
    
        strcpy(words[*numWords], buffer);
        (*numWords)++;
        memset(buffer, 0, strlen(buffer));
            
    }
}

void sortWords(char* words[], int numWords) {
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = 0; j < numWords - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

void printWords(char* words[], int numWords) {
    for (int i = 0; i < numWords; i++) printf("%s\n", words[i]);
}
