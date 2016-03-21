
#include<iostream>
#define noVertex 4

using namespace std;

int graph[noVertex][noVertex] = {{0, 1, 1, 0}, {1,1,0,1},{0,1,1,0},{0,0,1,0}};

void bfs ( int vertex)
{
    int queue[noVertex];
    bool visited[noVertex];
    for ( int i = 0 ; i < noVertex ; i++)
    {
        visited[i] = false;
    }
    int level[noVertex];
    level[vertex] = 0;
    visited[vertex] = true;
    int start = 0;
    int end = 0;
    int parent[noVertex];
    queue[end] = vertex;
    int temp;
    parent[vertex] = 0;

    while( start <= end)
    {
        int temp = queue[start] ;
        start++;
        for(int i = 0; i < noVertex ; i++)
        {
            if( graph[temp][i] == 1 && visited[i] == false )
            {
                cout << i << endl;
                visited[i] = true;
                parent[i] = temp;
                level[i] = level[temp] + 1;
                cout << " level of " << i << " is " << level[i] << endl;
                end++;
                queue[end] = i;
            }
        }
    }


}

int main()
{
/*    int **graph;
    graph = (int **)malloc(sizeof(int *) * noVertex);
    for( int i = 0; i < noVertex; i++)
    {
        graph[i] = (int *)malloc ( sizeof(int) * noVertex);
    }
*/
    bfs( 1);

}
