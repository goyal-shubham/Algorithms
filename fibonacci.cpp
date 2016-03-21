#include<iostream>

using namespace std;

void fiboi ( int range )
{
    int i;
    int result;
    int last= 1;
    int secondLast =1;
    for( i = 1; i <= range; i++)
    {
        if(i <= 2)
        {
            result = last;
        }
        else   
        {
            result = last + secondLast;
            secondLast = last;
            last = result;
        }
    }
        cout<<result<<endl;
}

int fiboR( int range)
{
    int i;
    int result;
    if( range <= 2)
    {
        return 1;
    }
    else
    {
        return fiboR(range - 1) + fiboR ( range - 2);
    }
}

int main()
{
    int range;
    int value;
    cout<<"enter the range : ";
    cin>>range;
    fiboi( range );
    int v = fiboR ( range );
    cout << v<<endl;
}
