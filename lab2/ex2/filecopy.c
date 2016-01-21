#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define BUFSIZE 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Illegal argument number for %s", argv[0]);
        exit(1);
    }

    char *srcFileName = argv[1];
    char *desFileName = argv[2];

    int srcFileDes = open(srcFileName, O_RDONLY);
    if (srcFileDes == -1) {
        fprintf(stderr, "Can not open source file %s", srcFileName);
        exit(1);
    }
    int desFileDes = open(desFileName, O_WRONLY | O_CREAT);
    if (desFileDes == -1) {
        fprintf(stderr, "Can not open destination file %s", desFileName);
        exit(1);
    }

    if (strcmp(srcFileName, desFileName) == 0) {
        fprintf(stderr, "Can not overwrite the source file.");
        exit(1);
    }

    void *buf = malloc(sizeof(void) * BUFSIZE);
    int curSize = 0;

    while ((curSize = read(srcFileDes, buf, BUFSIZE)) > 0) {
        if (write(desFileDes, buf, curSize) < curSize) {
            fprintf(stderr, "Write error");
            exit(1);
        }
    }

    if (curSize == -1) {
        fprintf(stderr, "Read error");
        exit(1);
    }

    if (close(srcFileDes) == -1) {
        fprintf(stderr, "Close source file error");
        exit(1);
    };

    if (close(desFileDes) == -1) {
        fprintf(stderr, "Close destination file error");
        exit(1);
    };

    //Change file mode
    struct stat srcMode;
    stat(srcFileName, &srcMode);
    if (chmod(desFileName, srcMode.st_mode) == -1) {
        fprintf(stderr, "Fail to change destination file mode");
        exit(1);
    }

    free(buf);
}