#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

using namespace std;

int Way = 0;

class Graph{
	public:
	int n;	
	int matrix[100][100];
	
};

void DFS(Graph *g,bool visited[],int vertex,int Stop){
	
	if(vertex>g->n){
		return;
	}
	
	if(vertex==Stop){
		Way++;
		return;
	}
	
	visited[vertex-1] = true;
	

	for(int i=0;i<g->n;i++){
		if(!visited[i] && g->matrix[vertex-1][i]==1){
			DFS(g,visited,i+1,Stop);
			visited[vertex-1] = false;
		}
	}
	
}


int main(){
	int V,E,Start,Stop;
	
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
	
	/*for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}*/
	
	bool visited[V];
	
	for(int i=0;i<V;i++){
		visited[i] = false;
	}
	
	cin >> Start;
	cin >> Stop;
	
	
	DFS(g,visited,Start,Stop);
	
	cout << Way;
	
}


