/*C++ Code to implement Circlar Doubly Linked List */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class CircularDoublyLinkedList
{
private:
    Node *Head;
    Node *Tail;
public:
    CircularDoublyLinkedList()
    {
        Head=NULL;
        Tail=NULL;
    }
    void addNode(int n)
    //Function to add new node in Circular doubly linked list
    {
        Node *temp=new Node;
        temp->prev=NULL;
        temp->data=n;
        temp->next=NULL;
        if (Head==NULL)
        {
            Head=temp;
            Tail=temp;
            Head->next=Head;
            Head->prev=Head;;
        }
        else
        {
            Tail->next=temp;
            temp->prev=Tail;
            temp->next=Head;
            Head->prev=temp;
            Tail=temp;
        }
    }

    void create_from_array(int A[], int length)
    //Function to add elements of array in Circular Doubly linked list
    {
        for (int i=0; i<length; i++)
        {
            addNode(A[i]);
        }
    }

    void display()
    //To display data node values of Circular Doubly Linked List
    {
        Node *p=Head;
        cout<<"Circular Doubly Linked List: ";
        do
        {
            cout<<p->data<<"->";
            p=p->next;
        } while (p!=Head);

        cout<<endl;
        
    }

    int CountNodes()
    //To count number of nodes in Circular Doubly Linked List
    {
        Node *p=Head;
        int count;
        do
        {
            count++;
            p=p->next;
        } while(p!=Head);
        return count;
    }

    void insert_at_first(int n)
    //To insert element in beginning of Circular Doubly Linked List
    {
        if (Head==NULL)
        {
            this->addNode(n);
        }
        else
        {
            Node *temp=new Node;
            temp->data=n;
            temp->next=Head;
            temp->prev=Tail;
            Tail->next=temp;
            Head->prev=temp;
            Head=temp;
        }
    }

    void insert_at_end(int n)
    //To insert element at end of Circular Doubly Linked List
    {
        if (Head==NULL)
        {
            this->addNode(n);
        }
        else
        {
            Node *temp=new Node;
            temp->data=n;
            temp->prev=Tail;
            temp->next=Head;
            Tail->next=temp;
            Head->prev=temp;
            Tail=temp;
        }
    }

    void insert_at_pos(int pos, int elem)
    //Function to insert an element at given position in Circular doubly linked list

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
    //Function to delete an element at beginning of Circular doubly linked list

    {
        Node *p=Head;
        p->next->prev=Tail;
        Tail->next=p->next;
        delete Head;
        Head=Tail->next;
    }

    void delete_at_last()
    //Function to delete an element at end of Circular doubly linked list

    {
         Tail->prev->next=Head;
         Head->prev=Tail->prev;
         delete Tail;
         Tail=Head->prev;
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
};

int main()
{
    CircularDoublyLinkedList cdls;
    int A[4]={1,2,3,4};
    cdls.create_from_array(A,4);
    cdls.display();
    cdls.insert_at_pos(3,11);
    cdls.display();
    cdls.insert_at_first(0);
    cdls.display();
    cdls.delete_at_last();
    cdls.display();
}
