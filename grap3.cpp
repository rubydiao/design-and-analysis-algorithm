#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX 100
using namespace std ;
vector <int> v ;
int arr[MAX][MAX] ;
int par[MAX];
int vis[MAX];
int pis[MAX];
int mi = 9999,n;
void parson(int to,int from) {
	if(par[to]==-1) {
		v.push_back(to); 
		return;
	} else {
		if(pis[to]<mi) {
			mi=pis[to];
		}
		v.push_back(to);
		parson(par[to],from);
	}
}
int max(){
	
	int a = -100 ,index = -1 ;
	for(int i = 0 ; i < MAX ; i++){
		if(vis[i] == 0 && pis[i] > a){
			a = pis[i];
			index = i ;
		}
	}
	return index ;
}
void ditra(int from ,int to){
	int now = 01;
	par[from] = -1 ;
	pis[from] = 0 ;
	for(int i = 0 ; i < n ; i++){
		now = max();
		//cout << now <<endl ;
		if(now == -1){
			return ;
		}
		vis[now] = 1 ;
		for(int j = 0 ; j < MAX ; j++){
			//cout << "yyyy" << endl ;
			if(arr[now][j] != 999){
				if( vis[j] == 0 && pis[j] < arr[now][j]){
					pis[j] = arr[now][j];
					par[j] = now ;
					cout << now << " : "<< par[j] << endl ;
				}	
			}
			
		}
		
	}
}
int main(){
	int m ;
	for(int i = 0 ; i < MAX ; i++){
		for(int j = 0 ; j< MAX ; j++){
			arr[i][j] = 999 ;
		}
	}
	cin >> m >> n;
	for(int i = 0 ; i < n ; i++){
		int a1,a2,a3 ;
		cin >> a1 >> a2 >> a3 ;
		arr[a1][a2] = a3 ;
		arr[a2][a1] = a3 ;
	}
	int from,to,people ;
	cin >> from >> to >> people ;
	ditra(from,to);
	//v.push_back(from);
	//ditra(to,from);
	parson(to,from);
	reverse(v.begin(),v.end()); 
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout << endl ;
	cout << ceil((double)people/(mi-1)) ;
	return 0 ;
}
/*
8 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
3 6 20
4 7 35
5 7 20
6 7 30
1 7 99

*/
