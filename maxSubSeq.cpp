
#include<iostream>

#define SIZE 10

using namespace std;

int maxSubSeq(int *a)
{
    int **sum; // sum[i][j] represents sum for a[i] t0 a[j]
    int output = a[0];
    sum = ( int **) malloc( sizeof(int *) * SIZE);
    for( int i = 0 ; i < SIZE; i++)
    {
        sum[i] = (int *) malloc( sizeof(int) * SIZE );
    }

    for ( int i = 0; i < SIZE ; i++)
    {
        for ( int j = i; j < SIZE; j++)
        {
            if( i == j)
            {
                sum[i][j] = a[i];
            }

            else
            {
                sum[i][j] = sum[i][j-1] + a[j];
                if( output < sum[i][j])
                {
                     output = sum[i][j];
                }
            }
        }
    }
   
     for ( int i = 0; i < SIZE ; i++)
    {
        for ( int j = i; j < SIZE; j++)
        {
          cout << "\t " << sum[i][j] << " ";  
        }
        cout << endl;
    }
   
     cout << "maximum is " << output << endl; 
    return output;
}

int maxLinearSeq( int *a , int length , int *maximum)
{
    if( length == 1)
    {
        maximum[length - 1] = a[0];
    }
    else
    {
        maximum[length - 1] = max( maxLinearSeq(a , length-1 , maximum) + a[length - 1] , a[length - 1] ); 
    }

    return maximum[length - 1]  ;
}


int main()
{
    int a[SIZE] = { -1 , -2 , 5 , -6 , 3 , 0 , 4, -3 , 9 , -1 };
    int output = maxSubSeq(a); 
    int maximum[SIZE];
    output = maxLinearSeq( a , SIZE , maximum);
    for ( int i = 0; i < SIZE; i++)
    {
        cout << maximum[i] << endl;
    }
}
