#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std; 

void count(int *arr, int n) 
{ 
	vector<bool> check(n, false); 

	for (int i = 0; i < n; i++) { 

		if (check[i] == true) {
			continue; 
		}
			
		int count = 1; 
		for (int j = i + 1; j < n; j++) { 
			if (arr[i] == arr[j]) { 
				check[j] = true; 
				count++; 
			} 
		} 
		cout << arr[i] << " " << count << endl; 
	} 
} 

int main() 
{ 
	int *arr = new int[80000000]; 
	int n;
	int a;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> a;
		arr[i] = a;
	}
	sort(arr,arr+n);
	count(arr, n); 
	return 0; 
} 

