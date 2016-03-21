
#include<iostream>

using namespace std;

int findLCS( string seq1, string seq2)
{
    int length1 = seq1.length();
    int length2 = seq2.length();
    int LCS[length1 + 1][length2 + 1];
    for( int i = 0 ; i <= length1; i++)
    {
        LCS[i][0] = 0;
    }
    for( int j = 1; j <= length2; j++)
    {
        LCS[0][j] = 0;
    }
    for ( int i = 1 ; i <= length1; i++)
    {
        for ( int j = 1; j <= length2 ; j++)
        {
            if ( seq1[i] == seq2[j])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else if (LCS[i-1][j] >= LCS[i][j-1])
            {
                LCS[i][j] = LCS[i-1][j]; 
            }
            else
            {
                LCS[i][j] = LCS[i][j-1];
            }
        }
    }
    
    int index = LCS[length1][length2];
    char ans[index+1];
    ans[index] = '\0';
    int i = length1;
    int j = length2;
    while( i > 0 && j > 0)
    {
        if(seq1[i - 1] == seq2[j-1])
        {
            ans[index - 1] = seq1[i-1];
            i--;
            j--;
            index--;
        }
        else if(LCS[i-1][j] > LCS[i][j-1])
            i--;
        else
            j--;
    }

    cout << ans << endl;
    return LCS[length1 ][length2];
}

int main()
{
    string seq1;
    string seq2;
    cout << "Enter string 1 " << endl;
    cin >> seq1;
    cout << "Enter String 2 " << endl;
    cin >> seq2;
    cout << seq1[1];
    cout << "longest common subsequence is : " << findLCS ( seq1 , seq2) << endl;
}
