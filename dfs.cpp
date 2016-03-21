#include<iostream>
#include<list>

using namespace std;

class graph
{
    int vertex;
    list<int> * neighbors;

    public:

    graph(int data)
    {
        vertex = data;
        neighbors = new list<int>[vertex];
    }

    void addEdge( int start , int end)
    {
        neighbors[start].push_back(end);
    }

    void dfsVisit( bool *visited , int s)
    {
        cout << s << endl;
        visited[s] = true;
        for( list<int>::iterator it = neighbors[s].begin() ; it != neighbors[s].end() ; it++)
        {
            if(!visited[*it])
            {
                dfsVisit( visited , *it);
            }
        }
    }

    void dfs()
    {
        bool *visited = new bool[vertex];
        for ( int i = 0; i < vertex; i++)
        {
            visited[i] = false;
        }
        
        for( int i = 0; i < vertex; i++)
        {
            if(!visited[i])
            {
                dfsVisit(visited , i);
            }
        }
    }
};

int main()
{
    graph myGraph(7);
    myGraph.addEdge(0 , 1);
    myGraph.addEdge(0 , 4);
    myGraph.addEdge(1 , 5);
    myGraph.addEdge(2 , 1);
    myGraph.addEdge(2 , 3);
    myGraph.addEdge(3 , 3);
    myGraph.addEdge(4 , 3);
    myGraph.addEdge(4 , 1);
    myGraph.addEdge(4 , 5);
    myGraph.addEdge(5 , 0);
    myGraph.addEdge(6 , 1);
    myGraph.addEdge(1 , 6);
    myGraph.dfs();

}
