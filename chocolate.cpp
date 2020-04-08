#include <iostream>
#include <math.h>
using namespace std;
int arr2d[10000][10000];
int j=0;

void printTheArray(int arr[],int n) {
	for(int i=0; i<n; i++) {
		arr2d[j][i] = arr[i];
	}
	j = j+1;
}
void generateAllBinaryStrings(int n,int arr[],int i) {
	if(i == n) {
		printTheArray(arr,n);
		return ;
	}
	arr[i] = 0;
	generateAllBinaryStrings(n,arr,i+1);
	arr[i] = 1;
	generateAllBinaryStrings(n,arr,i+1);

}
int main() {
	int n;
	cin >> n;
	int arr[n];
	int a[n];
	int b;
	int c = pow(2,n);
	for(int i=0 ; i < n; i++) {
		cin >>b ;
		a[i] = b;
	}
	int sumA = 0;
	int max =0 ,min =0;
	int minsumAsumB = 999;
	generateAllBinaryStrings(n,arr,0);
	for(int k=0; k < c ; k++) {
		for(int p=0; p < n; p++) {
			if(arr2d[k][p] == 1 && arr2d[k][p] == arr2d[k][p+1]) {
				sumA = 0;
				break;
			} else if(arr2d[k][p] == 1) {
				sumA = sumA + a[p];
			}
		}
		if(sumA > max) {
			max = sumA;
		}
		sumA = 0;
	}
	cout << max;
}
