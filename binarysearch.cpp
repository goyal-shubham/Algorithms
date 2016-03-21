#include<iostream>

using namespace std;

void binarySearch( int * a , int v , int first , int last )
{
    int mid;
    if (first <= last)
    {
        mid = ( first + last ) / 2;
        if( v == a[mid])
        {
            cout<<" no found.. at index = "<<mid;
        }
        else if(v < a[mid])
        {
           binarySearch( a , v , first , mid-1);
        }
        else
        {
            binarySearch ( a , v , mid+1 , last );
        }
    }
    else
    {
        cout<<"no. not found";
    }
}

void binary2( int * a, int v, int first , int last)
{
    int mid;
    mid = (first + last) / 2;
    while (first <= last)
    {
        mid = ( first + last ) / 2;
        if( v == a[mid])
        {
            cout<<" no found.. at index = "<<mid;
            break;
        }
        else if(v < a[mid])
        {
    //       binarySearch( a , v , first , mid-1);
            last = (mid - 1) ;
        }
        else
        {
            first = (mid + 1);
        }
    }
}

int main()
{
    int a[10] = {1,3,5,6,7,9,10,11,12,15};
    int value;
    cout<<"enter value to be found"<<endl;
    cin>>value;
    binarySearch ( a , value , 0 , 9);
    binary2(a , value , 0 ,9);
}
