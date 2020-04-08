#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n,m,column,next;
	int temp = 0;
	int max = 0;
	int sum = 0;
	cin >> m >> n;
	int arr[m][n];
	for(int i = 0; i<m; i++) {
		for(int j = 0; j<n; j++) {
			cin >>	arr[i][j];
		}
	}
	for(int i = 0; i<m; i++) {
		temp = arr[i][0];
		column = i;
		for(int j = 0; j<n; j++) {
			for(int k = 0; k<m; k++) {
				if(arr[k][j] > temp && abs(column - k) <= 1 && j != 0) {
					temp = arr[k][j];
					next = k;
				}
			}
			if(j != 0) {
				column = next;
			}
			sum += temp;
			temp = 0;
		}
		if(sum > max) {
			max = sum;
		}
		sum = 0;
	}
	cout << max << endl;
}
