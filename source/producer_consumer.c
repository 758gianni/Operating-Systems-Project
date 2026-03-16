#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("\nStarting producer and consumer processes...\n\n");

    // Fork child process for producer
    pid_t producer_pid = fork();

    if (producer_pid == 0) {
        execl("./executables/producer", "producer", NULL);
        perror("execl producer failed");
        exit(1);
    }

    // Fork child process for consumer
    pid_t consumer_pid = fork();

    if (consumer_pid == 0) {
        execl("./executables/consumer", "consumer", NULL);
        perror("execl consumer failed");
        exit(1);
    }

    // Wait for both children to complete
    int status;

    waitpid(producer_pid, &status, 0);
    waitpid(consumer_pid, &status, 0);

    return 0;
}
