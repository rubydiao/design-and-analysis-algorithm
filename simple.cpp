#include <iostream>
using namespace std;
int arr[101][101] = {0};
int visited[101] = {0};
int eiei = 0;
void dfs(int start, int end){

	if(start == end){
		eiei++;
	}else{
		for(int i = 0; i < 101; i++){
			if(arr[start][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				dfs(i, end);
				visited[i] = 0;
			}
		}
	}
}
int main(){
	int v, e;
	cin >> v >> e;
	for(int i = 0; i < e; i++){
		int v1, v2;
		cin >> v1 >> v2;
		arr[v1][v2] = 1;
	}
	int start, end;
	cin >> start >> end;
	visited[start] = 1;
	dfs(start, end);
	cout << eiei;
	return 0;
}
