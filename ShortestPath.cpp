#include<iostream>
#include<string>

#define MAX 100

using namespace std;


int arr[MAX][MAX] = {{0}};


void createGraph(int V){
	int E;
	
	
	cin >> E;
	
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			
			if(i!=j){
				arr[i][j] = 999;
			}
			
			
		}
	}
	
	for(int i=0;i<E;i++){
		int v_1,v_2,s;
		
		cin >> v_1 ;
		cin >> v_2 ;
		cin	>> s;
		
		arr[v_1][v_2] = s;
		
	}
	
}

void ShortestPath(int V){
	
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				
				int d1 = arr[i][j];
				int d2 = arr[i][k]+arr[k][j];
				
				if(d1<d2){
					arr[i][j] = d1;
				}
				else{
					arr[i][j] = d2;
				}
				
			}
		}
	}	
	
}


int main(){
	
	int V;
	cin >> V;
	
	createGraph(V);
	
	ShortestPath(V);
	
	int start,des;
	
	cin >> start ;
	cin >> des;
	
	cout << arr[start][des];
	
	/*for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout << arr[i][j] <<" ";
		}
		cout << endl;
	}*/
	
}

/*
4 6
0 1 8
0 3 1
1 2 1
3 2 9
2 0 4
3 1 2
3 2
*/
