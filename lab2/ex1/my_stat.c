#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdio.h>

#define PATHBUFF 100

int main() {
    char buffer[PATHBUFF];
    struct stat *stat_result;
    stat(buffer, stat_result);
    dev_t st_dev;
    ino_t st_ino;
    printf("%s", stat_result->st_dev);

    exit(0);
}
