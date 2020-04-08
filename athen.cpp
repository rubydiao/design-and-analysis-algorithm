#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> x;
int main() {
	int a;
	cin>> a;
	int b;
	int sum1 = 0 ;
	int sum2 = 0;
	for(int i = 0 ; i < a ; i++){
		cin >> b;
		if(b % 2 == 0){
			v.push_back(b);
		}
		else{
			x.push_back(b);
		}
	}
	sort(v.begin(),v.end());
	sort(x.begin(),x.end());
	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i] << " ";
		sum1+=v[i];
		
	}
	cout << sum1 <<" ";
	for(int i = 0 ; i < x.size() ; i++){
		cout << x[i] << " ";
		sum2+=x[i];
	}
	cout << sum2 <<endl;
	return 0;
}
