/*C++ Code to implement Insertion Sort on a array */

#include <bits/stdc++.h>
using namespace std;

template <class T>
void InsertionSort(T A[], int length)
{
    for (int i=1; i<length; i++)
    {
        int j=i;
        int x=A[j];
        while (j>0 && x<A[j-1])
        {
            A[j--]=A[j-1];
            
        }
        A[j]=x;
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
    InsertionSort(array,length);
    Display(array, length);
}