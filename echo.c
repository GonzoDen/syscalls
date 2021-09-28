long my_write (int fd, const void* buf, unsigned long count){
	long result;
	__asm__ __volatile__ (
		"mov $0x1, %%rax\n\t"
		"syscall"
		: "=a" (result)
	);

	return result;
}

unsigned long my_strlen (const char* s){
	const char* start = s; 
	for (; *s; ++s);
	return (unsigned long) (s - start);	
}

int main (int argc, char* argv[]){
	for (int i = 1; i < argc; i++){
		my_write(1, argv[i], my_strlen(argv[i])); //write, strlen include man
		if (i < argc -1){
			my_write(1, " ", 1);
		}
	}
	my_write(1, "\n", sizeof("\n") - 1);
	return 0;
}
