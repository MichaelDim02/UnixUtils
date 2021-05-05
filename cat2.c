#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

/* Unix concatination utility */

static void
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
		cat(stdin);
	} else {
		int i;
		for (i=1; i<argc; i++) {
			FILE *f = fopen(argv[i], "r");
			if (f) {
				cat(f);
				fclose(f);
			} else {
				fprintf(stderr, "cat: %s\n", strerror(errno));
			}	
		}
	}
	exit(0);
}
