#include<stdio.h>
#define MAX 10 


void DFS(int);
void create_graph(); 
void DF_traversal(); 
void print_parent(int );

int adj[MAX][MAX];
int visited[MAX]; 
int n; 
int parent[MAX]; 

 
int main()
{
    create_graph(); 
    DF_traversal();  
 
  return 0; 
}
 
void print_parent(int n)
{ int i; 
  printf("\n"); 
    for(i=0;i<n;i++)
     printf("%d ", parent[i]); 
}
void DF_traversal()
{   int v, i; 
    for(i=0;i<n;i++)
        visited[i] = 0;
        
    printf("Enter Start Vertex: \n");	
    scanf("%d", &v);
    parent[v]=-1; 
    DFS(v);
    print_parent(n);
}

void DFS(int i)
{   int j;
    printf("%d ", i);
    visited[i] = 1;
    
    for(j = 0 ; j < n; j++)
       if(!visited[j] && adj[i][j] == 1)
         {  parent[j]=i; 
             DFS(j);
         }
}

void create_graph()
{
    n = 6;                  // no. vertex in graph 
    
    adj[0][2] = 1;    adj[2][0] = 1;    adj[0][1] = 1;    adj[1][0] = 1;    adj[1][3] = 1;
    adj[3][1] = 1;    adj[3][2] = 1;    adj[2][3] = 1;    adj[3][4] = 1;    adj[4][3] = 1;
    adj[4][5] = 1;    adj[5][4] = 1;
}