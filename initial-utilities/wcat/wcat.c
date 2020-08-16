#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
	if(argc == 1)
		exit(0);
	for(int i = 1; i<argc; i++) {
		FILE * fd = fopen(argv[i], "r");
		if(fd == NULL) {
			printf("wcat: cannot open file\n");
			exit(1);
		}
		char str[512];
		while(fgets(str, sizeof(str), fd) != NULL)
			printf("%s", str);
		fclose(fd);
	}
	exit(0);

}
