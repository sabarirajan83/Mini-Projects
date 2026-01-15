// Roll Dice Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int n) {
    return (rand() % (6 * n)) + 1;
}

// Function to safely read an integer from user
int read_int() {
    int value;
    char ch;
    while (1) {
        if (scanf("%d", &value) == 1) {
            while ((ch = getchar()) != '\n' && ch != EOF) ;
            return value;
        } else {
            printf("Invalid input\nPlease enter a number: ");
            while ((ch = getchar()) != '\n' && ch != EOF) ;
        }
    }
}

int main() {
    srand(time(0));

    int n = 1;
    int count = 0;

    while (1) {
        printf("\nEnter the following numbers for:\n1. Roll Dice\n2. Options\n3. Exit\nchoice: ");
        int choice = read_int();

        switch (choice) {
            int option;
            case 1:
                printf("You rolled %d!\n", roll_dice(n));
                count++;
                break;
            case 2:
                printf("\nOptions:\n1. Change the number of dice to roll\n2. Number of times rolled\nchoice: ");
                option = read_int();
                switch(option) {
                    case 1:
                        printf("Enter the number of dice to roll: ");
                        n = read_int();
                        printf("Number of dice set to %d\n", n);
                        count = 0; // Reset count when changing number of dice
                        break;
                    case 2:
                        printf("The dice have been rolled %d times.\n", count);
                        break;
                    default:
                        printf("Invalid option. Please try again.\n");
                        break;
                }
                break;
            case 3:
                printf("Thanks for playing\nExiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
