#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char* argv[]){

	for (int i = 1; i < argc; i++){
		int fd = openat(AT_FDCWD, argv[i], O_WRONLY|O_CREAT, 0666);
		futimens(fd, NULL);
		close(fd);
	}
	return 0;
}
