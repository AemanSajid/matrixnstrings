#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    int shift, direction;
    int encryptedShift, encryptedDirection;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character from the string
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    // Generate random numbers for shift and direction
    srand(time(NULL));
    shift = rand() % ALPHABET_SIZE;
    direction = rand() % 2;  // 0 for left shift, 1 for right shift

    // Encrypt the string with the random shift and direction
    caesarEncrypt(str, shift);
    if (direction == 0) {
        encryptedShift = shift;
        encryptedDirection = -1;  // Left shift
    } else {
        encryptedShift = ALPHABET_SIZE - shift;
        encryptedDirection = 1;   // Right shift
    }

    printf("Encrypted string: %s\n", str);
    printf("Shift: %d\n", encryptedShift);
    printf("Direction: %s\n", encryptedDirection == -1 ? "Left" : "Right");

    return 0;
}


