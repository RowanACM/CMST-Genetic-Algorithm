
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

	char * winners = malloc(ind_size * populationSize);
	char * bestRef;//pointer to the best individual
	double best;
	double fitness;
	
	struct individual * ind = malloc(ind_size);

	for (int w = 0; w < populationSize; w++)//do populationSize tournaments
	{
		best = INT_MAX;//current best fitness(moved down here to reset best every time we set up a new tournament 
		for (int c = 0; c < tournSize; c++)//pull out tournSize of individuals
		{
			fitness = (*(struct individual *)(population + ind_size * (rand()%populationSize))).fitness;//pull out random individual and store its fitness
			
			if(fitness < best)//compare fitnesses to the current best(less is better)
			{
				best = fitness;//assign that fitness to best if its better
				bestRef = &fitness;//assign the bestRef pointer to that individual
			}						
		}//tourn loop
		
		for (int i = 0; i < ind_size; i++) //copy the individuals byte by byte
		{
			winners[(ind_size*w)+i] = (bestRef)[i];
		}//copy loop
					
	}//winners loop 
	
	printf("%i\n", populationSize);
	
	
	for (int i = 0; i < populationSize; i++)
	{		
		printf("%f \n", (*(struct individual*)(winners+(ind_size*i))).fitness);			
	}

	return winners;
}
