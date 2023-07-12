
#include <stdio.h>

#define MAX_CHARACTERS 256

void countCharacterFrequency(const char *str) {
    int frequency[MAX_CHARACTERS] = {0};  // Initialize frequency array with zeros

    // Iterate through each character of the string
    for (int i = 0; str[i] != '\0'; i++) {
        int index = (int)str[i];  // Get the ASCII value of the character
        frequency[index]++;       // Increment the frequency of the character
    }

    // Print the character frequency
    printf("Character frequency:\n");
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (frequency[i] > 0) {
            printf("'%c': %d\n", (char)i, frequency[i]);
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    countCharacterFrequency(str);

    return 0;
}


