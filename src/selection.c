
/*
 * selection.c
 *
 *  Created on: Mar 30, 2016
 *      Author: Sean Mulhall & Brent Rickards
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "individual.h"
#include "selection.h"


char * tournament_selection(char * population, int populationSize, int tournSize)
{

	char * winners = malloc(individual_size * populationSize);
	char * bestRef;//pointer to the best individual
	double best;
	struct individual * current_fitness;
	int genome_length = 15;
	
	struct individual * ind = malloc(individual_size);

	for (int w = 0; w < populationSize; w++)//do populationSize tournaments
	{
		best = INT_MAX;//current best fitness(moved down here to reset best every time we set up a new tournament) 
		for (int c = 0; c < tournSize; c++)//pull out tournSize of individuals
		{
			current_fitness = (struct individual *)(population + individual_size * (rand()%populationSize));//pull out random individual and store its fitness			
									
			if((*current_fitness).fitness < best)//compare fitnesses to the current best(less is better)
			{
				best = (*current_fitness).fitness;//assign that fitness to best if its better
				bestRef = current_fitness;//assign the bestRef pointer to that individual
			}						
		}//tourn loop
		
		for (int i = 0; i < individual_size; i++) //copy the individuals byte by byte
		{
			winners[(individual_size*w)+i] = bestRef[i];
		}//copy loop
					
	}//winners loop 
	
	printf("%i\n", genome_length);
	
	
	for (int i = 0; i < populationSize; i++)
	{		
		printf("Fitness:%f \n", (*(struct individual*)(winners+(individual_size*i))).fitness);
		printf("genomes \n");
		
		for (int j = 0; j < genome_length; j++)
		{
		printf("%i \n", (*(struct individual*)(winners+(individual_size*i))).genome[j]);
		}
		
		printf("\n");		
	}

	return winners;
}
