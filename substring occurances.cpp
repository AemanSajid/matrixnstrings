#include <stdio.h>
#include <string.h>

int findLastSubstringIndex(const char *str, const char *substr) {
    int strLength = strlen(str);
    int substrLength = strlen(substr);

    if (substrLength > strLength) {
        return -1;  // Substring cannot be longer than the string
    }

    // Iterate through the string in reverse
    for (int i = strLength - substrLength; i >= 0; i--) {
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

    int index = findLastSubstringIndex(str, substr);

    if (index != -1) {
        printf("Last occurrence of substring found at index: %d\n", index);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
6.
#include <stdio.h>
#include <string.h>

void findAllSubstringIndexes(const char *str, const char *substr) {
    int strLength = strlen(str);
    int substrLength = strlen(substr);

    if (substrLength > strLength) {
        printf("Substring cannot be longer than the string.\n");
        return;
    }

    int count = 0;  // Count of substring occurrences

    // Iterate through the string
    for (int i = 0; i <= strLength - substrLength; i++) {
        int j;

        // Check if current substring matches the given substring
        for (j = 0; j < substrLength; j++) {
            if (str[i + j] != substr[j]) {
                break;  // Mismatch found, break the inner loop
            }
        }

        // If the inner loop completed without a mismatch, print the index
        if (j == substrLength) {
            printf("Substring found at index: %d\n", i);
            count++;
        }
    }

    if (count == 0) {
        printf("Substring not found.\n");
    } else {
        printf("Total occurrences: %d\n", count);
    }
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

    findAllSubstringIndexes(str, substr);

    return 0;
}


