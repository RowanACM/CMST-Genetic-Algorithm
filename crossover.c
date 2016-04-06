#include invdividual.h;

char * crossover(char * parents), double crossover_prob)
{
	
	double probability = (rand() % 100) / 100;
	int crossover_point = rand() % ((genome_size - 1) + 1); 
	char * offspring; //pointer to be returned from parent crossover.
	

	offspring = malloc(individual_size * 2); //pop_size is not definite population size. otherwise this allocates space for offspring.	
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

	
	
	return offspring;
}