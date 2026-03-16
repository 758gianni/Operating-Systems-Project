#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int choice;

    while(1) {

        printf("\nFork Task Executor:\n");
        printf("1. Factorial Calculation\n");
        printf("2. Sorting Numbers\n");
        printf("0. Quit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==0)
            break;

        pid_t pid=fork();

        if(pid==0)
        {
            if(choice==1)
                execl("./factorial","factorial",NULL);
            else if(choice==2)
                execl("./sorting","sorting",NULL);

            exit(0);
        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}
