#include<iostream>

using namespace std;

class myString
{
    public:
        
        char *a;

        // this is constructor
        myString(string input)
        {
            a = (char*) malloc ( sizeof(char) *  input.size());
            for(int i=0; i<input.size();i++)
            {
                a[i] = input[i];
            }
            a[input.size()] = '\0';
        }      
    
        void printMyString()
        {
            cout<<a;
        }   

        void Append(myString b); // Append b in a

};

int main()
{
    string stringInput = "sachin";
    myString a(stringInput);
    a.printMyString();

}
