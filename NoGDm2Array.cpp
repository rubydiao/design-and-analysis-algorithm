#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
vector<int> x;
vector<int> w;
vector<int> y;
vector<int> sum;
vector<int> sum1;

int main() {

	int round , n , b, a, d ,s = 0,s1 = 0,num1,num2,k,k1;
	cin >> round;

	for(int i=0 ; i < round; i++) {
		cin>>b;
		for(int j =0 ; j< b ; j++) {
			cin >> num1;
			v.push_back(num1);
		}
		for(int k =0; k < b ; k++) {
			cin >> num2;
			x.push_back(num2);
		}
		cin >> k;
		if(round > 0) {
			cin>>b;
			for(int j =0 ; j< b ; j++) {
				cin >> a;
				w.push_back(a);
			}
			for(int k =0; k < b ; k++) {
				cin >> d;
				y.push_back(d);
			}
			cin >> k1;
			break;
		}
	}
	for(int i=0 ; i < b; i++) {
		s = s + v[i] + x[i];
		sum.push_back(s);
		s = 0;
	}
//	for(int i=0 ; i < sum.size() ; i++){
//		cout << sum[i] << " ";
//	}
	for(int i=0 ; i < b; i++) {
		s1 = s1 + w[i] + y[i];
		sum1.push_back(s1);
		s1 = 0;
	}
	for(int i=0 ; i < sum.size(); i++) {
		if(sum[i] >= k) {
			cout << "Yes"<< endl;
			break;
		} else {
			cout << "No"<< endl;
			break;
		}
	}
	for(int i=0 ; i < sum1.size(); i++) {
		if(sum1[i] >= k1) {
			cout << "Yes"<< endl;
			break;
		} else {
			cout << "No"<< endl;
			break;
		}
	}
}
