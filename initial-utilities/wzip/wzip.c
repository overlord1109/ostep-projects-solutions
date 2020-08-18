#include<stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if(argc == 1) {
		printf("wzip: file1 [file2 ...]\n");
		exit(1);
	}
	int run_length = 0;
	char current_char;
	char buffer[512];
	
	for(int i = 1; i<argc; i++) {
		FILE * fd = fopen(argv[i], "r");
		if(fd == NULL) {
			printf("wzip: cannot open file\n");
			exit(1);
		}
		current_char = fgetc(fd);
		run_length++;
		while ((fgets(buffer, sizeof(buffer), fd)) != NULL) {
			for(int i = 0; buffer[i] != '\0'; i++) {
				if(buffer[i] == current_char) {
					run_length++;
				}
				else {
					fwrite(&run_length, sizeof(int), 1, stdout);
					fwrite(&current_char, sizeof(char), 1, stdout);
					current_char = buffer[i];
					run_length = 1;
				}
			}
		}
		fclose(fd);
	}
	fwrite(&run_length, sizeof(int), 1, stdout);
	fwrite(&current_char, sizeof(char), 1, stdout);
	exit(0);

}