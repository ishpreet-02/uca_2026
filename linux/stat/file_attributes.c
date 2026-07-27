#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void printFileType(mode_t mode)
{
    if (S_ISREG(mode))
        printf("File Type: Regular File\n");
    else if (S_ISDIR(mode))
        printf("File Type: Directory\n");
    else if (S_ISLNK(mode))
        printf("File Type: Symbolic Link\n");
    else if (S_ISCHR(mode))
        printf("File Type: Character Device\n");
    else if (S_ISBLK(mode))
        printf("File Type: Block Device\n");
    else if (S_ISFIFO(mode))
        printf("File Type: FIFO/Pipe\n");
    else if (S_ISSOCK(mode))
        printf("File Type: Socket\n");
    else
        printf("File Type: Unknown\n");
}

void printTime(time_t t)
{
    printf("%s", ctime(&t));
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) == -1)
    {
        perror("stat failed");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n\n", argv[1]);

    printFileType(fileStat.st_mode);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
    printf("File Size: %ld bytes\n", fileStat.st_size);
    printf("Hard Links Count: %ld\n", fileStat.st_nlink);
    printf("Owner (UID): %d\n", fileStat.st_uid);
    printf("Group (GID): %d\n", fileStat.st_gid);

    printf("Last Access Time: ");
    printTime(fileStat.st_atime);

    printf("Last Modification: ");
    printTime(fileStat.st_mtime);

    printf("Status Change Time: ");
    printTime(fileStat.st_ctime);

    return 0;
}
