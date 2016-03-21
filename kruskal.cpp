
#include<iostream>

#define vertex 9

using namespace std;

class kruskal
{
    public :

    int edge;
    int weightTable[100][4];
    int sets[vertex+1][vertex+1];
    int top[vertex+1];
    int tree[vertex+1][vertex+1];
    
    kruskal()
    {
        edge = 0;
        for( int i = 0; i <= vertex; i++)
        {
            for( int j = 0; j <= vertex; j++)
            {
                tree[i][j] = 0;
            }
        }
    }

    void enterGraph()
    {
        bool loop = true;
        for( int i = 1; i <= vertex && loop; i++)
        {
            for( int j = i + 1; j <= vertex; j++)
            {
                cout << "enter vertexes followed by weight" 
                    << "Enter 0 0 to exit";
                int w,a,b;
                cout << "enter vertexes";
                cin >> a >> b;
                if( a != 0 || b != 0)
                {
                    cout << " enter weight ";
                    cin >> w;
                    edge++;
                    weightTable[edge][1] = a;
                    weightTable[edge][2] = b;
                    weightTable[edge][3] = w;
                }
                else
                {
                    loop = false;
                    break;
                }
            }
        }
    }
     
    void sortGraph()
    {
        for( int i = 1; i < edge; i++)
        {
            for(int j = 1; j < edge; j++)
            {
                if(weightTable[j][3] > weightTable[j+1][3])
                {
                    swap(weightTable[j][1] , weightTable[j+1][1]);
                    swap(weightTable[j][2] , weightTable[j+1][2]);
                    swap(weightTable[j][3] , weightTable[j+1][3]);
                }
            }
        }
    }
   
    void printGraph()
    {
        for(int i = 1; i <= edge; i++)
        {   
            cout << "<" << weightTable[i][1]
            <<"," << weightTable[i][2]
            <<">" << weightTable[i][3] << endl;
        }   
    }

    int checkSet(int n)
    {
        for(int i = 1; i <= edge; i++)
        {
            for(int j = 1; j <= top[i]; j++)
            {
                if( n == sets[i][j] )
                {
                    return i;
                }
            }
        }
        return 0;
    }

    void MSTkruskal()
    {
        for( int i = 1; i <= vertex; i++)
        {
            sets[i][1] = i;
            top[i] = 1;
        }

        for( int i = 1; i <= edge; i++)
        {
            int p1 = checkSet(weightTable[i][1]);
            int p2 = checkSet(weightTable[i][2]);
            if(p1 != p2)
            {
                tree[weightTable[i][1]][weightTable[i][2]] = weightTable[i][3];
                for(int j = 1; j <= top[p2]; j++)
                {
                    top[p1]++;
                    sets[p1][top[p1]] = sets[p2][j];
                }

                top[p2] = 0;
            }
        }
    }

    void printMST()
    {
        for( int i = 1; i <= vertex; i++)
        {
            for( int j = 1; j <= vertex; j++)
            {
                if(tree[i][j] != 0)
                {
                    cout << "<" << i << "," << j << ">" << tree[i][j] << endl;
                }
            }
        }
    }

};

int main()
{
   
   kruskal graph;
   graph.enterGraph();
   graph.printGraph();
   cout << endl << endl;
   graph.sortGraph();
   graph.printGraph();
   cout << endl << endl;
   graph.MSTkruskal();
   cout << endl << endl;
   graph.printMST();
   

}
