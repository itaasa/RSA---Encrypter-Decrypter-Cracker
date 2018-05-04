#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* The following will read and a text file (English Characters) and convert
 * it into numeric plain-text, then split it into message blocks.
 * The public key n and textfile will be give as parameters. */

int handle_args (char *, int);		//Checks if arguments are valid	
char* read_plaintext (char *);		//Reads plain text message from file
int* convert_num (char *);

int main (int argc, char ** argv) {

	int n = atoi(argv[2]);
	char* filepath = argv[1];

	if (handle_args(filepath, n) == 1){
		printf ("File will be read from: %s\n", argv[1]);	
		printf ("The public key is: %d\n", n);
		printf ("Reading from file...\n");
		char* alphatext = read_plaintext(argv[1]);
		int* numtext = convert_num(alphatext);
	}
}

int handle_args(char* filepath, int n){
	
	FILE* file = fopen (filepath, "r");
	
	if (file == NULL){
		printf ("%s - File does not exist.\n", filepath);
		return -1;
	}

	else if (n < 128){
		printf ("Public key is too small.\n");
		return -1;
	}

	else 
		return 1;
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
	
	fclose(file);
	return plaintext;
}

int* convert_num (char *plaintext) {
	int len = strlen (plaintext);

	int numplain [len];

	int i;
	for (int i=0; i<len; i++){
		numplain[i] = (int) plaintext [i];	
		printf("%d\n", numplain[i]);
	}

	
}

