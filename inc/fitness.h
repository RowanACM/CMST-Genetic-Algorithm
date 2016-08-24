int getBias(struct individual ind, int x, int y);
int getMaxCost(int ** cost_matrix);
int getAvgCost(int ** cost_matrix);
int ** generateNewCostMatrix(struct individual ind, int ** cost_matrix);
int ** prims(int ** new_matrix, int root);
int * getBranches(int ** tree, int root);
int * getAdjacent(int ** mst, int node);
float fitness(struct individual ind, int root, int ** matrix);
