#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 4096
#define MAX_CODE_SIZE 12

typedef struct {
    int code;
    char *value;
} LZWEntry;

LZWEntry table[MAX_TABLE_SIZE];
int tableSize = 256;

void initializeTable() {
    for (int i = 0; i < 256; i++) {
        table[i].code = i;
        table[i].value = (char *)malloc(2);
        table[i].value[0] = (char)i;
        table[i].value[1] = '\0';
    }
}

int findCode(char *str) {
    for (int i = 0; i < tableSize; i++) {
        if (strcmp(table[i].value, str) == 0) {
            return table[i].code;
        }
    }
    return -1;
}

void addEntry(char *str, int code) {
    if (tableSize < MAX_TABLE_SIZE) {
        table[tableSize].code = code;
        table[tableSize].value = strdup(str);
        tableSize++;
    }
}

void compress(char *input) {
    char current[256] = "";
    int code = 256;

    for (int i = 0; input[i] != '\0'; i++) {
        char next[2] = {input[i], '\0'};
        strcat(current, next);

        if (findCode(current) == -1) {
            int prevCode = findCode(current);
            if (prevCode != -1) {
                printf("%d ", prevCode);
            }
            addEntry(current, code++);
            strcpy(current, next);
        }
    }

    int finalCode = findCode(current);
    if (finalCode != -1) {
        printf("%d ", finalCode);
    }
}

void freeTable() {
    for (int i = 0; i < tableSize; i++) {
        free(table[i].value);
    }
}

int main() {
    initializeTable();
    char input[] = "ABABABABA";
    printf("Compressed output: ");
    compress(input);
    printf("\n");
    freeTable();
    return 0;
}
