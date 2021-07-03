#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *Head;
    Node *Tail;
public:
    DoublyLinkedList()
    {
        Head=NULL;
        Tail=NULL;
    }
    void addNode(int n)
    //Function to add new node in doubly linked list
    {
        Node *temp=new Node;
        temp->prev=NULL;
        temp->data=n;
        temp->next=NULL;
        if (Head==NULL)
        {
            Head=temp;
            Tail=temp;
        }
        else
        {
            Tail->next=temp;
            temp->prev=Tail;
            Tail=temp;
        }
    }

    void create_from_array(int A[], int length)
    //Function to add elements of array in doubly linked list
    {
        for (int i=0; i<length; i++)
        {
            addNode(A[i]);
        }
    }

    void Display()
    //Function to display data node values in doubly linked list
    {
        Node *p=Head;
        cout<<"Doubly Linked List: ";
        while (p)
        {
            cout<<p->data<<"->";
            p=p->next;

        }
        cout<<endl;
    }

    int CountNodes()
    //Function to count nodes in doubly linked list
    {
        Node *p=Head;
        int count;
        while (p)
        {
            count++;
            p=p->next;

        }
        return count;
    }

    void insert_at_first(int n)
    //Function to delete an element at first in doubly linked list

    {
        if (Head==NULL)
        {
            this->addNode(n);
        }
        else
        {
            Node *temp=new Node;
            temp->prev=NULL;
            temp->data=n;
            temp->next=Head;
            Head->prev=temp;
            Head=temp;
        }
    }

    void insert_at_end(int n)
    //Function to insert an element at end in doubly linked list

    {
        if (Head==NULL)
        {
            this->addNode(n);
        }
        else
        {
            Node *temp=new Node;
            temp->data=n;
            temp->next=NULL;
            temp->prev=Tail;
            Tail->next=temp;
            Tail=temp;
        }
    }

    void insert_at_pos(int pos, int elem)
    //Function to insert an element at given position in doubly linked list

    {
        int x=this->CountNodes();
        if (pos==1)
        {
            this->insert_at_first(elem);
        }
        else if (pos==x+1)
        {
            this->insert_at_end(elem);
        }
        else if (pos>1 && pos<=x)
        {
            Node *temp=new Node;
            temp->data=elem;
            Node *p=Head;
            int current=1;
            while (current<pos-1)
            {
                p=p->next;
                current++;
            }
            temp->next=p->next;
            temp->prev=p;
            p->next=temp;
            temp->next->prev=temp;
            
        }
        else
            return;
    }

    void delete_at_first()
    //Function to delete an element at beginning of doubly linked list
    {
        Node *p=Head->next;
        p->prev=NULL;
        delete Head;
        Head=p;
    }

    void delete_at_last()
        //Function to delete an element in end of doubly linked list
    {
        Node *p=Tail->prev;
        p->next=NULL;
        delete Tail;
        Tail=p;
    }

    void delete_at_pos(int pos)
    //Function to delete an element at given position in doubly linked list
    {
        int x=this->CountNodes();
        if (pos==1)
        {
            this->delete_at_first();
        }
        else if (pos==x)
        {
            this->delete_at_last();
        }
        else if (pos>1 && pos<x)
        {
            Node *p=Head;
            int current=1;
            while (current<pos-1)
            {
                p=p->next;
                current++;
            }
            Node *q=p->next;
            p->next=q->next;
            p->next->prev=p;
            delete q;
        }
        else{
            return;
        }
    }

    void reverse()
    //Function to reverse Doubly Linked List
    {
        Node *p=Head;
        Tail=Head;
        while (p)
        {
            Node *temp=p->next;
            p->next=p->prev;
            p->prev=temp;
            if (p->prev)
            {
                p=p->prev;
            }
            else{
                Head=p;
                p=p->prev;
            }
        }
    }
};

int main()
{
    DoublyLinkedList dl1;
    int A[5]= {1,2,3,4,5};
    dl1.create_from_array(A,5);
    dl1.Display();
    dl1.insert_at_end(9);
    dl1.Display();
    dl1.insert_at_first(14);
    dl1.Display();
    dl1.delete_at_last();
    dl1.delete_at_pos(3);
    dl1.Display();
    dl1.insert_at_pos(3, 12);
    dl1.Display();
    dl1.reverse();
    dl1.Display();
    
}