#include <iostream>

using namespace std;

int main() {
	int a;
	bool check;
	int size;
	cin>>size;
	int v[size];
	for(int i = 0 ; i < size ; i++) {
		cin>>a;
		v[i] = a;
	}
	for(int i = 0 ; i < size ; i++) {
		if(v[i] > v[i+1]) {
			check = 0;
			break;
		} else {
			check = 1;
		}
	}
	if(check == 0) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;

	}
}
