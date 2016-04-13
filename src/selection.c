
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
	double best;// = INT_MAX;//current best fitness commenting this out for now, because i dont think best will reset to max_int after we enter the loop
	double fitness;
	
	struct individual * ind = malloc(ind_size);

	for (int w = 0; w < populationSize; w++)//do populationSize tournaments
	{
		best = INT_MAX;//current best fitness
		for (int c = 0; c < tournSize; c++)//pull out tournSize of individuals
		{
			fitness = (*(struct individual *)(population + ind_size * (rand()%populationSize))).fitness;//pull out random individual and store its fitness
			
			if(fitness < best)//compare fitnesses to the current best(less is better)
			{
				best = fitness;//assign that fitness to best if its better
				bestRef = &fitness;//assign the bestRef pointer to that individual
			}						
		}//tourn loop
		
		/*for (int j = 0; j < ind_size; j++)//copy the individual into the winners array
		may take this out, J was originally the position in winners we wanted to store in, but we can 
		probably just use w, since thats the number of tournaments we've done so far. 
		...
		also moved the copy loop down here. The way it was before, we would have been copying bestRef every single time the tourn loop looped
		*/
		
		for (int i = 0; i < ind_size*4; i++) //copy the individuals byte by byte
		{//might want to think about changing the bound to ind_size*4, since and int is 4 times the size of a char
		 //and if we cast the winner as a char, we might lose those 3 extra bytes. not sure yet, will talk to nick
			winners[(ind_size*w)+i] = ((char*)bestRef)[i];
		}//copy loop
					
	}//winners loop 
	
	
	for (int i = 0; i < populationSize; i++)
	{
		
		printf("%d \n", winners[i*ind_size]);
			
	}

	return winners;
}
