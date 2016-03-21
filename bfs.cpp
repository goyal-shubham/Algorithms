
#include<iostream>
#include<list>

using namespace std;

class graph
{
    public:
        int Vertex;
        list<int> * neighbors;

        graph(int data)
        {
            Vertex = data;
            neighbors = new list<int> [Vertex];
        }
        
        void addEdge(int w , int v)
        {
            neighbors[w].push_back(v);
        }

        void bfs(int s)
        {
            bool *visited = new bool[Vertex];
            for( int i = 0; i < Vertex; i++)
            {
                visited[i] = false;
            }
            
            int *level = new int[Vertex];
            level[s] = 0;
            visited[s] = true;
            list<int> queue;
            queue.push_back(s);

            while(!queue.empty())
            {
                s = queue.front();
                queue.pop_front();
                cout << " S is " << s << endl;
                for( list<int>::iterator it = neighbors[s].begin(); it != neighbors[s].end() ; it++)
                {
                    if( !visited[*it] )
                    {
                        visited[*it] = true;
                        level[*it] = level[s] + 1;
                        queue.push_back(*it);
                    }
                }
            }

            for( int i = 0 ; i < Vertex ; i++)
            {
                cout << " level of " << i << " is " << level[i] << endl;
            }
        }

};

int main()
{
    graph myGraph(6);
    myGraph.addEdge(0 , 1);
    myGraph.addEdge(0 , 4);
    myGraph.addEdge(1,5);
    myGraph.addEdge(2,1);
    myGraph.addEdge(2 ,3);
    myGraph.addEdge(3 ,3 );
    myGraph.addEdge(4,3);
    myGraph.addEdge( 4 , 1);
    myGraph.addEdge( 4 , 5);
    myGraph.addEdge(5 , 0 );
    myGraph.bfs(2);
    
}
