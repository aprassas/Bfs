#include "LEDA/graph/basic_graph_alg.h"
#include <fstream>
#include "generator.h"
#include "LEDA/graph/graph_misc.h"
#include "LEDA/core/queue.h"
#include <ctime>
list<node> my_BFS(const graph& G,node s,node_array<int>& dist,node_array<edge>& pred,node_array<int>& color);
bool my_bipar_checker(const graph& G, list<node>& V1, list<node>& V2);




int main()
{
	
	
	
	graph SQ;
	graph CI;
	graph LV;
	mgraphgen Ggen;


	list<node> V1;
	list<node> V2;
	list<node> A;
	list<node> B;
	bool led,myBF;



int a[3]={10000,40000,90000};
for (int i = 0; i < 3 ; ++i)  
{	
	
	Ggen.square(SQ,a[i]);
	cout << "tetragona me "<< a[i] << " nodes" << endl;
	clock_t clock_start, clock_stop;
	clock_start = std::clock();

	led=Is_Bipartite(SQ, A, B);

	clock_stop = std::clock();
	double elapsedTime = (clock_stop - clock_start)*10000.0/(double)CLOCKS_PER_SEC;
	cout << "o xronos is_bipartite ths leda" <<"einai " << elapsedTime << "ms" << endl;

	clock_t clock_start2, clock_stop2;
	clock_start = std::clock();

	myBF=my_bipar_checker(SQ,V1,V2);

	clock_stop = std::clock();
	double elapsedTime2 = (clock_stop - clock_start)*10000.0/(double)CLOCKS_PER_SEC;
	cout << "o xronos gia my_bipar_checker"<<" einai: "  << elapsedTime2 << "ms" << endl;

cout << led << endl;
SQ.clear();
A.clear();
B.clear();
V1.clear();
V2.clear();

}

 int c[3]={500,1000,1500};
 cout << endl;
for (int i = 0; i < 3 ; ++i)  
{	
	
	Ggen.leveled(LV,c[i]);
	cout << "epipeda me "<< c[i] << " nodes" << endl;
	clock_t clock_start, clock_stop;
	clock_start = std::clock();

	led=Is_Bipartite(LV, A, B);

	clock_stop = std::clock();
	double elapsedTime = (clock_stop - clock_start)*10000.0/(double)CLOCKS_PER_SEC;
	cout << "o xronos is_bipartite ths leda" <<"einai " << elapsedTime << "ms" << endl;

	clock_t clock_start2, clock_stop2;
	clock_start = std::clock();

	myBF=my_bipar_checker(LV,V1,V2);

	clock_stop = std::clock();
	double elapsedTime2 = (clock_stop - clock_start)*10000.0/(double)CLOCKS_PER_SEC;
	cout << "o xronos gia my_bipar_checker"<<" einai: "  << elapsedTime2 << "ms" << endl;

LV.clear();
A.clear();
B.clear();
V1.clear();
V2.clear();

}

cout << endl;
int b[3]={10001,40001,90001};
 //o kuklos bgainei ektws mnhmhs me ligotera nodes omws leitourgei 
for (int i = 0; i < 3 ; ++i)  
{	
	
	Ggen.circle(CI,b[i]);
	cout << "kuklos me "<< b[i] << " nodes" << endl;
	clock_t clock_start, clock_stop;
	clock_start = std::clock();

	led=Is_Bipartite(CI, A, B);

	clock_stop = std::clock();
	double elapsedTime = (clock_stop - clock_start)*10000.0/(double)CLOCKS_PER_SEC;
	cout << "o xronos is_bipartite ths leda" <<"einai " << elapsedTime << "ms" << endl;

	clock_t clock_start2, clock_stop2;
	clock_start = std::clock();

	myBF=my_bipar_checker(CI,V1,V2);

	clock_stop = std::clock();
	double elapsedTime2 = (clock_stop - clock_start)*10000.0/(double)CLOCKS_PER_SEC;
	cout << "o xronos gia my_bipar_checker"<<" einai: "  << elapsedTime2 << "ms" << endl;
	cout << myBF << endl;
CI.clear();
A.clear();
B.clear();
V1.clear();
V2.clear();

}

























	return 0;
}

bool my_bipar_checker(const graph& G, list<node>& V1, list<node>& V2){

	bool is_bipartite=true;
	node s = G.choose_node(); //epilogh tyxaiou kombou
	node_array<int> dist(G,0);
	node_array<edge> pred(G);
	list<node> visited;
	node_array<int> color(G,-1);
	visited = my_BFS(G,s,dist,pred,color); 
	
	node q,f;
	edge e;
	forall_nodes(q,G){
		 
		forall_adj_edges(e,q){
			f=G.target(e);

			if(color[q]==color[f]){ //elegxos gia an to diagramma einai dimeres 
			is_bipartite = false;
			/*cout << "false ";
			G.print_node(f);
			cout << endl;*/
			break;
			}
		
			}		
			
			if(is_bipartite==false){
				break;
			}
	}	

	//#####
			if (is_bipartite == false){		//an den einai dimeres briskoume to path me paromoio BFS 
				
				queue<node> F;
				node_array<edge> pred2(G);
				node_array<edge> succ(G);
				F.append(s);
				int stop=0;
				V1.append(s);
				while(stop==0){
					q= F.pop();
					forall_adj_edges(e,q){
					 f=G.target(e);
					 	
					 if (color[q] == color[f]){
					 	pred2[f]=e;
					
						//V1.append(f);
						
						succ[q]=e;
						stop =1;
						
					}
					
					F.append(f);
				}
				}
				}
				
				
				if(is_bipartite==true){ //an to grafima einai dimeres tote epistrefoume ta 2 sunola
					node b;
					forall_nodes(b,G){
					if(color[b]==0)
						V1.append(b);
						else{
							V2.append(b);
						}
				}
	 	}
	 	
return is_bipartite;
}



list<node> my_BFS(const graph& G,node s,node_array<int>& dist,node_array<edge>& pred,node_array<int>& color){
	list<node> visited;
	node_array<bool> marked(G,false);
	node t,u;
	queue<node> S;
	edge e;
	//BFS me pinaka color 

	S.append(s);
	marked[s]=true;
	visited.append(s);
	color[s]=0; //xrwma 0 gia prasino 1 gia mple

	while(!S.empty()){
		t = S.pop();		
		forall_adj_edges(e,t){	//gia ola ta geitonika nodes 		
			u=G.target(e);		//pairnoume to target node ths kathe akmhs
		if(marked[u]==false){		//an den to exoume dei to markaroume
			marked[u] = true;		
			S.append(u);		//to bazoyme sthn lista
			dist[u]=dist[t]+1;	//tou anatheoume to epipedo pou anoikei
		pred[u]=e;
		if (color[u]==-1 && dist[u]%2==0){	//an to upoloipo einai mhden tote einai artios kombos alliws perittos
			color[u]= 0;
		}
			else
			{
			 color[u]=1;
			}
		visited.append(u); //lista olwn twn kombwn pou exoume episkeythei
		}
		}

		
		}

return visited;
	}