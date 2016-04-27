#include "mutation.h"
#include "stdlib.h"
#include "time.h"

void mutation(stuct individual * ind, double mut_prob){
	
	srand(time(NULL));
	double random_number;
	double max_prob = 100;

	double chromo_max = 100;
	double chromo_min = 1;

	for(int i = 0; i < gnome_length; i++){
		random_number = rand() / (RAND_MAX / max_prob);
		if(random_number <= mut_prob)
			(* ind).genome[i] = rand() % chromo_max + chromo_min;
	}
}

