/* C++ Code to implement basic functions of Circular Linked List */
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class CircularLinkedList
{
    private:
        Node *Head,*Tail;
    public:
        CircularLinkedList()
        {
            Head=NULL;
            Tail=NULL;
        }

        void addNode(int n)
        {
            Node *temp= new Node;
            temp->data=n;
            temp->next=NULL;

            if (Head==NULL)
            {
                Head=temp;
                Tail=temp;
                Head->next=Head;
            }
            else
            {
                Tail->next=temp;
                temp->next=Head;
                Tail=temp;
            }
        }

        void create_from_array(int A[], int length)
        //Function to add all the elements of an array as nodes in Circular Linked list
        {
          for (int i=0; i<length; i++)
            {
                this->addNode(A[i]);
            }
        }


        void display()
        {
            Node *p=Head;
            cout<<"Circular Linked List: ";
            do
            {
                cout<<p->data<<"->";
                p=p->next;
            } while (p!=Head);   
            cout<<endl;     
        }

        void insert_at_first(int elem)
        //Function to insert a node in beginning of the Circular Linked list
        {
            if (Head==NULL)
            {
                addNode(elem);
            }
            else{
                Node *temp= new Node;
                temp->data=elem;
                temp->next=Head;
                Tail->next=temp;
                Head=temp;
            }
        }

        void insert_at_last(int elem)
        //Function to insert a node in end of the Circular Linked list

        {
            if (Head==NULL)
            {
                addNode(elem);
            }
            else
            {
                Node *temp= new Node;
                temp->data=elem;
                temp->next=Head;
                Tail->next=temp;
                Tail=temp;
            }
        }

        void insert_at_pos(int pos, int elem)
        {
            //Function to insert node at given position in the Circular Linked list
    
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
        

        int CountNodes()
        //Function to count number of nodes in Circular Linked list
        {
            int count=0;
            Node *p=Head;
            do
            {
                count++;
                p=p->next;
            } while (p!=Head);

            return count;
        }

        void delete_at_first()
        //Function to delete the node at the beginning of the Circular Linked list

        {
            Tail->next=Head->next;
            delete Head;
            Head=Tail->next;
        }

        void delete_at_last()
        //Function to delete the node at the end of the Circular Linked list
        {
                Node *p=Head;
                while (p->next!=Tail)
                {
                    p-p->next;
                }
                p->next=Head;
                delete Tail;
                Tail=p;
        }

        void delete_at_pos(int pos)
        {
            //Function to delete the node at the given position in the Circular Linked list
            int cnt=this->CountNodes();
            if (pos<=0 || pos>cnt)
            {
                 return;
            }
            else if (pos==1)
            {
                this->delete_at_first();
            }
            else if (pos==cnt)
            {
                 this->delete_at_last();
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
    
};

int main()
{
    int A[5]={1,2,3,14,16};
    CircularLinkedList ls;
    ls.create_from_array(A,5);
    ls.display();
    ls.insert_at_first(11);
    ls.display();
    ls.insert_at_pos(4, 7);
    ls.display();
    ls.insert_at_last(10);
    ls.display();
    ls.delete_at_pos(3);
    ls.display();
    ls.delete_at_first();
    ls.display();
}