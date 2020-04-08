#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<limits>

using namespace std;


int Way = 0;
int Min;
int temp = 0;

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
		if(temp<Min){
			Min = temp;
		}
		return;
	}
	
	visited[vertex-1] = true;
	

	for(int i=0;i<g->n;i++){
		if(!visited[i] && g->matrix[vertex-1][i]>0){
			temp += g->matrix[vertex-1][i];
			
			DFS(g,visited,i+1,Stop);
			
			temp -= g->matrix[vertex-1][i];
			
			visited[vertex-1] = false;
		}
	}
	
}


int main(){
	
	Min = 99999999999999;
	//Min = std::numeric_limits<int>::max();
	
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
		int vertex,edges,s;
		cin >> vertex;
		cin >> edges;
		cin >> s;
		
		g->matrix[vertex-1][edges-1] = abs(s);
		
	}

	bool visited[V];
	
	for(int i=0;i<V;i++){
		visited[i] = false;
	}
	
	cin >> Start;
	cin >> Stop;
	
	
	DFS(g,visited,Start,Stop);
	
	if(Way==0){
		cout << 999;
	}
	else{
		cout << Min;
	}
	//cout << Min;

}


