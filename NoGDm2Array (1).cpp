#include<iostream>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int main(){
	
	int m,n,k;
	
	cin >> m;
	
	for(int t=0;t<m;t++){
		
		vector<int> v1,v2;
		
		cin >> n;
		
		for(int i = 0;i<n;i++){
			int temp;
			cin >> temp;
			v1.push_back(temp);
		}
		
		for(int i = 0;i<n;i++){
			int temp;
			cin >> temp;
			v2.push_back(temp);
		}
		
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());	
		reverse(v2.begin(),v2.end());
		
		cin >> k;
		
		bool check = true;
		for(int i=0;i<n;i++){	
			if(v1[i]+v2[i] < k){
				check = false;
				break;
			}	
		}
		
		if(check){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
		
	}	
	
}

/*
2
5
1 2 4 4 3
5 2 3 1 9
5
5
1 2 4 4 3
5 2 3 1 9
15

output:
Yes
No
*************************

2
8
35 70 79 63 6 82 62 96 
1 25 59 65 46 28 92 43 
28
7
92 3 93 22 19 48 72 
5 54 83 17 96 27 39 
70

output:
Yes
Yes

*/




