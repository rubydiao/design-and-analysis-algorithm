#include<stdio.h>
#define MAXV 5

typedef struct {
 int edges[MAXV][MAXV];
 int degree[MAXV];
 int nvertices, nedges;
} graph;


initial_graph(graph *g)
{  g->nvertices = 0;
   g->nedges = 0;
   
   for(int i=0;i< MAXV;i++){
   
      g->degree[i] = 0;
  }
}


print_graph(graph *g)
{ int i, j;

 for(i=0; i < g->nvertices; i++)
   { printf("%d :", i);
     for(j=0; j<= g->nvertices; j++)
      {     if(g->edges[i][j] == 1)
            printf(" %d", j);
      }
    printf("\n");
   }
}

int main()
{ graph g;
   g.edges[0][0] = 1; g.edges[0][1] = 1;
   g.edges[0][2] = 1; g.edges[0][3] = 0;
   g.edges[0][4] = 0;

   g.edges[1][0] = 0; g.edges[1][1] = 0;
   g.edges[1][2] = 0; g.edges[1][3] = 1;
   g.edges[1][4] = 0;

   g.nvertices = MAXV; 
  
   print_graph(&g);
 return 0;
}
