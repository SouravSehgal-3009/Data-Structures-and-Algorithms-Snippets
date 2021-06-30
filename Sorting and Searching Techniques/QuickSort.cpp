/*C++ Code to implement Quick Sort on a array */


#include <bits/stdc++.h>
using namespace std;

template <class T>
int partition(T A[], int low, int high)
{
    int j=low, k=high;
    T pivot=A[low];
    while(j<k)
    {
        while(A[j]<=pivot)
        {
            if (j==high)
                break;
            j++;
        }
        while(A[k]>=pivot)
        {
            if(k==low)
            {
                break;
            }
            k--;
        }
        if (j<k)
            swap(A[j],A[k]);
    }
    swap(A[low],A[k]);
    return k;
}

template <class T>
void Quicksort(T A[], int low, int high)
{
    if (low<high)
    {
        int p=partition(A, low, high);
        Quicksort(A, low, p);
        Quicksort(A, p+1, high);
    }
}

template <class T>
void Display(T A[], int length)
{
    cout<<"Sorted Array: ";
    for (int i=0; i<length; i++)
    {
        cout<<A[i]<<" ";
    }
}


int main()
{
    int length;
    cout<<"Enter the number of elements you want to insert in array: ";
    cin>>length;
    int array[length];    //You can change the datatype to float, char, double or string also
    for (int i=0; i<length; i++)
    {
        cout<<"Enter element: ";
        cin>>array[i];
    }
    Quicksort(array,0, length-1);
    Display(array, length);
}