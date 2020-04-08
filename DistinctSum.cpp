#include<iostream>
using namespace std;
int index = 0;

void cts(int A[],int B[],int n) {
	int C[index];
	for(int i = 0 ; i < index + 1 ; i++) {
		C[i]=0;
	}
	for(int j = 1 ; j <= n ; j++) {
		C[A[j]]++;
	}
	for(int i = 1 ; i <= index ; i++) {
		C[i]+=C[i-1];
	}
	for(int j = n ; j >= 1 ; j--) {
		B[C[A[j]]]=A[j];
		C[A[j]]=C[A[j]]-1;
	}
}
int main() {
	int n , sum = 0;
	cin>>n;
	int a[n],b[n];
	for(int i = 1 ; i <= n ; i++) {
		cin>>a[i];
		if(a[i]>index ) {
			index =a[i];
		}
	}
	cts(a,b,n);

	for(int i = 1;i <= n ; i++)       
	{
		if(b[i]!=b[i+1]){
			sum+=b[i];
		}
	}
	cout << sum << endl;
}



