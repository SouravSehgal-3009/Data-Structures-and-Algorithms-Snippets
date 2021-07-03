/* C++ Code to implement basic functions of Linked List */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *Head, *Tail;
public:
    LinkedList()
    {
        Head=NULL;
        Tail=NULL;
    }

    void add_Node(int n)
    //Function to add node in the end of linked list
    {
        Node *temp=new Node;
        temp->data=n;
        temp->next=NULL;
        
        if(Head==NULL)
        {
            Head=temp;
            Tail=temp;
        }
        else
        {
            Tail->next=temp;
            Tail=Tail->next;
        }
    }

    void create_from_array(int A[], int length)
    //Function to add all the elements of an array as nodes in linked list
    {
        for (int i=0; i<length; i++)
        {
           this->add_Node(A[i]);
        }
    }

    void Display()
    //Function to display node data in linked list
    {
        Node *p=Head;
        cout<<"Linked List: ";
        while(p!=NULL)
        {
            cout<<p->data<<"->";
            p=p->next;
        }
        cout<<endl;
    }

    int CountNodes()
    //Function to count number of nodes in linked list
    {
        int count=0;
        Node *p=Head;
        while (p!=NULL)
        {
           count++;
           p=p->next; 
        }
        return count;
    }

    int SumNodes()
    //Function to calculate sum of node data in linked list
    {
        int sum=0;
        Node *p=Head;
        while (p!=NULL)
        {
            sum+=p->data;
            p=p->next;
        }
        return sum;
    }

    int max()
    //Function to calculate maximum node data value in linked list
    {
        Node *p=Head;
        int m=p->data;
        p=p->next;
        while (p)
        {
            if (m<p->data)
                m=p->data;
            p=p->next;
        }
        return m;
    }
    
    Node *Search(int elem)
    //Function to search address of given elemnt in linked list
    {
        Node *p=Head;
        while (p)
        {
            if (p->data==elem)
                return p;
            p=p->next;
        }
        return NULL;
    }

    void insert_at_first(int elem)
    //Function to insert a node in beginning of the linked list
    {
        if (Head==NULL)
        {
            add_Node(elem);
        }
        else
        {
        Node *temp=new Node;
        temp->data=elem;
        temp->next=Head;
        Head=temp;
        }
    }

    void insert_at_pos(int elem, int pos)
    //Function to insert node at given position in the linked list
    {
        int cnt=this->CountNodes();
        if (pos==1)
        {
            this->insert_at_first(elem);
        }
        else if (pos>1 && pos<=cnt)
        {
            int current=0;
            Node *temp=new Node, *p=Head;
            temp->data=elem;
            temp->next=NULL;
            while(p && current<pos-2)
            {
            current++;
            p=p->next;
            }
            temp->next=p->next;
            p->next=temp;
        }
        else if (pos==cnt+1)
        {
            this->insert_at_last(elem);
        }
        else    
            return;
    }

    void insert_at_last(int elem)
    //Function to calculate the node in the end of the linked list
    {
        if (Head==NULL)
        {
            add_Node(elem);
        }
        else
        {
            Node *temp=new Node, *p=Head;
            temp->data=elem;
            temp->next=NULL;
            Tail->next=temp;
            Tail=temp;
        }
    }

    bool isSorted()
    //Function to check whether nodes are sorted according to their data values
    {
        Node *p=Head;
        while (p && p->next)
        {
            if (p->data>p->next->data)
            {
                return false;
            }
            p=p->next;
        }
        return true;
    }

    void insert_sorted(int elem)
    /* Function to insert the node in sorted linked list in such a way that it remains
    sorted even after new node is inserted */
    {
        if (this->isSorted() && Head!=NULL)
        {
            if (Head->data>elem)
            {
                this->insert_at_first(elem);
            }
            else
            {
                Node*p=Head;
                while (p && p->next)
                {
                    if (p->next->data<elem)
                    {
                    p=p->next;
                    }
                    else{
                        break;
                    }
                }
                Node *temp=new Node;
                temp->data=elem;
                temp->next=p->next;
                p->next=temp;
            }
        }
        else
        {
            this->add_Node(elem);
        }
    }

    void Delete_at_first()
    //Function to delete node at the begining of linked list
    {
        Node *p=Head;
        Head=Head->next;
        delete p;
    }

    void Delete_at_last()
    //Function to delete the node at the end of the linked list
    {
        Node *p=Head;
        while (p->next!=Tail)
        {
            p-p->next;
        }
        Node *q=Tail;
        p->next=NULL;
        Tail=p;
        delete q;
    }

    void Delete_at_pos(int pos)
    //Function to delete the node at the given position in the linked list
    {
        int cnt=this->CountNodes();
        if (pos<=0 || pos>cnt)
        {
            return;
        }
        else if (pos==1)
        {
            this->Delete_at_first();
        }
        else if (pos==cnt)
        {
            this->Delete_at_last();
        }
        else{
            int current=0;
            Node *p=Head;
            while(p && current<pos-2)
            {
            current++;
            p=p->next;
            }
            Node *q=p->next;
            p->next=q->next;
            delete q;
        }
    }

    void rmv_dup_sorted()
    //Function to remove duplicates in a sorted linked list
    {
        Node *p=Head,*q=p->next;
        while (q)
        {
            if (q->data==p->data)
            {
                p->next=q->next;
                delete q;
                q=p->next;

            }
            else{
                p=q;
                q=p->next;
            }
        }
    }

    void Reverse()
    //Function to revers the linked list by reversing links
    {
        Node *p=Head, *q=NULL, *r=NULL;
        Tail=Head;
        while (p)
        {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
        }
        Head=q;
    }

    void concatenate(LinkedList l1)
    //Function to concatenate a linked list to another one
    {
        this->Tail->next=l1.Head;
        this->Tail=l1.Tail;
    }
    
    void merge(LinkedList l2)
    //Function to merge two linked lists
    {
        Node *first=this->Head,*second=l2.Head, *last;
        if (first->data<=second->data)
        {
            last=first;
            first=first->next;
            last->next=NULL;    
            this->Head=last;
   }
        else
        {
            last=second;
            second=second->next;
            last->next=NULL;
            this->Head=last;

        }

        while (first!=NULL && second!=NULL)
        {
            if (first->data<=second->data)
            {
                last->next=first;
                last=first;
                first=first->next;
                last->next=NULL;
            }
            else{

                last->next=second;
                last=second;
                second=second->next;
                last->next=NULL;
            } 
        }
            
        while (first)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }

        while (second)
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }

        this->Tail=last;
    }

    bool isLoop()
    //Function to check whether there is a loop in given linked list
    {
        Node *p=Head, *q=Head;
        while (p && q && p!=q)
        {
            p=p->next;
            q=q->next;
            q=(q!=NULL)?q->next:NULL;
        }
        if (p==q)
            return true;
        else
            return false;
    }

    void makeloop()
    //Function to make a loop in linked list by making it a circular linked list
    {
        Tail->next=Head;
    }

    int mid_value()
    //Function to find data value of middle node of Linked List
    {
        Node *p=Head, *q=Head;
        while(q)
        {
            if (q) {q=q->next;}
            if (q) {q=q->next;}
            if (q){p=p->next;}
        }
        return p->data;
    }
};

int main()
{
    int A[5]={1,2,3,14,16};
    LinkedList ls;
    ls.create_from_array(A,5);
    ls.Display();
    ls.insert_sorted(14);
    ls.Display();
    ls.Delete_at_pos(13);
    ls.Display();
    LinkedList ls2;
    int A1[6]={11,12,13,14,16,17};
    ls2.create_from_array(A1, 6);
    ls.merge(ls2);
    ls.Display();
    cout<<"Count of nodes in ls: "<<ls.CountNodes()<<endl;
    cout<<"Sum of nodes in ls: "<<ls.SumNodes()<<endl;
    cout<<"Maximum value in ls is: "<<ls.max()<<endl;
    cout<<"Address of 14 in ls: "<<ls.Search(14)<<endl;
    cout<<"Middle element: "<<ls.mid_value()<<endl;
}
