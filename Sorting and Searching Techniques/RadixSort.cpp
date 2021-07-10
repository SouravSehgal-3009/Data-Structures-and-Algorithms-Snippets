//C++ Code to implement Radix Sort

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *insert(Node *p, int elem)
{
    Node *temp=new Node;
    temp->data=elem;
    temp->next=NULL;
    if (p==NULL)
        p=temp;
    else
    {
        temp->next=p;
    }
    return temp;
}

Node *Delete(Node *p)
{
    Node *temp=p->next;
    delete p;
    return temp;
}

int max(int A[], int length)
    //Returns element with maximum value in the array
{
        int max_elem=A[0];
        for (int i=0; i<length; i++)
        {
            if (A[i]>max_elem)
                max_elem=A[i];

        }
        return max_elem;
}

int digits(int n)
//To calculate number of digits in a number
{
    int count=0;
    while (n>0)
    {
        n=n/10;
        count++;
    }
    return count;
}

int power(int m, int n)
//To calculate m^n
{
    int p=1;
    while (n)
    {
        p=p*m;
        n--;
    }
    return p;
}

void Display(int A[], int length)
{
    cout<<"Sorted Array: ";
    for (int i=0; i<length; i++)
    {
        cout<<A[i]<<" ";
    }
}


void RadixSort(int A[], int length)
{
    int maximum= max(A, length);
    Node **bins= new Node*[10];
    int d=digits(maximum);
    for (int j=1; j<=d; j++)
    {
        for (int i=0; i<=maximum; i++)
        {
            bins[i]=NULL;
        }
        for (int i=length-1; i>=0; i--)
        {
            int x=(A[i]%(power(10,j)))/(power(10,j-1));
            bins[x]=insert(bins[x], A[i]);
        }
        Display(A,length);
        int i=0, k=0;
        while (i<=9)
        {
            while (bins[i])
            {
                A[k++]=bins[i]->data;
                bins[i]=Delete(bins[i]);
            }
            i++;
        }
        Display(A,length);
    }
}


int main()
{
    int length;
    cout<<"Enter the number of elements you want to insert in array: ";
    cin>>length;
    int array[length];   
    for (int i=0; i<length; i++)
    {
        cout<<"Enter element: ";
        cin>>array[i];
    }
    RadixSort(array, length);
    Display(array, length);
}