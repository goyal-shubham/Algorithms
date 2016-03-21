#include<iostream>

using namespace std;

int getFactorial( int num1 )
{
    int counter;
    int fact = 1;
    for( counter = num1; counter > 1 ; counter--)
    {   
        fact = fact * counter;
    }
    return fact;
}

bool checkRange( int num )
{
    if( num >= 1 && num <= 100 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int noCases;
    cin >> noCases;
    int input;
    int factorial;
    if( checkRange ( noCases))
    {
        while(noCases)
        {
            cin >> input;
            if(checkRange(input))
            {   
                factorial = getFactorial( input );
                cout << factorial << endl;
                noCases--;
            }
            else
            {
                break;
            }
        }
    }
}
