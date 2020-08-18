#include<stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if(argc == 1) {
		printf("wunzip: file1 [file2 ...]\n");
		exit(1);
	}
	int run_length;
	char c;
	
	for(int i = 1; i<argc; i++) {
		FILE * fd = fopen(argv[i], "r");
		if(fd == NULL) {
			printf("wunzip: cannot open file\n");
			exit(1);
		}
		
		while ((fread(&run_length, sizeof(int), 1, fd)) != 0 && fread(&c, sizeof(char), 1, fd) != 0) {
			for(int i=0; i<run_length; i++) {
				putchar(c);
			}
		}
	fclose(fd);
}
exit(0);

}