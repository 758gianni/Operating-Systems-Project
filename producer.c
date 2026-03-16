#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    // Set up shared memory and semaphore
    const char *name = "/shared_buffer";

    int shmid = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shmid, sizeof(int));

    int *buffer = mmap(0, sizeof(int), PROT_READ | PROT_WRITE,
    MAP_SHARED, shmid, 0);

    // Prompt user to enter a positive integer value to produce
    int value;

    printf("Enter integer value to produce: ");

    // Validate that user input is a positive integer
    if (scanf("%d", &value) != 1) {
        printf("Invalid input\n");
        return 1;
    }
        
    // Write the produced value to shared memory
    *buffer = value;

    // Print the produced value
    printf("Produced value = %d\n", value);

    // Clean up shared memory and semaphore
    munmap(buffer, sizeof(int));
    close(shmid);

    return 0;
}
