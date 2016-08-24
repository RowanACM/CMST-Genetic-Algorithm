// The fitness of an individual will be determined by the weight of the MST generated from its gnome and how well the 
// MST meets the criteria of our CMST

#include "stack.c"
#include <stdlib.h>
#include <stdio.h>
#include "../inc/individual.h"
#include "../inc/fitness.h"
#include "../inc/CMST.h"


int getBias(struct individual ind, int x, int y){
	int edge_count = (nodes * (nodes - 1)) / 2;
	if(x == y)
		return (ind).genome[x + (nodes * (nodes - 1))/2];
	else
		return (ind).genome[(((x - 1) * (x - 2)) / 2) + (y - 1)];
}

int getMaxCost(int ** cost_matrix){
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

int getAvgCost(int ** cost_matrix){
	int cost;
	for(int i = 1; i < nodes; i++)
		for(int j = 0; j < i; j++)
			cost = cost + cost_matrix[i][j];
	return cost/((nodes * (nodes - 1)) / 2);
}

int ** generateNewCostMatrix(struct individual ind, int ** cost_matrix){
	int ** new_matrix = malloc(nodes);
	int P1 = 1, P2 = 1;
	int c_max = getMaxCost(cost_matrix);

	for(int i = 0; i < nodes; i++){
		
		int * costs = malloc(i+1);
		new_matrix[i] = costs;

		for( int j = 0; j < i; i++)
			new_matrix[i][j] = cost_matrix[i][j] + (c_max * ((P1 * getBias(ind, i, j)) + (P2 * (getBias(ind, i, i) + getBias(ind, j, j)))));

		// Copy node value
		new_matrix[i][i] = cost_matrix[i][i];
	}
	return new_matrix;
}


int ** prims(int ** new_matrix, int root){

	printf("Prims begin");

	int ** mst = malloc(nodes);
	int mst_index = 0;
	int nodes_visited[nodes];
	int node_index = 0;
	float min_cost = INT_MAX;
	float cost = 0;
	float prims_weight = 0;
	int temp = 0;

	nodes_visited[node_index] = root;
	node_index++;
	

	while(node_index < nodes){
		
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
	//weight = prims_weight;
	return mst;
}


int * getBranches(int ** tree, int root){

	int * branches = { 0 };
	struct stack s;
	int discovered = INT_MAX;
	int v = 0;	
	int * adj_root = getAdjacent(tree, root);

	for(int i = 0; i < (sizeof(adj_root) / 4); i++){
		realloc(branches, i + 1);
		push(s, adj_root[i]);
		while(s.top > 0){
			v = pop(s);
			if(tree[v][v] < INT_MAX){
				branches[i] = branches[i] + tree[v][v];
				tree[v][v] = INT_MAX;							
			}
			int * adjacent = getAdjacent(tree, v);
			for(int j = 0; j < (sizeof(adjacent) / 4); j++)
				push(s, adjacent[j]);
		}
	}	
	
	free(adj_root);

	return branches;
}


int * getAdjacent(int ** mst, int node){

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
	Test.


*/

float fitness(struct individual ind, int root, int ** matrix){
	int cost_avg = getAvgCost(matrix);
	int weight = 0;
	int branch_count = 0;
	int branches_over = 0;
	int max_cap = 12;
	int cap_over = 0;

	int ** new_matrix = generateNewCostMatrix(ind, matrix);
	int ** mst = prims(new_matrix, root);
	int * branches = getBranches(mst, root);

	branch_count = sizeof(branches) / 4;

	for(int i = 0; i < branch_count; i++){
	
		if(branches[i] > max_cap){
			cap_over = cap_over + (branches[i] - max_cap);
			branches_over++;
		}
	}

	free(new_matrix);
	free(mst);
	free(branches);

	int fit = weight + (cap_over * (branches_over / branch_count) * cost_avg);
	(ind).fitness = fit;
	return fit;
}
