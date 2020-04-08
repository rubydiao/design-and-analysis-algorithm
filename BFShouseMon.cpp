#include<iostream>
#include<vector>

using namespace std;


int Graph[1000][1000] = {{0}};
vector<int> queue;

void BFS(int start,bool visited[],int n) {

	visited[start] = true;
	queue.push_back(start);

	while(queue.size()>0) {

		for(int i=0; i<n; i++) {

			if(Graph[queue[0]][i]==1&&!visited[i]) {
				queue.push_back(i);
				visited[i] = true;
			}

		}

		cout << queue[0] << " ";
		queue.erase(queue.begin());

	}

}


int main() {

	int V,E;

	cin >> V;
	cin >> E;


	V = V+1;
	for(int i=0; i<E; i++) {

		int v,e;

		cin >> v;
		cin >> e;

		Graph[v][e] = 1;

	}

	bool visited[V] = {false};

	int start;
	cin >> start;

	BFS(start,visited,V);

}
