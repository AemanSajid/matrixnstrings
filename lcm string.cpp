#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int calculateLCM(int numbers[], int count) {
    int result = numbers[0];

    for (int i = 1; i < count; i++) {
        result = lcm(result, numbers[i]);
    }

    return result;
}

int main() {
    int numbers[10];
    int count;

    printf("Enter the number of elements (max 10): ");
    scanf("%d", &count);

    if (count < 1 || count > 10) {
        printf("Invalid number of elements. Program exiting.\n");
        return 0;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < count; i++) {
        scanf("%d", &numbers[i]);
    }

    int lcmResult = calculateLCM(numbers, count);

    printf("The least common multiple (LCM) is: %d\n", lcmResult);

    return 0;
}

