#include <stdio.h>
#include <string.h>
#include <ctype.h>

void upperCase(char* c) {
    int size = strlen(c);
    for (short i = 0; i < size; i++) {
        c[i] = toupper(c[i]);
    }
    printf("string of characters after capitalization: \n%s\n", c);
}

void lowerCase(char* c) {
    int size = strlen(c);
    for (short i = 0; i < size; i++) {
        c[i] = tolower(c[i]);
    }
    printf("lower case string of characters: \n%s", c);
}

int main() {
    char x[100];
    fgets(x, 99, stdin);
    upperCase(x);
    lowerCase(x);
    return 0;
}