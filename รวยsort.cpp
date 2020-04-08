#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	int a;
	cin>>a;
	int b;
	int *a2 = new int[1000000];
	int *a3 = new int[1000000];
	
	int sum = 0;
	int sum1 = 0;
	int s =0;
	for(int i = 0 ; i < a; i++) {
		cin >> b;
		if(b >= 0){
			a2[b] = b;
		}else{
			a3[abs(b)] = b;
			s++;
		}
	}
	for(int i = 10000  ; i >0 ; i--) {
		if(sum1 < s) {
			if(a3[i] != 0) {
				cout << a3[i] << " ";
				sum1++;
			}
		} else {
			break;
		}
	}
	for(int i = 0  ; i < 1000000 ; i++) {
		if(sum < a) {
			if(a2[i] != 0) {
				cout << a2[i] << " ";
				sum++;
			}
		} else {
			break;
		}
	}
	cout << endl;
	return 0;
}
