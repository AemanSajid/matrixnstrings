#include <stdio.h>
#include <stdbool.h>

bool isBinaryPalindrome(int num) {
    int reverseNum = 0;
    int temp = num;

    while (temp > 0) {
        reverseNum <<= 1;    // Left shift by 1 to make space for the next bit
        reverseNum |= temp & 1;    // Add the rightmost bit of 'temp' to 'reverseNum'
        temp >>= 1;    // Right shift by 1 to move to the next bit in 'temp'
    }

    return (reverseNum == num);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isBinaryPalindrome(num)) {
        printf("The binary representation of %d is a palindrome.\n", num);
    } else {
        printf("The binary representation of %d is not a palindrome.\n", num);
    }

    return 0;
}

