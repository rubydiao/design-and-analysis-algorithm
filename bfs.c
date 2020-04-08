#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int parent[MAX];
int state[MAX];
void create_graph();
void BF_Traversal();
void print_parent(int );
void BFS(int v);

int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main()
{   create_graph();
    BF_Traversal();
    return 0;
}

void BF_Traversal()
{   int v;

    for(v=0; v<n; v++)
        state[v] = initial;

    printf("Enter Start Vertex: \n");
    scanf("%d", &v);
    parent[v]=-1;
    BFS(v);
    print_parent(n);
}

void print_parent(int n)
{ int i;
    for(i=0;i<n;i++)
     printf("%d ", parent[i]);
}

void BFS(int v)
{   int i;
    insert_queue(v);
    state[v] = waiting;

    while(!isEmpty_queue())
    {   v = delete_queue( );
        printf("%d ",v);
        state[v] = visited;

        for(i=0; i<n; i++)
        {  if(adj[v][i] == 1 && state[i] == initial)
            {  insert_queue(i);
               state[i] = waiting;
               parent[i] = v;
            }
        }
    }
    printf("\n");
}

void insert_queue(int vertex)
{
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else
    {  if(front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex ;
    }
}

int isEmpty_queue()
{  return ((front == -1) || (front > rear))? 1:0;
}

int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {   printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front + 1;
    return delete_item;
}

void create_graph()
{    n = 6;
    adj[0][2] = 1;    adj[2][0] = 1;    adj[0][1] = 1;    adj[1][0] = 1;    adj[1][3] = 1;
    adj[3][1] = 1;    adj[3][2] = 1;    adj[2][3] = 1;    adj[3][4] = 1;    adj[4][3] = 1;
    adj[4][5] = 1;    adj[5][4] = 1;
}
