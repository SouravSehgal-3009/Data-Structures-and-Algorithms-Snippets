/*C++ Code to implement Shell Sort on a array */

#include <bits/stdc++.h>
using namespace std;

template <class T>
void ShellSort(T A[], int length)
{
    int gap=length/2;
    while (gap>=1)
    {
        for (int i=gap; i<length; i++)
        {
            int j=i;
            T value=A[j];
            while(j-gap>=0 && A[j-gap]>value)
            {
                A[j]=A[j-gap];
                j=j-gap;
            }
            A[j]=value;
        }
        gap=gap/2;
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
    ShellSort(array, length);
    Display(array, length);
}