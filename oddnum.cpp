#include <iostream>

using namespace std;
int main(){
	
	int x,y,v,e,count =0;
	int s = 0 ;
	cin>>v>>e;
	int g[v][v];
	for(int i =1 ; i <= v ; i++){
		for(int j = 1 ; j <= v ; j++){
			g[i][j] = 0;
		}
	}
	for(int i = 1 ; i <= e ; i++){
		cin>> x >> y;
		g[x][y] = 1;
	}
	
	for(int i = 1 ; i <= v ; i++){
		for(int j = 1 ; j <=  v ; j++){
			if(g[i][j] == 1 && (j%2) == 0){
				count++;
			}
			
		}
	}
	cout << count << endl;
}
