/*C++ Code to implement Binary Search for searching an element in a array */


#include <bits/stdc++.h>
using namespace std;

template <class T>
int binary_search(T A[], int low, int high,int elem)
    //Performs binary search to find the index of given element otherwise returns -1
    {
        if (low<=high)
        {
            int mid=(low+high)/2;
            if (A[mid]==elem)
                return mid;
            else if (A[mid]<elem)
                low=mid+1;
            else
                high=mid-1;
            return binary_search(A, low, high, elem);
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
    int index=binary_search(array, 0, length-1, element);
    if (index==-1)
    {
        cout<<"Element not found in array"<<endl;
    }
    else
    {
        cout<<"Index of element "<<element<<" in array: "<<index<<endl;
    }
}