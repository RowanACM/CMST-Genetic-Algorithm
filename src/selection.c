#include <stdlib.h>

#include "individual.h"
#include "selection.h"

char * tournament_selection(char * population, int pop_size, int tourn_size)
{
	return malloc(individual_size * pop_size);
}
