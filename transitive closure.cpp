#include<stdio.h>
#include <iostream>

#define V 4

using namespace std;

void printSolution(int reach[][V]);


void transitiveClosure(int graph[][V]) {
	int reach[V][V];
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			reach[i][j] = graph[i][j];

	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {

			for (int j = 0; j < V; j++) {

				reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

			}

		}
	}

	printSolution(reach);
}


void printSolution(int reach[][V]) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << reach[i][j] << " ";
		cout << endl;
	}
}

int main() {

	int graph[V][V];
	for(int i = 0 ; i< V ; i++) {
		for(int j = 0  ; j < V ; j++) {
			cin >> graph[i][j];
		}
	}

	transitiveClosure(graph);
	return 0;
}

