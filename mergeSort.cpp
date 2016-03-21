#include<iostream>

using namespace std;

//complexity : n(log n)
void merge ( int * a, int first , int mid , int last)
{
    int temp[last - first + 1];
    int k = 0;
    int firstTemp = first;
    int midTemp = mid + 1;
    while((firstTemp <= mid) && ( midTemp<=last))
    {
        if( a[firstTemp] <= a[midTemp])
        {
            temp[k] = a[firstTemp];
            firstTemp++;
        }
        else
        {
            temp[k] = a[midTemp];
            midTemp++;
        }
        k++;
    }
    
    if( midTemp > last)
    {
        for( int i = firstTemp ; i <= mid ; i++ )
        {
            temp[k] = a[i];
            k++;
        }
    }
    else
    {
        for ( int i = midTemp ; i <= last ; i++)
        {
            temp[k] = a[i];
            k++;
        }
    }
    int i = 0;
    for ( int k = first ; k <= last ; k++)
    {
        a[k] = temp[i];
        i++;
    }
}

/*Complexity of this function: */
void mergeSort (int * a , int first , int last )
{
    if( first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(a, first , mid);
        mergeSort(a, mid + 1 , last);
        merge( a , first , mid , last);
    }
}


int main()
{
    int a[10] = {5,2,4,7,1,3,2,6,0,8};
    mergeSort(a , 0 , 9);
    for(int i = 0; i < 10; i++)
    {
        cout<<a[i]<<endl;
    }
}
