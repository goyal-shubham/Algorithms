#include<iostream>
#include<string>
using namespace std;

void upperCase(char c)
{   
    if(c<=122 && c>=97)
    {
        c=c-32;
        cout<<c;
    }
    else if(c==32)
        cout<<c;
}
int main()
{   
    int i = 0;
    char * a;
    cout<<"enter the string to convert to upper case";
    gets(a);
    char temp;
    cout<<a[i];
    while( a[i])
    {   
        temp = a[i];
        upperCase(temp);
        i++;
    }
}

