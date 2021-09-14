#ifndef FUNCTION
#define FUNCTION

#include "LEDA/core/queue.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "LEDA/graph/graph.h"
#include "LEDA/graph/edge_array.h"
#include "LEDA/graph/node_array.h"
#include "LEDA/graph/node_list.h" 
#include "LEDA/core/list.h"
#include "LEDA/graph/graph_iterator.h"



using namespace std;
using namespace leda;


class mFunction
{
public:
	mFunction(){}

	list<node> my_BFS(const graph& G,node s,node_array<int>& dist,node_array<edge>& pred,node_array<int>& color);

	bool my_bipar_checker(const graph& G, list<node>& V1, list<node>& V2);
	

};


#endif