#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main() {
	int a , k, size,count = 0;
	cin>>size;
	cin>> k;
	for(int i = 0 ; i < size ; i++) {
		cin>>a;
		v.push_back(a);
	}
	for(int i = 0 ; i < v.size() ; i++) {
		int t = i;
		for(int j = i ; j < v.size() ; j++) {
			if(v[t] > v[j]) {
				t = j;
			}
		}
		int tt = v[i];
		v[i] = v[t];
		v[t] = tt;
		count++;
		if(v.at(k) == v.at(i)) {
			cout << count << endl;
		}
			
	}
}
