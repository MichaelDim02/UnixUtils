#include <stdlib.h>
#include <stdio.h>

/* Unix concatination utility */

void
cat(char* filename)
{
	FILE *f = fopen(filename, "r");
	if (f) {
		int c;
		while ((c = getc(f)) != EOF) {
			putchar(c);
		}
		fclose(f);
	} else {
		printf("%s: No such file or directory\n", filename);
	}
}

void
main(int argc, char* argv[])
{
	if (argc == 1) {
		char buffer[256];
		while(1) {
			fgets(buffer, 256, stdin);
			printf("%s", buffer);
		}
	} else {
		int i;
		for (i=1; i<argc; i++) {
			cat(argv[i]);
		}
	} 
}
