#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 131072
static char buffer[BUF_SIZE]; //max size num
int main (int argc, char* argv[]) {
	if (argc > 1){
		for (int i = 1; i < argc; i++){
			int fd = openat(AT_FDCWD, argv[i], O_RDONLY); //filedescriptor
			ssize_t bytes_read;
			while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0){
					write(STDOUT_FILENO, buffer, bytes_read);
			}
			close(fd);
		}
	} 
	else { //read from stdinput (console)
			ssize_t bytes_read;
			while ((bytes_read = read(STDIN_FILENO, buffer, BUF_SIZE)) > 0){
					write(STDOUT_FILENO, buffer, bytes_read);
			}
	}

	return 0;
}
