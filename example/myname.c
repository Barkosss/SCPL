#include <stdio.h>

#define MAX_LEN_NAME 100

int main() {
    char name[MAX_LEN_NAME];

    printf("Enter your name: ");
    scanf("%99s", name);

    printf("Hello, %s!\n", name);

    return 0;
}