#include <stdio.h>
#define MAXV 10
#define MAX_INT 10000

typedef struct{
int edges[MAXV][MAXV];
int nvertices;
} graph;

void initial_graph(graph *g)
{ int i,j;
for (i = 0; i < g->nvertices; i++)
     for (j = 0; j < g->nvertices; j++)
          g->edges[i][j] = MAX_INT;                     // initial weight with infinity

g->edges[0][0] = 0;
g->edges[1][1] = 0;
g->edges[2][2] = 0;
g->edges[3][3] = 0;   // set diagonal weight = 0
}

void print_solution(graph *g)
{   for (int i = 0; i < g->nvertices; i++)           // print out transistive clouser matrix
        { for (int j = 0; j < g->nvertices; j++)
                  printf("%d ", g->edges[i][j]);
          printf("\n");
        }
}

void Floyd(graph *g)
{ int i, j, k;

for(k=0; k < g->nvertices; k++)                // compute transitive clouser
    for(i=0; i < g->nvertices; i++)
          for(j=0; j < g->nvertices; j++)
               if(g->edges[i][k] + g->edges[k][j] < g->edges[i][j])
                    g->edges[i][j] = g->edges[i][k] + g->edges[k][j];

}

int main()
{ graph g;
  g.nvertices = 4;
  initial_graph(&g);

  g.edges[0][1] = 1; g.edges[1][3] = 3; g.edges[2][0] = 1; g.edges[3][0] = 2;
  g.edges[3][2] = 2;

Floyd(&g);

print_solution(&g);
return 0;
}
