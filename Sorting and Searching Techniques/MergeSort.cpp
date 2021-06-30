/*C++ Code to implement Merge Sort on a array */

#include <bits/stdc++.h>
using namespace std;

template <class T>
void Merge(T A[], int low, int mid, int high)
{
    int i=low, j=mid+1, k=low;
    int arr[high+1];
    while (i<=mid && j<=high)
    {
        if (A[i]<=A[j])
        {
            arr[k++]=A[i++];
        }
        else
        {
            arr[k++]=A[j++];
        }
    }
    while (i<=mid)
    {
            arr[k++]=A[i++];
    }
    while (j<=high)
    {
            arr[k++]=A[j++];
    }
    for (int i=low; i<=high; i++)
    {
        A[i]=arr[i];
    }
}

template <class T>
void MergeSort(T A[], int low, int high)
{
    if (low<high)
    {
        int mid=(low+high)/2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
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
    MergeSort(array, 0, length-1);
    Display(array, length);
}

