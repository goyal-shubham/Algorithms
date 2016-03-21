#include<iostream>

using namespace std;


int findMid( int * a , int first , int last)
{
    int pivot = a[last];
    int i = -1;
    int j = -1;
    int temp;
    cout << "first last " << first << " " << last << endl;
    while(first < last)
    {
        if( a[first] <= pivot)
        {
            if( i == -1 || j == -1)
            {
                i++;
            }
            else
            {
                i++;
                j = first;
                swap( a[i] , a[j] );
            }
        }
        else
        {
            j = first;
        }
        first++;
    }
    for( int i = 0; i < 8; i++)
    {
        cout<<a[i]<<endl;
    }  
    cout <<  endl;

    if( i != -1 || j != -1 )
    {
        swap( a[i+1] , a[last]);
        return i + 1 ;
    }
    
}

void quickSort( int * a, int first, int last)
{
    if(first < last)
    {
        int mid = findMid( a , first , last);
        quickSort( a , first , mid - 1);
        quickSort( a , mid + 1, last);
    }
}

int main()
{
    int a[] = {10,120,123,23,32,12,42,15};
    int n = sizeof (a)/(int)sizeof(a[0]);
    cout<<"Array was"<<endl;
    for( int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    
    quickSort( a , 0 , n-1);
    cout<<"sorted array is"<<endl;
    for( int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }   
}
