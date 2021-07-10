/* C++ Code to implement Chaining */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Chaining
{
private:
    Node **bins;
public:
    Chaining()
    {
        bins=new Node*[10];
        for (int i=0; i<10; i++)
        {
            bins[i]=NULL;
        }
    }

    int hashfun(int x)
    {   
        return x%10;
    }

    Node *insert_sorted(Node *p, int elem)
    {
        Node *temp=new Node;
        temp->data=elem;
        temp->next=NULL;
        
        if(p==NULL)
        {
            return temp;    
        }
        else if (p->data>elem)
        {
            temp->next=p;
            return temp;
        }
        else
        {
            while (p && p->next)
            {
                if (p->next->data<elem)
                {
                    p=p->next;
                }
                else
                {
                    break;
                }
            }
            temp->next=p->next;
            p->next=temp;
        }
        return p;
    }

    void insert(int A[], int length)
    {
        for (int i=0; i<length; i++)
        {
            int x=hashfun(A[i]);
            bins[x]=insert_sorted(bins[x], A[i]);
        }
    }

    Node *search(int key)
    {
        int y=hashfun(key);
        Node *p=bins[y];
        while (p && p->data!=key)
        {
            p=p->next;
        }
        if (!p) return NULL;
        return p;
    }
};

int main()
{
    int A[]={45, 23, 9, 81,21, 24, 59};
    Chaining ch1;
    ch1.insert(A, sizeof(A)/sizeof(A[0]));
    cout<<"Search: "<<ch1.search(31);
}