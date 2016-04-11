
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

int ind_size = 8;
/**
test method
**/
/**
int main(void)
{
	char * selection(char * population, int populationSize, int tournSize);
	char * pop = malloc(ind_size * 200);
	for (int i = 0; i < 200; i++)
	{
		struct individual * ind = malloc(ind_size);
		(*ind).fitness = rand() % 10;
		for (int j = 0; j < ind_size;  j++)
		{
		pop[(ind_size * i) + j] = ((char *) ind)[j];
		}
		printf("%d ",pop[ind_size *i]);
		free(ind);
	}

	char * newPop = selection(pop, 8, 5);
}
**/
char * tournament_selection(char * population, int populationSize, int tournSize)
{

	char * winners = malloc(ind_size * populationSize);
	char * bestRef;//pointer to the best individual
	double best = INT_MAX;//current best fitness
	double fitness;
	struct individual * ind = malloc(ind_size);

	for (int w = 0; w < populationSize; w++)//do populationSize tournaments
	{
		for (int c = 0; c < tournSize; c++)//pull out tournSize of individuals
		{
			fitness = (*(struct individual *)(population + ind_size * (rand()%populationSize))).fitness;//pull out random individual and store its fitness
			if(fitness < best)//compare fitnesses to the current best
			{
				best = fitness;//assign that fitness to best if its better
				bestRef = &fitness;//assign the bestRef pointer to that individual
			}
			for (int j = 0; j < ind_size; j++)//copy the individual into the winners array
			{
				for (int i = 0; i < ind_size; i++) //copy the individuals byte by byte
				{
				winners[(ind_size*j)+i] = ((char*)bestRef)[i];
				}
				
			}
		}
	}
	
	
	for (int i = 0; i < populationSize; i++)
	{
		ind = *(winners[i]);
		printf("%f \n",(*ind).fitness);
			
	}

	return winners;
}
