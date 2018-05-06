#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* The following will read and a text file (English Characters) and convert
 * it into numeric plain-text, then split it into message blocks.
 * The public key n and textfile will be give as parameters. */

int handle_args (char *, int);		//Checks if arguments are valid	
char* read_plaintext (char *);		//Reads plain text message from file
int* convert_num (char *);
int* convert_block (int *, int );
int get_block_size (int );
int get_num_of_digits(int );
int get_block_len(int, int`);
int main (int argc, char ** argv) {

	int n = atoi(argv[2]);
	int* numtext;
	char* filepath = argv[1];

	if (handle_args(filepath, n) == 1){

		char* alphatext = read_plaintext(argv[1]);
		numtext = convert_num(alphatext);
		
		printf ("%d\n", get_block_size(n));
	}
}

//Checks if file does not exist, or if the public key is too small
//Returns 1 if criteria is met, else -1
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

	int* numplain = malloc (len);

	int i;
	for (int i=0; i<len; i++){
		numplain [i] = (int) plaintext [i];	
	}	

	return numplain;
}

int* convert_block (int* num_text, int block_size) {

}

int get_block_size(int n) {

	int min, keydigits = get_num_of_digits(n);
	
	min = keydigits / 3;
	
	return min;	
	
}

int get_block_len (int block_size, int len) {

	if (len % block_size == 0)
		return len / block_size;
	else
		return (len / block_size) + 1
}

int get_num_of_digits(int n) {

	int count = 0;
	
	while (n > 0) {	
		count++;
		n /= 10;
	}

	return count;	
}

