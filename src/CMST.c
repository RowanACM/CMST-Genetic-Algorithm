/*
 *  Author: Nick LaPosta
 *  Version: 0.5
 *  Last Update: 3/31/2016
 *  Comments: Finished main function. Only need to finish file input.
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

char * generate_population(int pop_size, int genome_length)
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

int main(int argc, char * argv[])
{
	char * input_file     = argv[1];
	int num_generations   = atoi(argv[2]);
	int population_size   = atoi(argv[3]);
	int tourn_size        = atoi(argv[4]);
	double crossover_prob = atof(argv[5]);
	double mutation_prob  = atof(argv[6]);
	
	// TODO: Take input file and set globals from that
	int nodes = set_globals(input_file);
	int genome_length = (nodes * (nodes + 1)) / 2;
	individual_size = sizeof(struct individual) + (sizeof(int) * (genome_length));
	//
	
	char * population = generate_population(population_size, genome_length);
	for(int i = 0; i < num_generations; i++)
	{
		// Fitness
		for(int j = 0; j < population_size; j++)
		{
			fitness((struct individual *)(population + (j * individual_size)));
		}
		// End Fitness
		
		// Selection
  		char * breeding_pool = tournament_selection(population, population_size, tourn_size);
		// End Selection
		
		// Crossover
		char * children;
		for(int j = 0; j < population_size - 1; j = j + 2)
		{
			// TODO: Make this actually do stuff
			children = crossover(breeding_pool, crossover_prob);
			for(int k = 0; k < individual_size; k++)
			{
				population[(individual_size * j) + k] = children[k];
				population[(individual_size * (j + 1)) + k] = children[individual_size + k];
			}
			breeding_pool += individual_size * 2;
		}

		free(breeding_pool - ((population_size / 2) * individual_size * 2));
		free(children);
		// End Crossover

		// Mutation
		for(int j = 0; j < population_size; j++)
		{
			mutation((struct individual *) (population + (individual_size * j)), mutation_prob);
		}
		// End Mutation
	}
	free(population);
	return 0;
}
