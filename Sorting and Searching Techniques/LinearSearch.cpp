/*C++ Code to implement Linear Search for searching an element in a array */


#include <bits/stdc++.h>
using namespace std;

template <class T>
int linear_search(T A[], int length, int elem)
    //Performs linear search to find the index of given element otherwise returns -1

    {
        for (int i=0; i<length; i++)
        {
            if (A[i]==elem)
                return i;
        }
        return -1;
    }

int main()
{
    int length, element;
    cout<<"Enter the number of elements you want to insert in array: ";
    cin>>length;
    int array[length];    //You can change the datatype to float, char, double or string also
    for (int i=0; i<length; i++)
    {
        cout<<"Enter element: ";
        cin>>array[i];
    }
    cout<<"Enter the element you want to find index of in array: ";
    cin>>element;
    int index=linear_search(array, length, element);
    if (index==-1)
    {
        cout<<"Element not found in array"<<endl;
    }
    else
    {
        cout<<"Index of element "<<element<<" in array: "<<index<<endl;
    }
}