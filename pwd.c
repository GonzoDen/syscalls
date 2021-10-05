#include <unistd.h>
#include <string.h>

#define BUF_SIZE 4096

static char buffer[BUF_SIZE];

int main (int argc, char* argv[])
{
	getcwd(buffer,BUF_SIZE);
	write(STDOUT_FILENO, buffer, strnlen(buffer, BUF_SIZE));
	write(STDOUT_FILENO, "\n", 1);
	return 0;
}
