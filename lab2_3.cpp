#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n];
    int max =0;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(a[i]>max){
            max = a[i];
        }
    }
    max = max+1;
    int aa[max];
    for(int i =0;i<max;i++){
        aa[i] = 0;
    }

    for(int i =0;i<n;i++){

        aa[a[i]] = aa[a[i]]+1;
    }
    int sum =0;
    for(int i =0;i<max;i++){
        if(aa[i]>0){
            sum = sum+i;
        }

    }
    cout << sum;


}
