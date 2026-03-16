#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int choice;

    while (1) {
        // Display the main menu
        printf("\nFork Task Executor:\n");
        printf("1. Factorial Calculation\n");
        printf("2. Sorting Numbers\n");
        printf("0. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // If user selects "Quit", exit program right away
        if (choice == 0) {
            printf("Exiting program...\n");
            break;
        }

        // Fork a child process to execute the selected project
        pid_t pid = fork();

        if (pid == 0) {
            // If user selects 1, execute the factorial program
            if (choice == 1) {
                execl("./factorial", "factorial", NULL);
            }

            // If user selects 2, execute the sorting program
            else if (choice == 2) {
                execl("./sorting", "sorting", NULL);
            }

            exit(0);
        } else {
            // Parent process waits for the child process to finish before
            // displaying the menu again
            wait(NULL);
        }
    }

    return 0;
}
