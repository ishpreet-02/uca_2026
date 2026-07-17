#include <stdio.h>

void url_encode(char *str, int true_length)
{
    int i;
    int spaceCount = 0;
    int newIndex;

    for (i = 0; i < true_length; i++)
    {
        if (str[i] == ' ')
        {
            spaceCount++;
        }
    }

    newIndex = true_length + (spaceCount * 2);

    str[newIndex] = '\0';

    for (i = true_length - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[newIndex - 1] = '0';
            str[newIndex - 2] = '2';
            str[newIndex - 3] = '%';
            newIndex -= 3;
        }
        else
        {
            str[newIndex - 1] = str[i];
            newIndex--;
        }
    }
}

int main(void)
{
    char str[50] = "Hello World";

    int true_length = 11;

    url_encode(str, true_length);

    printf("Encoded String: %s\n", str);

    return 0;
}