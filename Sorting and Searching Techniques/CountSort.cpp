/*C++ Code to implement Count Sort on a array */

#include <bits/stdc++.h>
using namespace std;

template <class T>
T max(T A[], int length)
    //Returns element with maximum value in the array
{
        T max_elem=A[0];
        for (int i=0; i<length; i++)
        {
            if (A[i]>max_elem)
                max_elem=A[i];

        }
        return max_elem;
}

template <class T>
void CountSort(T A[], int length)
{
    T maximum= max(A, length);
    int arr[maximum+1]={0};
    for (int i=0; i<length; i++)
    {
        arr[A[i]]++;
    }
    for (int i=0, k=0; i<=maximum; i++)
    {
        while(arr[i]>0)
        {
            A[k++]=i;
            arr[i]--;
        }
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
    CountSort(array, length);
    Display(array, length);
}