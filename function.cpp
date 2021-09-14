#include "function.h"






list<node> mFunction::my_BFS(const graph& G,node s,node_array<int>& dist,node_array<edge>& pred,node_array<int>& color){
	list<node> visited;
	node_array<bool> marked(G,false);
	node t,u;
	queue<node> S;
	edge e;
	

	S.append(s);
	marked[s]=true;
	visited.append(s);
	color[s]=0;

	while(!S.empty()){
		t = S.pop();
		forall_adj_edges(e,t){
			u=G.target(e);
		if(marked[u]==false){
			marked[u] = true;
			S.append(u);
			dist[u]=dist[t]+1;
		pred[u]=e;
		if (color[u]==-1 && dist[u]%2==0){
			color[u]= 0;
		}
			else
			{
			 color[u]=1;
			}
		visited.append(u);
		}
		}

		
		}

return visited;
	};


bool mFunction::my_bipar_checker(const graph& G, list<node>& V1, list<node>& V2){

	bool is_bipartite=true;
	node s = G.choose_node();//***********
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

			if(color[q]==color[f]){
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

			if (is_bipartite == false){
				list<node> path;
				queue<node> F;
				node_array<edge> pred2(G);
				node_array<edge> succ(G);
				F.append(s);
				int stop=0;
				path.append(s);
				while(stop==0){
					q= F.pop();
					forall_adj_edges(e,q){
					 f=G.target(e);
					 	
					 if (color[q] == color[f]){
					 	G.print_node(q);
					 	cout << endl;
					 	G.print_node(f);
					 	cout << endl;
					 	pred2[f]=e;
						cout << "stop" << endl;
						path.append(f);
						//path.append(s);
						succ[q]=e;
						stop =1;
						
					}
					else{
					//	path.append(f);
					//	pred2[f]=e;
					//	succ[q]=e;
					}
					F.append(f);
				}
				}
				


				cout << "seed node";
				G.print_node(s);
				cout << endl;
				cout << "path" << endl;
					
				forall(q,path){
				G.print_node(q);
				}
				cout << endl;
				forall_nodes(q,G) {
   			 if (pred2[q]!=nil) G.print_edge(pred2[q]);
				}
			cout << endl;
				cout << endl;
				forall_nodes(q,G) {
   			 if (succ[q]!=nil) G.print_edge(succ[q]);
				}




		}




		/*	forall_nodes(q,G) {
   			 if (pred[q]!=nil) G.print_edge(pred[q]);
			}
			cout << endl;
			G.print_node(s);
				cout << endl;


*/
	
	cout << endl;
	/*for(color[q]!=nil)	{
		if(color[q]==color[q+1]){
		is_bipartite = false;
		G.print_node(q);
		cout << endl;
		}
		}
	
	if (is_bipartite == true){
		forall_nodes(q,G){}
}
*/
	

	 	
return is_bipartite;
};











