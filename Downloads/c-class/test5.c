#include <stdio.h>
#include <stdlib.h>

/*
    File: hw6_boston_tommy.c
    Author: Tommy Boston
    Assignment: Homework 6
    Date: 2/16/25
    Resources: Google
*/

// Recursive function to fill the matrix
void matrixprint(int numMatrix[][100], int num, int curNum) {
    if (curNum > num) { // Base case: Stop recursion when curNum exceeds num
        return;
    }

    for (int idx = 0; idx < curNum; idx++) {
        numMatrix[curNum - 1][idx] = idx + 1; // Fill numbers sequentially
    }

    for (int idx = curNum; idx < num; idx++) {
        numMatrix[curNum - 1][idx] = 0; // Fill remaining spots with 0
    }

    // Recursively call for the next row
    matrixprint(numMatrix, num, curNum + 1);
}

int main() {
    int num, error = 1, curNum = 1;

    // Input validation loop
    while (error == 1) {
        printf("Type a number less than 100 and bigger than 0: ");
        scanf("%d", &num);

        if (num >= 100 || num <= 0) {
            printf("Invalid number. Try again.\n");
        } else {
            error = 0;
        }
    }

    // Declare and initialize matrix
    int numMatrix[100][100] = {0};

    // Fill the matrix using recursion
    matrixprint(numMatrix, num, curNum);

    // Print the matrix while skipping 0s
    printf("\nGenerated Left-Aligned Triangle:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (numMatrix[i][j] != 0) {
                printf("%d ", numMatrix[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

