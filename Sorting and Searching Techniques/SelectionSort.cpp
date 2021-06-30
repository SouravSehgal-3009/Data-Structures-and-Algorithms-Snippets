/*C++ Code to implement Selection Sort on a array */

#include <bits/stdc++.h>
using namespace std;

template <class T>
void SelectionSort(T A[], int length)
{
    for (int i=0; i<length-1; i++)
    {
        int k=i;
        for (int j=i+1; j<length; j++)
        {
            if (A[j]<A[k])
            {
                k=j;
            }
        }
        swap(A[i],A[k]);
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
    SelectionSort(array, length);
    Display(array, length);
}