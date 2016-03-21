
#include<iostream>

using namespace std;

//O(n^3)
//Sachin : can be easily done in O(n^2)

void deDuplicateNew ( string input)
{
    int start = -1;
    int size = input.size();
    for( int i = 0; i < size; i++)
    {
        int found = 0;
        for( int j = i - 1; j >= 0; j--)
        {
            if(input[j] == input[i])
            {
                found = 1;
                if(start < 0)
                {
                    start = i;
                }
                break;
            }
        }

        if(found == 0 && start > 0) 
        {
            input[start] = input[i];
            start++;
        }
    }
    
    for ( int i = start; i < size; i++)
    {
        input[i] = '\0';
    }

    cout << input << endl;
}

int main()
{
    string input;
    cout << "enter the string" << endl;
    cin >> input; 
    deDuplicateNew(input);
}
