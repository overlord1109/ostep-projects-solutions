#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
	if(argc == 1) {
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}
	char * searchterm = argv[1];
	char *line = NULL;
	size_t len = 0;
	if(argc == 2) {
	//do fgets from stdin ....
		while ((getline(&line, &len, stdin)) != -1) {
			if(strstr(line, searchterm) != NULL)
				printf("%s", line);
		}
		exit(0);
	}
	for(int i = 2; i<argc; i++) {
		FILE * fd = fopen(argv[i], "r");
		if(fd == NULL) {
			printf("wgrep: cannot open file\n");
			exit(1);
		}
		while ((getline(&line, &len, fd)) != -1) {
			if(strstr(line, searchterm) != NULL)
				printf("%s", line);
		}
		free(line);
		fclose(fd);
	}
	exit(0);

}