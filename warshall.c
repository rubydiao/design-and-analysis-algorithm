#include <stdio.h>

#define MAXV 10

typedef struct{
  int edges[MAXV][MAXV];
  int nvertices;

} graph;


void initial_graph(graph *g)
{ int i,j;

   for (i = 0; i < MAXV; i++)
     for (j = 0; j < MAXV; j++)
          g->edges[i][j] = 0;

  g->nvertices = 0;

}
void Warshall(graph *g)
{ int i, j, k;
  graph dist;

   for (i = 0; i < g->nvertices; i++)
     for (j = 0; j < g->nvertices; j++)
         dist.edges[i][j] = g->edges[i][j];


  for(k=0; k < g->nvertices; k++)                  // compute transitive clouser
    for(i=0; i < g->nvertices; i++)
        for(j=0; j < g->nvertices; j++)
            dist.edges[i][j] |= (dist.edges[i][k] & dist.edges[k][j]);


  for (i = 0; i < g->nvertices; i++)                // print out transistive clouser matrix
    { for (j = 0; j < g->nvertices; j++)
         printf("%d ", dist.edges[i][j]);
      printf("\n");
    }
}

int main()
{  graph g;

    initial_graph(&g);
    g.edges[0][1] = 1;
    g.edges[1][2] = 1;
    g.edges[2][0] = 1;
    g.edges[2][3] = 1;

   g.nvertices = 4;

   Warshall(&g);

    return 0;
}
