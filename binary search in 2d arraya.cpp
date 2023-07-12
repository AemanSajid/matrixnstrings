#include <stdio.h>

void displayRowIndex(int number) {
    int digit;
    int row, column;

    printf("Number: %d\n", number);

    while (number > 0) {
        digit = number % 10;

        row = digit;
        column = digit;

        printf("Digit: %d, Row: %d, Column: %d\n", digit, row, column);

        number /= 10;
    }
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    displayRowIndex(number);

    return 0;
}


#include <stdio.h>

#define ROWS 4
#define COLS 4

int binarySearch(int arr[][COLS], int target, int row, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[row][mid] == target) {
            return mid;
        } else if (arr[row][mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

void search2DArray(int arr[][COLS], int target) {
    int row = 0;
    int col = COLS - 1;
    int found = 0;

    while (row < ROWS && col >= 0) {
        if (arr[row][col] == target) {
            printf("Found at row %d, column %d\n", row, col);
            found = 1;
            break;
        } else if (arr[row][col] < target) {
            row++;
        } else {
            int index = binarySearch(arr, target, row, 0, col - 1);
            if (index != -1) {
                printf("Found at row %d, column %d\n", row, index);
                found = 1;
                break;
            } else {
                col--;
            }
        }
    }

    if (!found) {
        printf("Element not found in the 2D array.\n");
    }
}

int main() {
    int arr[ROWS][COLS] = {
        {2, 4, 6, 8},
        {10, 12, 14, 16},
        {18, 20, 22, 24},
        {26, 28, 30, 32}
    };

    int target;

    printf("Enter the target element: ");
    scanf("%d", &target);

    search2DArray(arr, target);

    return 0;
}

