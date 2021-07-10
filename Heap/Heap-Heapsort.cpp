//C++ Code to implement creation of a heap and Heap Sort

#include <bits/stdc++.h>
using namespace std;

void insert_in_heap(int A[],int n)
{
    int temp=A[n];
    int i=n;
    while (i>1 && A[i/2]<temp)
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

void create_heap(int A[], int length)
{
    for (int j=2; j<=length; j++)
    {
        insert_in_heap(A, j);
    }
}

void heapify(int A[], int length)
{
    int j;
    for (int i=length; i>=1; i--)
    {
        while (2*i<=length)
        {
            j=2*i;
            if (A[j]<A[j+1] && j+1<=length)
            {
                j++;
            }
            if (A[i]<A[j])
            {
                swap(A[i], A[j]);
            }
            else
                break;
            if (j==2*i) i=2*i;
            else i=2*i+1;
        }
    }
}

int delete_from_heap(int A[], int length)
{
    int temp=A[1];
    A[1]=A[length];
    int i=1, j=2*i;
    while (j<length-1)
    {
        if (A[j]<A[j+1])
        {
            j++;
        }
        if (A[i]<A[j])
        {
            swap(A[i], A[j]);
            i=2*i; j=2*j;
        }
        else    
            break;
    }
    return temp;
}

void Heapsort(int A[], int length)
{
    create_heap(A, length);
    for (int i=length; i>=1; i--)
    {
        A[i]=delete_from_heap(A, i);
    }
    cout<<"Sorted Array: ";
    for (int i=1; i<=length; i++)
    {
        cout<<A[i]<<" ";
    }
}

int main()
{
    int A[]={0,4,7,1,8,9,5};
    heapify(A,6);
    cout<<"Heap: ";
    for (int i=1; i<=6; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    int A1[]={10,14,17,11,18,19,15};

    Heapsort(A1,6);
    
}