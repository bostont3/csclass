#include <stdio.h>
#include <stdlib.h>

// Corrected function names
void xor0(int num1, int num2) {
    int final = num1 ^ num2;
    printf("%d\n", final);
}
void or0(int num1, int num2) {
    int final = num1 | num2;
    printf("%d\n", final);
}
void and0(int num1, int num2) {
    int final = num1 & num2;
    printf("%d\n", final);
}
void twos(int num1, int num2) {
    int final = ~num1 + 1;
    int final2 = ~num2 + 1;
    printf("%d %d\n", final, final2);
}

int main() {
    int num1, num2, run = 1, choice, same = 1, error;

    printf("Hello User.\n");

    while (run == 1) {
        error = 1; // Reset error flag each iteration

        while (error == 1) {
            if (same == 1) {
                printf("Type two numbers: ");
                if (scanf("%d %d", &num1, &num2) != 2) {
                    printf("Invalid Input. Please enter integers.\n");
                    while (getchar() != '\n'); // Clear buffer
                    continue;
                }
                error = 0; // Input is valid
            } else {
                error = 0;
            }
        }

        printf("\nChoose xor (1), or (2), and (3), 2's Complement (4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                xor0(num1, num2);
                break;
            case 2:
                or0(num1, num2);
                break;
            case 3:
                and0(num1, num2);
                break;
            case 4:
                twos(num1, num2);
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\nWould you like to run again? yes (1), no (0): ");
        if (scanf("%d", &run) != 1) {
            run = 0; // Exit on invalid input
        }

        if (run == 1) {
            printf("Would you like to choose new numbers? yes (1), no (0): ");
            if (scanf("%d", &same) != 1) {
                same = 1; // Default to re-entering numbers
            }
        }
    }

    return 0;
}

