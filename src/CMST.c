/*
 *  Author: Nick LaPosta
 *  Version: 0.5
 *  Last Update: 3/31/2016
 *  Comments: Added Comments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/CMST.h" 
#include "../inc/individual.h"
#include "../inc/fitness.h"
#include "../inc/selection.h"
#include "../inc/crossover.h"
#include "../inc/mutation.h"

#define nodes 13


int set_globals(char * filename)
{
	// TODO: File IO
	return 5;
}

/*
 *  This function creates a set or randomized individuals
 *
 *   param - int pop_size: Number of individuals to create
 *   param - int genome_length: Length of each individual's genome
 *
 *  return - pop: A pointer to the generated set of individuals
 */
char * generate_population(int individual_size, int pop_size, int genome_length)
{
	char * pop = malloc(individual_size * pop_size);
	
	struct individual * ind = malloc(individual_size);
	(*ind).fitness = -1.0;
	for(int i = 0; i < pop_size; i++)
	{
		for(int j = 0; j < genome_length; j++)
		{
			(*ind).genome[j] = 10 + j;
		}
		for(int j = 0; j < individual_size; j++)
		{
			pop[(individual_size * i) + j] = ((char *) ind)[j];
		}
	}
	free(ind);
	
	return pop;
}

/*
 *  This function handles all of the Genetic Algorithm execution. Calls all of the GA functions and keeps the data organized.
 */
int main(int pop_size)
{
	
	// TODO: Take input file and set globals from that
	int genome_length = (nodes * (nodes + 1)) / 2;
	int individual_size = sizeof(struct individual) + (sizeof(int) * (genome_length));

	char * pop = generate_population(individual_size, pop_size, genome_length);
	
	for(int i = 0; i < pop_size; i++){
		fitness(((struct individual *)pop)[i], 1);
		printf("%d, %d", i, ((struct individual *)pop)[i].fitness);
	}


	return 0;
}
