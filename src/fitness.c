// The fitness of an individual will be determined by the weight of the MST generated from its gnome and how well the 
// MST meets the criteria of our CMST

// Representation of an upper triangle matrix using a 2D array
// For a any path (a, b), the path weight can bb found at the 2D array location
// begin
// if b < a
// Array[b][a - b]
// else
// Array[a][b - a]
// end
// Paths of the form (a, a) and (b, b) return the weigth of the node a and b respectively.


// A single individual is passed as a parameter
// We are given the pointer to the individual within the population

// Obtain the gnome from the individual

// Obtain the largest edge weight, assign that value to C_max
// Assign values to P_1 and P_2, values must be between 0.0 & 1.0
// Using the function C'_ij = C_ij + P_1 * (C_Max) * (b_ij) + P_2 * (C_Max) * (b_i + b_j) to build a new graph
// where C'_ij is the new weight of the edge (i, j)
// C'_ij should be an integer, thus the P compontents of the equation should be converted to integers before the addition
// A new graph should be created/represented using these values

// Apply prims to our new graph, an array of paths should be obtained
// Record the total weight of this graph, this will be used to determine the individual's fitness value.

// Determing the capacitance of the MST's branches
// Given an MST (An array of paths) of size N-1 (N being the number of nodes) represented byt the variable MST
// And an integer value that represents the root node for the MST represented by the variable R
// The capcitance value of each branc of the MST will be stored in an array represented by the variabel Branches
// The length of this array will give us the number of branches in the CMST and the weight of each branch
// begin
//
//	R
//	MST
//	Branches
//	root = R
//	index = 0
//	partner (represnts the other node in a root node path, example (root, x) or (x, root), x is the partner.
//
//	Iterate through the MST to find the first instance of a path that contains the root
//		When root is found,
//			Get the capacitance of the partner and set Branches[i] = Branches[i] + partner_cap
//			Set root = partner
//		If root is not found,
//			Set root = R
//			index = index + 1
//
// end
