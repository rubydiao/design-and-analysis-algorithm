#include<iostream>
#include<stack>
 
#define NODE 100
 
using namespace std;
 
int graph[NODE][NODE] = {{0}};
int arrinput[1000] = {-1};
int n;
 
void DFS(int u, bool visited[], stack<int>&stk) {
    visited[u] = true;
    for(int v = 0; v<=n; v++) {
        if(graph[u][v]) {
            if(!visited[v]) {
                DFS(v, visited, stk);
            }
        }
    }
    stk.push(u);
}
 
void performTopologicalSort() {
    stack<int> stk;
    bool vis[n];
    for(int i = 0; i<=n; i++) {
        vis[i] = false;
    }
 
    for(int i = 0; i<=n; i++) {
        if(!vis[i]) {
            DFS(i, vis, stk);
        }
    }
 
    while(!stk.empty()) {
 
        if(stk.top() == arrinput[stk.top()]){
            cout << stk.top() << " ";
        }
        stk.pop();
    }
 
}
 
int main() {
    int x,y;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> x >> y;
        graph[x][y] = 1;
        arrinput[x] = x;
        arrinput[y] = y;
    }
    performTopologicalSort();
    cout << endl;
}
