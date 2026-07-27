#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int c, next;
    int in_string = 0, in_char = 0, escape = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (in_string) {
            putchar(c);
            if (escape)
                escape = 0;
            else if (c == '\\')
                escape = 1;
            else if (c == '"')
                in_string = 0;
        }
        else if (in_char) {
            putchar(c);
            if (escape)
                escape = 0;
            else if (c == '\\')
                escape = 1;
            else if (c == '\'')
                in_char = 0;
        }
        else {
            if (c == '"') {
                in_string = 1;
                putchar(c);
            }
            else if (c == '\'') {
                in_char = 1;
                putchar(c);
            }
            else if (c == '/') {
                next = fgetc(fp);

                if (next == '/') {
                    while ((c = fgetc(fp)) != EOF && c != '\n');
                    if (c == '\n')
                        putchar('\n');
                }
                else if (next == '*') {
                    int prev = 0;
                    while ((c = fgetc(fp)) != EOF) {
                        if (prev == '*' && c == '/')
                            break;
                        prev = c;
                    }
                }
                else {
                    putchar('/');
                    if (next != EOF)
                        ungetc(next, fp);
                }
            }
            else {
                putchar(c);
            }
        }
    }

    fclose(fp);
    return 0;
}