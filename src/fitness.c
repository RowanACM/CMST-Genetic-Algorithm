// The fitness of an individual will be determined by the weight of the MST generated from its gnome and how well the 
// MST meets the criteria of our CMST

// Representation of an upper triangle matrix using a 2D array
// For any path (a, b), the path weight can be found at the 2D array location
// begin
// if b < a
// Array[b][a]
// else
// Array[a][b]
// end


// A single individual is passed as a parameter
// We are given the pointer to the individual within the population

#include "individual.h"

int getCost(int a, int b, int * matrix){
	if(b > a) 
		return matrix[b][a];
	else
		return matrix[a][b];
}

int getMaxCost(){
	int max = getCost(1,0, cost_matrix);
	int cost;
	for(int i = 1; i < nodes; i++){
		for(int j = 0; j < i; j++){			
				
			cost = getCost(i, j, cost_matrix);
			
			if(max < cost)
				max = cost;
		}
	}
}


int* generateNewCostMatrix(){
	int * new_matrix = malloc(nodes);
	for(int i = 0; i < nodes; i++)
		
		float * costs = malloc(i+1);
		new_matrix[i] = costs;

		for( int j = 0; j <= i; i++){
		
			new_matrix[i][j] = getCost[i][j] + (cost_max * ((P1 * genome[i][j]) + (P2 * (genome[i][i] + genome[j][j]))));
		
		}
}


void fitness(individual ind)
{
	//ind.genome
	int cost_max = getMaxCost();
	float P1 = 1, P2 = 1;

	int * new_matrix = malloc(nodes);

}
// Obtain the gnome from the individual

// Obtain the largest edge weight, assign that value to C_max
// Assign values to P_1 and P_2, values must be between 0.0 & 1.0
// Using the function C'_ij = C_ij + P_1 * (C_Max) * (b_ij) + P_2 * (C_Max) * (b_i + b_j) to build a new graph
// where C'_ij is the new weight of the edge (i, j)
// C'_ij should be an integer, thus the P compontents of the equation should be converted to integers before the addition
// A new graph should be created/represented using these values

// Apply prims to our new graph, an array of paths should be obtained
// Record the total weight of this graph, this will be used to determine the individual's fitness value.

// We need a function to return an array of branch capacities
/*
begin

	int[] Branches;
	Stack S;
	int final discovered = -1;

 	RootDFS(Tree, root){
		int index = 0;
		for each vertice v Tree.adjacent(root){
			Branches = realloc(index+1);
			S.push(v)
			while S is not empty
				v = S.pop()
			        if v is not labeled as discovered:
				label v as discovered{
					Branches[i] = Branches[i] + MST[v][v];
					MST[v][v] = discovered; 
				}
			        
			        for all edges from v to w in G.adjacentEdges(v) do
			        	S.push(w)
			index++;
		}
	}

end
*/
// 
// Total fitness should be equal to the weight of the graph plus some value determined by the number of branches and/or the weight of the branches.
// Fitness Variables
//	Median/Mean/Maximum/Minimum weight of edges
//	'	'	'	'	' of nodes
//	Weight of spanning tree
//	Number of branches over the capacitance, and the amount each are over by
//
/*

h(tree) = W_tree + (C_over(Branches_over/Brances_total)(W_avg));

*/
