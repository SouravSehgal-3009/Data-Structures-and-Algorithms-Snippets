//C++ Code to implement Queue using Linked List

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
    private:
        Node *front;
        Node *rear;
    public:
        Queue()
        {
            front=NULL;
            rear=NULL;
        }

        void enqueue(int n)
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

        int dequeue()
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
            cout<<"Queue: ";
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
    Queue Q1;
    Q1.enqueue(4);
    Q1.enqueue(9);
    Q1.enqueue(7);
    Q1.enqueue(11);
    Q1.display();
    Q1.dequeue();
    Q1.dequeue();
    Q1.display();
}
