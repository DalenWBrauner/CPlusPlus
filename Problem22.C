#include<iostream>	// input/output stream
#include<stdio.h>	// standard input/output (.h?)
#include<cstdio>	// C standard input/output ?
#include<cstdlib>	// C standard library ?

// main(void) runs automagically
int main(void) {

	// Instantiate file structures
	FILE *infile, *outfile;

	// Open 'infile'
	infile = fopen("names.txt", "r");
	if (infile == NULL) {
		fprintf(stderr, "Can't read names.txt!\n");
		exit(1);
	}

	// Open 'outfile'
	outfile = fopen("scores.txt", "w");
	if (outfile == NULL) {
		fprintf(stderr, "Can't write to scores.txt!\n");
		exit(1);
	}

	printf("(Psst, I finished running.)\n\t\tLove, Problem22.C\n");
}
