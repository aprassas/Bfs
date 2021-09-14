#ifndef GENERATOR
#define GENERATOR

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <chrono>
#include "LEDA/graph/graph.h"
#include "LEDA/graph/edge_array.h"
#include "LEDA/graph/node_array.h"
#include "LEDA/graph/node_list.h" 
#include "LEDA/core/list.h"
#include "LEDA/graph/graph_iterator.h"

using namespace std;
using namespace leda;

class mgraphgen
{
public:
	mgraphgen(){}

	void square(graph& G,int m);

	void leveled(graph& G,int m);

	void circle(graph& G,int m);

};


#endif