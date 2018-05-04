#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* The following will read and a text file (English Characters) and convert
 * it into numeric plain-text, then split it into message blocks.
 * The public key n and textfile will be give as parameters. */

char* convert_alpha (char *);			
char* read_plaintext ();		//Reads plain text message from file

int main (int argc, char ** argv) {

	int n;

	n = atoi(argv [2]);

	printf ("File will be read from: %s\n", argv[1]);	
	printf ("The public key is: %d\n", n);

	printf ("Reading from file...\n");
	printf ("%s", read_plaintext(argv[1]));
}


char* read_plaintext(char *filepath) {
	
	char* plaintext;
	long file_size;
	FILE *file = fopen (filepath, "r");
	
	if (file == NULL){
		printf ("File: %s does not exist\n", filepath);
		return NULL;
	}	

	//Finds the size of the file
	fseek (file, 0, SEEK_END);
	file_size = ftell (file);

	plaintext = malloc (file_size);
	
	int i;
	fseek(file, 0, SEEK_SET);
	
	for (i=0; i<file_size; i++){
		plaintext[i] = fgetc (file);
	}	

	return plaintext;
}

int* convert_alpha (char *plaintext) {

}

