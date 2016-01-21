#include <unistd.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>

/*
 * Function for identify file mode.
 */
char *getFileMode(mode_t m);
void setFileMode(mode_t m, char *pmode, int *vmode);

int main(int argc, char *argv[]) {
    char *pathname = argv[1];
    //int pathnameLen = strlen(pathname);

    if (pathname == NULL) {
        write(2, "No pathname\n", 20);
    }

    printf("Params Num : %d\n", argc - 1);

    printf("Path name is : %s\n", argv[1]);

    //test for file_mode
    struct stat *buf = malloc(sizeof(struct stat));

    if (lstat(pathname, buf) != 0) {
        printf("File error.");
        exit(errno);
    }

    char *file_mode = getFileMode(buf->st_mode);
    printf("File mode is : %s\n", file_mode);

    printf("Mode# is : %lo (octal)\n", (unsigned long) buf->st_mode);
    //end test for file_mode

    //test for dev

    printf("Device : %lx \n", (unsigned long) buf->st_dev);
    printf("Dev major : %o \n", major(buf->st_dev));
    printf("Dev minor : %o \n", minor(buf->st_dev));

    printf("dev ID : %lxh/%ldd\n", (long) buf->st_dev, (long) buf->st_dev);
    //end test for dev

    //test for inode_num
    printf("File Inode Num is : %ld\n", (long) buf->st_ino);
    //end test for inode_num

    char mode[11];
    mode[10] = '\0';
    int modeNum;
    setFileMode(buf->st_mode, mode, &modeNum);
    printf("File Mode : %04o/%s\n", modeNum, mode);

    //printf("Mode : %lo (octal)\n", (unsigned long)buf->st_mode);

    //test for Link count
    printf("File Link Count is : %ld\n", (long) buf->st_nlink);
    //end test for Link Count

    //test for UID and GID and Username
    char *usrName = getpwuid(buf->st_uid)->pw_name;
    char *grpName = getgrgid(buf->st_gid)->gr_name;
    printf("UID : %s/%ld, GID : %s/%ld\n", usrName, (long) buf->st_uid, grpName, (long) buf->st_gid);
    //end test for UID and GID

    //test for I/O block size
    printf("Block size is : %ld\n", (long) buf->st_blksize);
    //end test for I/0 block size

    //test for File size
    printf("File size is : %ld\n", (long) buf->st_size);
    //end test for File size

    //test for Blocks allocated
    printf("Blocks allocated : %lld\n", (long long) buf->st_blocks);
    //end test for Blocks allocated

    //test for Last status change
    printf("Change time : %s", ctime(&buf->st_ctime));
    //end test for last status change

    //test for Last status change
    printf("Access time : %s", ctime(&buf->st_atime));
    //end test for last status change

    //test for Last status change
    printf("Modify time : %s", ctime(&buf->st_mtime));
    //end test for last status change

    free(buf);
    exit(EXIT_SUCCESS);
}

char *getFileMode(mode_t m) {
    if (S_ISBLK(m)) {
        return "block special file";
    } else if (S_ISCHR(m)) {
        return "character special file";
    } else if (S_ISDIR(m)) {
        return "directory";
    } else if (S_ISFIFO(m)) {
        return "fifo special file";
    } else if (S_ISLNK(m)) {
        return "symbolic link";
    } else if (S_ISREG(m)) {
        return "regular file";
    } else {
        return "unknown file mode";
    }
}

void setFileMode(mode_t m, char *pmode, int *vmode) {
    //dir or not
    if (S_ISDIR(m)) {
        pmode[0] = 'd';
    } else {
        pmode[0] = '-';
    }

    unsigned long permission_mask = 4095L;
    *vmode = (unsigned long) (m & permission_mask);

    //user read
    if ((m & S_IRUSR) == 0) {
        pmode[1] = '-';
    } else {
        pmode[1] = 'r';
    }

    //user write
    if ((m & S_IWUSR) == 0) {
        pmode[2] = '-';
    } else {
        pmode[2] = 'w';
    }

    //user exc
    if ((m & S_IXUSR) == 0) {
        pmode[3] = '-';
    } else {
        pmode[3] = 'x';
    }

    //group read
    if ((m & S_IRGRP) == 0) {
        pmode[4] = '-';
    } else {
        pmode[4] = 'r';
    }

    //group write
    if ((m & S_IWGRP) == 0) {
        pmode[5] = '-';
    } else {
        pmode[5] = 'w';
    }

    //group exc
    if ((m & S_IXGRP) == 0) {
        pmode[6] = '-';
    } else {
        pmode[6] = 'x';
    }

    //other read
    if ((m & S_IROTH) == 0) {
        pmode[7] = '-';
    } else {
        pmode[7] = 'r';
    }

    //other write
    if ((m & S_IWOTH) == 0) {
        pmode[8] = '-';
    } else {
        pmode[8] = 'w';
    }

    //user exc
    if ((m & S_IXOTH) == 0) {
        pmode[9] = '-';
    } else {
        pmode[9] = 'x';
    }
}

/*
 *  S_ISBLK(m)
    Test for a block special file.
    S_ISCHR(m)
    Test for a character special file.
    S_ISDIR(m)
    Test for a directory.
    S_ISFIFO(m)
    Test for a pipe or FIFO special file.
    S_ISREG(m)
    Test for a regular file.
    S_ISLNK(m)
    Test for a symbolic link.
 */