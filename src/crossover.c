#include <stdlib.h>
#include "individual.h"
#include "crossover.h"

char * crossover(char * parents, float crossover_prob)
{

	float probability = (rand() % 100) / 100; //will make a decimal value between 0 and 1


	if (probability < crossover_prob) {
		
		int crossover_point = rand() % ((genome_size - 1) + 1);  //Creates a rand and will split the genome at this point
		char * offspring; //pointer to be returned from parent crossover.
		offspring = malloc(individual_size * 2); //Allocating the space for the offspring
	
		struct individual * child1 =  malloc(individual_size);
		struct individual * child2 =  malloc(individual_size);


		for (int i = 0; i < crossover_point; i++) {

			child1->genome[i] = parents[0].genome[i];
			child2->genome[i] = parents[individual_size + 1].genome[i];  //index for parents was 1
			
		}
		for (int i = crossover_point; i < genome_length; i++) {

			child2->genome[i] = parents[0].genome[i];
			child1->genome[i] = parents[individual_size + 1].genome[i];  //index for parents was 1
			
		}
		offspring[0] = child1;
		offspring[individual_size + 1] = child2;  //index was 12

		return offspring;
	}

	return parents;
}
