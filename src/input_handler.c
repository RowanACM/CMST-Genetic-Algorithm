#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ** getInputMatrix(char *filename, int nodes){

	FILE * input = fopen(filename, "r");
	int ** cost_matrix = malloc(nodes);
	char s[2];
	char temp;

	for(int i = 0; i < nodes; i++){
		int cols[i+1];
		cost_matrix[i] = cols;
		for(int j = 0; j <= i; j++){
			s[0] = fgetc(input); 
			s[1] = fgetc(input);
			fgetc(input); // Skip over tab or newline
			cols[j] = atoi(s);
		}
	}

	return cost_matrix;
}


