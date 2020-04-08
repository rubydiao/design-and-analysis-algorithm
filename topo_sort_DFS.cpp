#include<iostream>
#include<stack>

#define NODE 8

using namespace std;

int graph[NODE][NODE] = {
   {0, 1, 1, 0, 0, 0, 0, 0},
   {0, 0, 0, 1, 0, 0, 0, 0},
   {0, 0, 0, 0, 1, 1, 1, 0},
   {0, 0, 0, 0, 0, 0, 0, 1},
   {0, 0, 0, 0, 0, 0, 0, 1},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0}
};

void DFS(int u, bool visited[], stack<int>&stk) {
   visited[u] = true;
   for(int v = 0; v<NODE; v++) {
      if(graph[u][v]) {
         if(!visited[v])
            DFS(v, visited, stk);
      }
   }
   stk.push(u);                      // push starting vertex into the stack
}

void performTopologicalSort() {
   stack<int> stk;

   bool vis[NODE];

   for(int i = 0; i<NODE; i++)
      vis[i] = false;

   for(int i = 0; i<NODE; i++)
      if(!vis[i])                       // when node is not visited
          DFS(i, vis, stk);

   while(!stk.empty()) {
      cout << "\n" << stk.top();
      stk.pop();
   }

}

main() {
   cout << "Output: ";
   performTopologicalSort();
}
