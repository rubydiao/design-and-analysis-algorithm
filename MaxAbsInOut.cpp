#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<math.h>

using namespace std;

int Max = 0;

class Graph{
	public:
	int n;	
	int matrix[100][100];
	Graph(){
		for(int i=0;i<100;i++){
			for(int j=0;i<100;i++){
				matrix[i][j] = 0;
			}
		}
	}
	
};

void DFS(Graph *g,bool visited[],int vertex){
	
	if(vertex>g->n){
		return;
	}
	
	if(visited[vertex-1]==false){
		int in=0,out=0;
		for(int i=0;i<g->n;i++){
			if(g->matrix[vertex-1][i]==1){
				out++;
			}
			if(g->matrix[i][vertex-1]==1){
				in++;
			}
		}
		int diff = abs(in-out);
		if(diff>Max){
			Max = diff;
		}
	}

	
	visited[vertex-1] = true;
	
	for(int i=0;i<g->n;i++){
		if(!visited[i] && g->matrix[vertex-1][i]==1){

			DFS(g,visited,i+1);
		}
	}
	
}


int main(){
	
	int V,E;
	
	cin >> V;
	cin >> E;
	
	Graph *g = new Graph;
	g->n = V;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			g->matrix[i][j] = 0;
		}
	}
	
	for(int i=0;i<E;i++){
		int vertex,edges;
		cin >> vertex;
		cin >> edges;

		g->matrix[vertex-1][edges-1] = 1;
	}
	

	bool visited[V];
	
	for(int i=0;i<V;i++){
		visited[i] = false;
	}
	

	for(int i=0;i<V;i++){
		DFS(g,visited,i);
	}
	
	
	cout << Max;
	
}


