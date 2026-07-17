#include <stdio.h>

int my_strlen(const char *str) {
    int length = 0;

    while (*str != '\0') {
        str++;
        length++;
    }

    return length;
}

int main() {
    char str[] = "Hello , how are you?";

    printf("Length of the string: %d\n", my_strlen(str));

    return 0;
}