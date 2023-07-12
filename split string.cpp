
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int isDelimiter(char ch, char delimiter) {
    return (ch == delimiter);
}

void splitString(char *str, char delimiter) {
    int length = strlen(str);

    char word[MAX_LENGTH];
    int wordIndex = 0;

    for (int i = 0; i < length; i++) {
        if (!isDelimiter(str[i], delimiter)) {
            word[wordIndex++] = str[i];
        } else {
            word[wordIndex] = '\0';
            if (wordIndex > 0) {
                printf("%s\n", word);
            }
            wordIndex = 0;
        }
    }

    // Print the last word if it exists
    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        printf("%s\n", word);
    }
}

int main() {
    char str[MAX_LENGTH];
    char delimiter;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the delimiter character: ");
    scanf("%c", &delimiter);

    printf("Words after splitting:\n");
    splitString(str, delimiter);

    return 0;
}



