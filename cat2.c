#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h> <stdlib.h> <sys/types.h> <sys/stat.h>
#include <fcntl.h>

/* Unix concatination utility */

void
cat(FILE *f)
{
	int c;
	while ((c = getc(f)) != EOF) {
		putchar(c);
	}
}

void
main(int argc, char* argv[])
{
	if (argc == 1) {
		while(1) {
			cat(stdin);
		}
	} else {
		int i;
		for (i=1; i<argc; i++) {
			FILE *f = fopen(argv[i], "r");
			if (f) {
				cat(f);
				fclose(f);
			} else {
				fprintf(stderr, "cat: error opening %s\n", argv[i]);
			}	
		}
	} 
}
