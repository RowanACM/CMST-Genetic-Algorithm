/*
 *  Author: Nick LaPosta
 *  Version: 0.5
 *  Last Update: 3/31/2016
 *  Comments: Added Comments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CMST.h" 
#include "individual.h"
#include "fitness.h"
#include "selection.h"
#include "crossover.h"
#include "mutation.h"

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
char * generate_population(int pop_size, int genome_length)
{
	char * pop = malloc(ind_size * pop_size);
	
	struct individual * ind = malloc(ind_size);
	for(int i = 0; i < pop_size; i++)
	{
		(*ind).fitness = rand() % 10;
		printf("%f \n",(*ind).fitness);
		for(int j = 0; j < genome_length; j++)
		{
			(*ind).genome[j] = 10 + j;
		}
		for(int j = 0; j < ind_size; j++)
		{
			pop[(ind_size * i) + j] = ((char *) ind)[j];
		}

	}
	free(ind);

	return pop;
}

/*
 *  This function handles all of the Genetic Algorithm execution. Calls all of the GA functions and keeps the data organized.
 */
int main(int argc, char * argv[])
{
	int nodes = 5;
	int genome_length = (nodes * (nodes + 1)) / 2;
	ind_size = sizeof(struct individual) + (sizeof(int) * (genome_length));
	//char *tournament_selection(char * population, int populationSize, int tournSize);
	ind_size = 76;
	char *pop = generate_population(10, genome_length);
	char * newPop = tournament_selection(pop, 8, 5);
	
}
