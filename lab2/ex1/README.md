## My_Stat (lab2-ex1)
### Command Line Syntax
`my_stat [-L] <filename>`
### Explain
The program my_stat can show information about a given file.  
If you use the option -L, it will show the information of the deepest followed file.
### Example
Input:`$ ./my_stat testfile`
Result:
```
File: "testfile"
Size: 0               Blocks: 0          IO Block: 16384  regular file
Device: 1ah/26d Inode: 53823260808  Links: 1
Access: (0640/-rw-r-----)  Uid: (13844/  yixin1)   Gid: (17127/  yixin1)
Access: Thu Jan 21 16:16:43 2016
Modify: Thu Jan 21 16:16:43 2016
Change: Thu Jan 21 16:16:43 2016
```
Input:`$ ./my_stat softlink`
Result:
```
File: "softlink"
Size: 8               Blocks: 0          IO Block: 16384  symbolic link
Device: 1ah/26d Inode: 53693040683  Links: 1
Access: (0777/-rwxrwxrwx)  Uid: (13844/  yixin1)   Gid: (17127/  yixin1)
Access: Thu Jan 21 16:30:30 2016
Modify: Thu Jan 21 16:30:30 2016
Change: Thu Jan 21 16:30:30 2016
```
Input:`$ ./my_stat -L softlink`
Result:
```
File: "softlink"
Size: 0               Blocks: 0          IO Block: 16384  regular file
Device: 1ah/26d Inode: 53823260808  Links: 1
Access: (0640/-rw-r-----)  Uid: (13844/  yixin1)   Gid: (17127/  yixin1)
Access: Thu Jan 21 16:16:43 2016
Modify: Thu Jan 21 16:16:43 2016
Change: Thu Jan 21 16:16:43 2016
```
