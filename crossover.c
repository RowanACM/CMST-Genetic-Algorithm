#include invdividual.h;

char * crossover(char * parents, double crossover_prob)
{

	double probability = (rand() % 100) / 100; //will make a random decimal value between 0 and 1
	int crossover_point = rand() % ((genome_size - 1) + 1);  //Creates a rand and will split the genome at this point
	char * offspring; //pointer to be returned from parent crossover.
	offspring = malloc(individual_size * 2); //Allocating the space for the offspring

	if (probability < crossover_prob) {


		struct individual child1;
		struct individual child2;


		for (int i = 0; i < crossover_point; i++) {
			//offspring[0].genome[i] = parent[0].genome[i];
			//offspring[1].genome[i] = parent[1].genome[i];
			child1.genome[i] = parent[0].genome[i];
			child2.genome[i] = parent[1].genome[i];
		}
		for (int i = crossover_point; i < genome_length; i++) {
			//offspring[1].genome[i] = parent[0].genome[i];
			//offspring[0].genome[i] = parent[1].genome[i];
			child2.genome[i] = parent[0].genome[i];
			child1.genome[i] = parent[1].genome[i];
		}
		offspring[0] = child1;
		offspring[12] = child2;


	}
	else {
		offspring = parents;
	}


	return offspring;
}