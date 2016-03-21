#include<iostream>

using namespace std;

#define RANGE 90

void bucketSort( int * a , int n)
{
    int bucket[RANGE];

    for(int i = 0; i < 90 ; i++)
    {
        bucket[i] = 0;
    }

    for( int i = 0 ; i < n ; i++)
    {
        // if(a[i[ > range // error
        bucket[a[i]] = bucket[a[i]] + 1;
    }

    for( int i = 0 , j = 0; j < 90 ;j++)
    {
        for ( int k = bucket[j] ; k > 0 ; k--)
        {
            a[i] = j;
            i++;
        }
    }
}

int main()
{
    int a[12] =  {10,24,22,23,46,32,67,87,5,89,33,20};
    int n = 12;
    bucketSort( a , n);
    for( int i = 0 ; i < n ; i++)
    {
        cout<<a[i]<<endl;
    }
}
