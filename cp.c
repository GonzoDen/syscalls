#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 131072
static char buffer[BUF_SIZE];

int main (int argc, char* argv[]){
	if (argc == 3) {
		int in_fd = openat(AT_FDCWD, argv[1], O_RDONLY);
		int out_fd = openat(AT_FDCWD, argv[2], O_WRONLY|O_CREAT|O_EXCL, 0664);
		ssize_t bytes_read;
		while ((bytes_read = read (in_fd, buffer, BUF_SIZE)) > 0){
			write (out_fd, buffer, bytes_read);
		}
		close (in_fd);
		close (out_fd);	
	}	

	return 0;
}	
