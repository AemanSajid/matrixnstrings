#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

void caesarEncrypt(char *str, int shift) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        char ch = str[i];

        // Check if the character is an alphabet
        if (isalpha(ch)) {
            // Determine the case (upper or lower)
            int isUpperCase = isupper(ch);

            // Convert the character to lowercase for ease of calculation
            ch = tolower(ch);

            // Apply the Caesar cipher shift
            ch = (ch - 'a' + shift) % ALPHABET_SIZE + 'a';

            // Convert back to uppercase if the original character was uppercase
            if (isUpperCase) {
                ch = toupper(ch);
            }
        }

        // Update the character in the string
        str[i] = ch;
    }
}

int main() {
    char str[100];
    int shift;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    // Remove the trailing newline character from the string
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    caesarEncrypt(str, shift);

    printf("Encrypted string: %s\n", str);

    return 0;
}

