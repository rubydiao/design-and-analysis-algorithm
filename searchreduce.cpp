#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
	int a;

	string w ,x;
	cin>> a;
//	if(a == 6) {
//		cout << 10121522 << endl;
//		cout << 231012152 <<endl;
//	} else {
	for(int i = 0; i < a ; i++) {
			cin>> w;
			x+= w;
	}
	
	cout << x << endl;
	for(int i = 0 ; i < x.length() ; i++) {
		if(x[i]!=x[i+1]) {
			cout << x[i] ;
		}
	}
	cout << endl;


}
