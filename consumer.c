#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    // Set up shared memory and semaphore
    const char *name = "/shared_buffer";

    int shmid = shm_open(name, O_CREAT | O_RDWR, 0666);

    int *buffer = mmap(0, sizeof(int), PROT_READ | PROT_WRITE,
    MAP_SHARED, shmid, 0);

    // Read the produced value from shared memory
    printf("Consumed value = %d\n", *buffer);

    // Clean up shared memory and semaphore
    munmap(buffer, sizeof(int));
    close(shmid);

    return 0;
}
