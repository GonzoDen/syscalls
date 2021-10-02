#include <stdio.h>
#include <stdbool.h>
int main (int argc, char *argv[]){
	if (argc > 1){
		while (true){
			for (int i = 1; i < argc; i++){
				printf (i < argc - 1 ? "%s " : "%s\n", argv[i]);
			}
		}
	}


	else{
		while (true){
			puts("y");
		}
	}
	return 0;
}
