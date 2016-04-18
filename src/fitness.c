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
#include "fitness.h"
#include "stack.c"

int getBias(int x, int y){
	if(x == y)
		return bias[x + edge_count];
	else
		return bias[(((x - 1) * (x - 2)) / 2) + (y - 1)];
}

int getMaxCost(){
	int max = cost_matrix[1][0];
	int cost;
	for(int i = 2; i < nodes; i++){
		for(int j = 0; j < i; j++){			
				
			cost = cost_matrix[i][j];
			
			if(max < cost)
				max = cost;
		}
	}
	return max;
}

int getAvgCost(){
	int cost;
	for(int i = 1; i < nodes; i++)
		for(int j = 0; j < i; j++)
			cost = cost + cost_matrix[i][j];
	return cost/edge_count;
}

int * generateNewCostMatrix(){
	int * new_matrix = malloc(nodes);
	int P1 = 1, P2 = 1;

	for(int i = 0; i < nodes; i++){
		
		float * costs = malloc(i+1);
		new_matrix[i] = costs;

		for( int j = 0; j < i; i++)
			new_matrix[i][j] = cost_matrix[i][j] + (cost_max * ((P1 * getBias(i, j)) + (P2 * (getBias(i, i) + getBias(j, j)))));

		// Copy node value
		new_matrix[i][i] = cost_matrix[i][i];
	}
	return new_matrix;
}


int * prims(int * graph, int root){

	printf("Prims begin");

	int mst[nodes];
	int mst_index = 0;
	int nodes_visited[nodes];
	int nodes_index = 0;
	float min_cost = INT_MAX;
	float cost = 0;
	float prims_weight = 0;
	int temp = 0;

	nodes_visited[nodes_index] = root;
	nodex_index++;
	

	while(nodex_index < nodes){
		
		int min_path[2];
		
		for(int i = 0; i <= node_index; i++){
			int node = nodes_visited[i];
			for(int j = node; j < nodes; j++){				
				if(j == node)
					for(int k = 0; k < node; k++){
						cost = new_matrix[j][k];
						if(cost < min_cost){
							min_cost = cost;
							min_path[0] = node;
							min_path[1] = k;
						}
					}
				else
					cost = new_matrix[j][node];
				if(cost < min_cost){
					min_cost = cost;
					min_path[0] = j;
					min_path[1] = node;
				}
			}
		}
		
		prims_weight = prims_weight + min_cost;
		min_cost = INT_MAX;
		new_matrix[min_path[0]][min_path[1]] = INT_MAX;
		mst[mst_index] = min_path;
		mst_index++;
		node_index++;
	}
	
	printf("Prims end");
	mst_wight = prims_weight;
	return mst;
}


float * getBranches(int * tree, int root){

	int * branches = { 0 };
	struct stack s;
	int discovered = INT_MAX;
	
	int * adj_root = getAdjacent(tree, root);

	for(int i = 0; i < (sizeof(adj_root) / 4); i++){
		realloc(branches, i + 1);
		push(s, adj_root[i])
		while(s.top > 0){
			v = pop(s);
			if(new_matrix[v][v] < INT_MAX){
				branches[i] = branches[i] + new_matrix[v][v];
				new_matrix[v][v] = INT_MAX;							
			}
			int * adjacent = getAdjacent(tree, v);
			for(int j = 0; j < (sizeof(adjacent) / 4); j++)
				push(s, adjacent[j]);
		}
	}	

	return branches;
}


int * getAdjacent(int * mst, int node){

	int * adjacent = { 0 };
	int adj_node = 0;
	int index = 0;

	for(int i = 0; i < nodes - 1; i++){
		if(node == mst[i][0])
			adj_node == mst[i][1];	
		else if(node == mst[i][1])
			adj_node == mst[i][0];
		if(adj_node != 0){
			adjacent[index] = adj_node;
			adjacent = (int *) realloc(adjacent, 1);
			adj_node = 0;
			index++;
		}
	}

	adjacent[index] = 0;

	return adjacent;
}




float fitness(struct individual * ind, int root)
{
	int * bias = (*ind).genome;
	int edge_count = (nodes * (nodes - 1)) / 2;

	int cost_max = getMaxCost();
	int cost_avg = getAvgCost();
	int mst_weight = 0;
	int branch_count = 0;
	int branches_over = 0;
	int cap_over = 0;

	int * new_matrix = generateNewCostMatrix();

	

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
