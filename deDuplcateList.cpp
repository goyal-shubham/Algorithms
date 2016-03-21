
#include<iostream>
#include<list>
#define ASCII_RANGE 128
using namespace std;

void printList ( list<char> myList)
{
    for(list<char> :: iterator ptr = myList.begin(); ptr != myList.end(); ptr++)
    {
        cout << *ptr << " ";
    }
    cout << endl << endl; 
}

void deDuplicateList ( list<char> myList )
{
    char bucket[ASCII_RANGE];
    for( int i = 0; i < ASCII_RANGE; i++)
    {
        bucket[i] = 0;
    }

    list<char> :: iterator ptr = myList.begin();
    for( ; ptr != myList.end(); ptr++)
    {
        bucket[*ptr] = 1;
    }
    
    for( ptr = myList.begin() ; ptr != myList.end() ; ptr++)
    {
        if(bucket[*ptr] == 1)
        {
            cout << *ptr<< " ";
            bucket[*ptr] = 0;
        }
    }
    cout << endl;
 
}

int main()
{
    string input = "HURRY UP";
    list<char> myList;

    for( int i = 0; i < input.length(); i++)
    {
        myList.push_back(input[i]);
    }
    printList(myList);
    deDuplicateList(myList);
   
}
