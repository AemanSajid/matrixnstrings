#include <stdio.h>

void findAdditiveSequences(int num, int currentNum, char *sequence, int index) {
    if (currentNum == 0) {
        sequence[index] = '\0';
        printf("%s\n", sequence);
        return;
    }

    for (int i = 1; i <= currentNum; i++) {
        sequence[index] = i + '0';
        findAdditiveSequences(num, currentNum - i, sequence, index + 1);
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    char sequence[100];

    printf("Additive Sequences for %d:\n", num);
    findAdditiveSequences(num, num, sequence, 0);

    return 0;
}


