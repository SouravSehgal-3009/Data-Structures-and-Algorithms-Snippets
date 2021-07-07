//C++ Code to implement DEQueue using Linked List

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class DEQueue
{
    private:
        Node *front;
        Node *rear;
    public:
        DEQueue()
        {
            front=NULL;
            rear=NULL;
        }

        void Renqueue(int n)
        {
            Node *temp=new Node;
            temp->data=n;
            temp->next=NULL;
            if (!temp)
            {
                cout<<"Queue Overflow"<<endl;
            }
            else if (front==NULL)
            {
                front=rear=temp;
            }
            else
            {
                rear->next=temp;
                rear=temp;
            }
        }

        void Fenqueue(int n)
        {
            Node *temp=new Node;
            temp->data=n;
            temp->next=NULL;
            if (!temp)
            {
                cout<<"Queue Overflow"<<endl;
            }
            else if (front==NULL)
            {
                front=rear=temp;
            }
            else
            {
                temp->next=front;
                front=temp;
            }
        }

        int Fdequeue()
        {
            int x=-1;
            if (front==NULL)
            {
                cout<<"Queue is empty"<<endl;
            }
            else
            {
                Node *p=front;
                x=front->data;
                front=front->next;
                delete p;  
            }
            return x;
        }

        void Rdequeue()
        {
            int x=-1;
            if (front==NULL)
            {
                cout<<"Queue is empty"<<endl;
            }
            else
            {
                Node *p=front;
                while (p->next!=rear)
                {
                    p=p->next;
                }
                p->next=NULL;
                delete rear;
                rear=p;
            }
        }

        int Queuefront()
        {
            return front->data;
        }

        int Queuerear()
        {
            return front->data;
        }

        void display()
        {
            Node *p=front;
            cout<<"DEQueue: ";
            while (p)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }
};

int main()
{
    DEQueue Q1;
    Q1.Fenqueue(4);
    Q1.Fenqueue(9);
    Q1.Renqueue(7);
    Q1.Renqueue(11);
    Q1.display();
    Q1.Fdequeue();
    Q1.Rdequeue();
    Q1.display();
}