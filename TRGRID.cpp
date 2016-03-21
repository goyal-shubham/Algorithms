#include<iostream>

using namespace std;

int main()
{
    int t;
    long long int n, m;
    cin >> t;
    for(int i = 1 ; i <= t ; i++)
    {
        cin >> n >> m;
        if(n <= m)
        {
            if(n % 2 == 0)
            {
                cout << "L";
            }
            else if(n%2==1)
            {
                cout << "R";
            }
        }
        else if(n > m)
        {
            if(m % 2 == 0)
            {
                cout << "U";
            }
                else if(m % 2 == 1)
                {
                    cout << "D";
                }
        }
        cout << endl;
    }
}
