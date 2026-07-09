#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define LOGFILE "audit.log"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        write(1, "Usage:\n./auditlog --add \"message\"\n./auditlog --view\n", 53);
        return 1;
    }

    // ADD MODE
    if (strcmp(argv[1], "--add") == 0)
    {
        if (argc < 3)
        {
            write(1, "Please provide a message.\n", 26);
            return 1;
        }

        int fd = open(LOGFILE, O_WRONLY | O_CREAT | O_APPEND, 0644);

        if (fd < 0)
        {
            write(1, "Cannot open log file.\n", 22);
            return 1;
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }

    // VIEW MODE
    else if (strcmp(argv[1], "--view") == 0)
    {
        int fd = open(LOGFILE, O_RDONLY);

        if (fd < 0)
        {
            write(1, "Log file not found.\n", 20);
            return 1;
        }

        char ch;
        int line = 1;
        char buffer[20];

        int len = snprintf(buffer, sizeof(buffer), "%d: ", line);
        write(1, buffer, len);

        while (read(fd, &ch, 1) > 0)
        {
            write(1, &ch, 1);

            if (ch == '\n')
            {
                line++;

                if (read(fd, &ch, 1) > 0)
                {
                    len = snprintf(buffer, sizeof(buffer), "%d: ", line);
                    write(1, buffer, len);
                    write(1, &ch, 1);
                }
                else
                {
                    break;
                }
            }
        }

        close(fd);
    }

    else
    {
        write(1, "Invalid option.\n", 16);
    }

    return 0;
}
