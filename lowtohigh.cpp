#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
int main() {
	int array[10000];
	int size;
	int a;

	cin>>size;
	for(int i = 0 ; i < size ; i++) {
		cin>>a;
		array[i] = a;
	}
	int count = 0 ;
	for(int i = 0 ; i < size - 1 ; i++) {
		for(int j = 0 ; j < size - i - 1 ; j++) {
			if(array[j+1] < array[j]) {
				int t = array[j+1];
				array[j+1] = array[j];
				array[j] = t;
				count++;
			}
			
		}
	}
	count = count ;
	
	for(int i = 0 ; i < size ; i++) {
		cout << array[i] <<" ";
	}
	cout << endl;
	cout << count << endl;

	return 0;
}
