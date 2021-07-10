//C++ Code to implement Bin Sort

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

void BinSort(int A[], int length)
{
    int maximum= max(A, length);
    Node **bins= new Node*[maximum+1];
    for (int i=0; i<=maximum; i++)
    {
        bins[i]=NULL;
    }
    for (int i=0; i<length; i++)
    {
        bins[A[i]]=insert(bins[A[i]], A[i]);
    }
    int i=0, j=0;
    while (i<=maximum)
    {
        while (bins[i])
        {
            bins[i]=Delete(bins[i]);
            A[j++]=i;
        }
        i++;
    }
}

void Display(int A[], int length)
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
    int array[length];    
    for (int i=0; i<length; i++)
    {
        cout<<"Enter element: ";
        cin>>array[i];
    }
    BinSort(array, length);
    Display(array, length);
}