#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAXV 5 

using namespace std;
struct Node {
   int item;
   struct Node *next;
};

struct adj_list{
   struct Node *head;
};

struct Graph {
   int nvertices;
   struct adj_list array[MAXV];
};

struct Node *CreateNode(int dest)
{ struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
   newnode->item = dest;
   newnode->next = NULL;
 
 return newnode;
}

struct Graph *createGraph(int n)
{ struct Graph* graph = (struct Graph *) malloc(sizeof(struct Graph));

for(int i = 0; i < n; ++i)
    graph->array[i].head = NULL;

return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{ struct Node* newnode = CreateNode(dest);
       newnode->next = graph->array[src].head;
       graph->array[src].head = newnode;
}

void printGraph(struct Graph *g)
{ int v;

   for(v=0; v < g->nvertices; ++v) {
       struct Node* p = g->array[v].head;
       printf("%d",v);
       while(p)
         { printf(" -> %d", p->item);
           p = p->next;
         }
    printf("\n");
   }
 
}

int main()
{
  struct Graph *g = createGraph(MAXV);

   addEdge(g, 0, 1);
   addEdge(g, 0, 4);
   addEdge(g, 1, 2);
   addEdge(g, 2, 3);
   addEdge(g, 3, 4);
   g->nvertices=MAXV;
printGraph(g);


return 0; 
}


