#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int choice;

    while (1) {
        // Display the main menu
        printf("\n===== Main Menu =====\n\n");
        printf("Select Project:\n");
        printf("1. Fork-Based Task Executor System\n");
        printf("2. Producer-Consumer Simulation System\n");
        printf("0. Quit\n\n");
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
            // If user selects 1, execute the fork_tasks program
            if (choice == 1) {
                execl("./executables/fork_tasks", "fork_tasks", NULL);
            }

            // If user selects 2, execute the producer_consumer program
            else if (choice == 2) {
                execl("./executables/producer_consumer", "producer_consumer", NULL);
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
