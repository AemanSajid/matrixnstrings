#include <stdio.h>
#include <string.h>

int findSubstringIndex(const char *str, const char *substr) {
    int strLength = strlen(str);
    int substrLength = strlen(substr);

    // Iterate through the string
    for (int i = 0; i <= strLength - substrLength; i++) {
        int j;

        // Check if current substring matches the given substring
        for (j = 0; j < substrLength; j++) {
            if (str[i + j] != substr[j]) {
                break;  // Mismatch found, break the inner loop
            }
        }

        // If the inner loop completed without a mismatch, return the index
        if (j == substrLength) {
            return i;
        }
    }

    return -1;  // Substring not found
}

int main() {
    char str[100];
    char substr[100];

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the substring: ");
    fgets(substr, sizeof(substr), stdin);

    // Remove the trailing newline character
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    if (substr[strlen(substr) - 1] == '\n') {
        substr[strlen(substr) - 1] = '\0';
    }

    int index = findSubstringIndex(str, substr);

    if (index != -1) {
        printf("Substring found at index: %d\n", index);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}


