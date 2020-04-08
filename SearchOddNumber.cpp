#include<iostream>
#include<string>

using namespace std;


int count = 0;

class Graph{
	
	public :
	int v;
	bool edges[100][100];

	Graph(int v){
		this->v = v;
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				edges[i][j] = false;
			}
		}
	}
	
};

void DFS(Graph *g,bool visited[],int v){
	visited[v-1] = true;
	
	for(int i=0;i<g->v;i++){
		if(!visited[i]&&g->edges[v-1][i]==true){
			if((i+1)%2==0){
				count++;
			}
			DFS(g,visited,i+1);
		}
	}
}


int main(){

	int v,e;
	
	cin >> v;
	
	Graph *g = new Graph(v);
	
	cin >> e;

	for(int i=0;i<e;i++){
		int t_v1,t_v2;
		cin >> t_v1;
		cin >> t_v2;
		g->edges[t_v1-1][t_v2-1] = true;
		g->edges[t_v2-1][t_v1-1] = true;
	}
	
	bool visited[100];
	
	for(int i=0;i<100;i++){
		visited[i] = false;
	}
	
	for(int i=0;i<v;i++){
		if(!visited[i]){
			if((i+1)%2==0){
				count++;
			}
			DFS(g,visited,i+1);
		}
	}
	
	cout << count;
}




