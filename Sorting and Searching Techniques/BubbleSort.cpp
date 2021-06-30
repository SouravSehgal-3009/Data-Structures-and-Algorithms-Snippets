/*C++ Code to implement Bubble Sort on a array */

#include <bits/stdc++.h>
using namespace std;

template <class T>
void BubbleSort(T A[],int length)
{
    int flag;
    for (int i=0; i<length-1; i++)
    {
        flag=0;
        for (int j=1; j<length-i; j++)
        {
            if (A[j]<A[j-1])
            {
                swap(A[j],A[j-1]);
                flag=1;
            }
        }
        if (flag==0)    
        //Will execute if array is already sorted now and no need for furthur comparisons
        {
            break;    
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
    BubbleSort(array,length);
    Display(array, length);
}