// The fitness of an individual will be determined by the weight of the MST generated from its gnome and how well the 
// MST meets the criteria of our CMST


#include "individual.h"
#include "fitness.h"
#include "stack.c"

int getBias(int x, int y){
	int edge_count = (nodes * (nodes - 1)) / 2;
	if(x == y)
		return bias[x + (nodes * (nodes - 1))/2];
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

int * generateNewCostMatrix(int c_max){
	int * new_matrix = malloc(nodes);
	int P1 = 1, P2 = 1;
	int c_max = getMaxCost();

	for(int i = 0; i < nodes; i++){
		
		float * costs = malloc(i+1);
		new_matrix[i] = costs;

		for( int j = 0; j < i; i++)
			new_matrix[i][j] = cost_matrix[i][j] + (c_max * ((P1 * getBias(i, j)) + (P2 * (getBias(i, i) + getBias(j, j)))));

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
	weight = prims_weight;
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


/*
	TO DO-
	Garbage collection.
	Test.


*/

float fitness(struct individual * ind, int root)
{
	int * bias = (*ind).genome;
	int cost_avg = getAvgCost();
	int weight = 0;
	int branch_count = 0;
	int branches_over = 0;
	int max_cap;
	int cap_over = 0;

	int * new_matrix = generateNewCostMatrix(cost_max);
	int * mst = prims(new_matrix, root);
	int * branches = getBranches(mst, root);

	branch_count = sizeof(branches) / 4;

	for(int i = 0; i < branch_count; i++){
	
		if(branches[i] > max_cap){
			cap_over = cap_over + (branches[i] - max_cap);
			branches_over++;
		}
	}

	return weight + (cap_over * (branches_over / branch_count) * cost_avg);

}
