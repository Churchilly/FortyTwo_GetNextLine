# FortyTwo_GetNextLine
Reading a line from a fd is way too tedious.

## Function Prototypes

### `open`
```c
#include <fcntl.h>

int open(const char *pathname, int flags, ...);
```

### `read`
```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);
```

### `close`
```c
#include <unistd.h>

int close(int fd);
```

## Flags for `open` Function

- `O_RDONLY`: Open the file for read-only access.
- `O_WRONLY`: Open the file for write-only access.
- `O_RDWR`: Open the file for both reading and writing.
- `O_CREAT`: Create the file if it does not exist. Requires a third argument specifying the file mode (permissions).
- `O_EXCL`: Ensure that this call creates the file. If the file already exists, the call fails.
- `O_TRUNC`: Truncate the file to zero length if it already exists and is opened for writing.
- `O_APPEND`: Open the file in append mode. Writes will always append to the end of the file.
- `O_NONBLOCK`: Open the file in non-blocking mode.
- `O_SYNC`: Open the file for synchronous I/O.

## Explanation of File Descriptor (fd)

A file descriptor (fd) is an integer that uniquely identifies an open file within a process. The operating system maintains a table of open files for each process, and the file descriptor is an index into this table.

### Example Usage

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[bytesRead] = '\0';
    printf("Read %zd bytes: %s\n", bytesRead, buffer);

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}
```

### File Descriptors in System

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    int fd3 = open("file3.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1) {
        perror("open");
        return 1;
    }

    // Simulate some operations
    sleep(42);

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}
```

#### Running the Program

Compile and run the program:

```sh
gcc -o open_files open_files.c
./open_files &
```

The program will run in the background and sleep for 42 seconds, giving you time to inspect the open files using `lsof`.

#### Using `lsof` to Inspect Open Files

Find the PID of the running program:

```sh
ps aux | grep open_files
```

Assume the PID is `42`. Now, use `lsof` to list the open files for this process:

```sh
lsof -p 42
```

#### Example Output of `lsof`

```plaintext
COMMAND     PID USER  FD     TYPE   DEVICE  SIZE/OFF NODE  NAME
open_files  42  user  cwd    DIR    1,4     4096     567   /path/to/current/directory
open_files  42  user  txt    REG    1,4     123456   789   /path/to/open_files
open_files  42  user  mem    REG    1,4     56789    890   /usr/lib/libc.so.6
open_files  42  user  0u     CHR    136,2   0t0      3     /dev/pts/2
open_files  42  user  1u     CHR    136,2   0t0      3     /dev/pts/2
open_files  42  user  2u     CHR    136,2   0t0      3     /dev/pts/2
open_files  42  user  3r     REG    1,4     1024     456   /path/to/file1.txt
open_files  42  user  4r     REG    1,4     2048     789   /path/to/file2.txt
open_files  42  user  5r     REG    1,4     4096     890   /path/to/file3.txt
```

#### Explanation of Output

- **COMMAND:** The name of the command associated with the process (`open_files`).
- **PID:** The process ID (`42`).
- **USER:** The user who owns the process (`user`).
- **FD:** The file descriptor number. Common values include:
  - `cwd`: Current working directory.
  - `txt`: Program text (code and data).
  - `mem`: Memory-mapped file.
  - `0u`, `1u`, `2u`: Standard input, output, and error.
  - `3r`, `4r`, `5r`: Regular file descriptors for reading (`r`).
- **TYPE:** The type of file (e.g., `DIR` for directory, `REG` for regular file).
- **DEVICE:** The device number.
- **SIZE/OFF:** The size of the file or the file offset.
- **NODE:** The inode number.
- **NAME:** The name of the file.
