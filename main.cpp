
#include <iostream>
#include <math.h>

using namespace  std;

int main() {
    int v,e,x,y,s=0,s2 = 0,count=0;
    cin >> v;
    cin >> e;
    int xx[v];
    int xy[v];
    int g[v][v];
        for(int i = 1 ; i <= v ; i++){
            for(int j = 1 ; j <= v ; j++){
                g[i][j] = 0;
            }
        }

        for(int i = 0 ; i < e ; i++){
            cin >> x >> y;
            g[x][y] = 1;
            if(g[y][x] == 0){
                g[y][x] = -1;
            }
        }
        for(int i = 1 ; i <= v ; i++){
            for(int j = 1 ; j <= v ; j++){
//                        cout << g[i][j] << " ";
                if(g[i][j] == -1){
                    s++;
                }else if(g[i][j] == 1){
                    s2++;
                }
            }
//            cout << endl;
            xx[i] = s;
            xy[i] = s2;
            s = 0;
            s2 = 0;
        }
    for(int i =  1 ; i <= v;i++){
        xx[i] = abs(xx[i] - xy[i]);
    }
    for(int i =  1 ; i < v;i++){
        if(xx[i] < xx[i+1]){
            count = xx[i+1];
            xx[i] = xx[i+1];
        }
    }
    cout << count << endl;
}

//6 10
//1 2
//1 3
//2 6
//2 5
//3 5
//3 4
//3 5
//4 6
//5 6
//6 1
