#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
vector<int> v;
vector<int> q1;
vector<int> q2;
void countSort(vector <int>& v) 
{ 
	int max = *max_element(v.begin(), v.end()); 
	int min = *min_element(v.begin(), v.end()); 
	int range = max - min + 1; 
	
	vector<int> count(range), output(v.size()); 
	for(int i = 0; i < v.size(); i++) 
		count[v[i]-min]++; 
		
	for(int i = 1; i < v.size(); i++) 
		count[i] += count[i-1]; 
	
	for(int i = v.size()-1; i >= 0; i--) 
	{ 
		output[ count[v[i]-min] -1 ] = v[i]; 
			count[v[i]-min]--; 
	} 
	
	for(int i=0; i < v.size(); i++) 
			v[i] = output[i]; 
} 

int main() 
{ 
	
	int size,a;
	cin>>size;
	for(int i=  0 ; i < size; i++){
		cin>>a;
		v.push_back(a);
	}
	countSort (v); 
	reverse(v.begin(),v.end());
	int m;
	cin >> m;
	for(int i= 0 ; i < v.size() ; i++){
		if(v[i] + v[i+1] == m){
			q1.push_back(v[i]);
			q2.push_back(v[i+1]);
		}
	}
	for(int i= 0 ; i < q1.size() ; i++){
		cout << q1[i] << " " << q2[i];
	}
	return 0; 
} 

