#include<stdio.h>
#include<stdlib.h>

#define MAX 8

void create_graph();
void add(int vertex);
int del();
int isEmpty();
int find_indegree_of_vertex(int vertex);
int total_vertices;

int adjacent_matrix[MAX][MAX] = {
   {0, 1, 1, 0, 0, 0, 0, 0},
   {0, 0, 0, 1, 0, 0, 0, 0},
   {0, 0, 0, 0, 1, 1, 1, 0},
   {0, 0, 0, 0, 0, 0, 0, 1},
   {0, 0, 0, 0, 0, 0, 0, 1},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0}
};

int queue[MAX];
int front = -1;
int rear = -1;

int main()
{   int vertex, count, topological_sort[MAX], indegree[MAX];

      total_vertices=MAX;

      for(int i = 0; i < total_vertices; i++)
      { indegree[i] = find_indegree_of_vertex(i);
        if(indegree[i] == 0)
            add(i);
      }

      count = 0;
      while(!isEmpty())
      {   vertex = del();
          topological_sort[++count] = vertex;
          for(int i = 0; i < total_vertices; i++)
             { if(adjacent_matrix[vertex][i] == 1)
                  {  adjacent_matrix[vertex][i] = 0;
                     indegree[i] = indegree[i] - 1;
                     if(indegree[i] == 0)
                         add(i);
                  }
            }
      }

      printf("Topological Order of Vertices\n");
      for(int i = 1; i <= count; i++)
         printf(" %3d", topological_sort[i]);
      printf("\n");

      return 0;
}

void add(int vertex)
{  if(front == -1)
         front = 0;
    rear = rear + 1;
    queue[rear] = vertex ;
}

int isEmpty()
{  return (front == -1 || front > rear)?1:0;
}

int del()
{  int element = queue[front];
         front = front + 1;
  return element;
}

int find_indegree_of_vertex(int vertex)
{  int count, total_indegree = 0;
      for(count = 0; count < total_vertices; count++)
         if(adjacent_matrix[count][vertex] == 1)
                  total_indegree++;

      return total_indegree;
}
