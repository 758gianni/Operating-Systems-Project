#include <stdio.h>

int main() {
    int num;
    long long factorial = 1;

    // Get user input
    printf("Enter integer: ");
    scanf("%d", &num);

    // Calculate factorial using a loop
    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    // Display the result
    printf("Factorial = %lld\n", factorial);

    return 0;
}
