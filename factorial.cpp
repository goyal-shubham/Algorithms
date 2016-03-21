#include<iostream>

using namespace std;

int main()
{
    int no_cases;
    int input;
    cin>>no_cases;
    while( no_cases > 0)
    {
        cin>>input;
        if( input >= 1)
        {
            int count = 0;
            while( input >= 5 )
            {
                count = count + input/5;
                input = input/5;
            }    
        
            cout<<count<<endl;
        }

        no_cases--;
    }
}

