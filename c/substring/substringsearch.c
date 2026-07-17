#include <stdio.h>

int find_substring(const char *haystack, const char *needle)
{
    int i;
    int j;

    if (needle[0] == '\0')
    {
        return 0;
    }

    for (i = 0; haystack[i] != '\0'; i++)
    {
        j = 0;

        while (haystack[i + j] != '\0' &&
               needle[j] != '\0' &&
               haystack[i + j] == needle[j])
        {
            j++;
        }

        if (needle[j] == '\0')
        {
            return i;
        }
    }

    return -1;
}

int main(void)
{
    const char haystack[] = "Embedded Systems";
    const char needle[] = "bed";

    int result = find_substring(haystack, needle);

    if (result != -1)
    {
        printf("Substring found at index: %d\n", result);
    }
    else
    {
        printf("Substring not found.\n");
    }

    return 0;
}