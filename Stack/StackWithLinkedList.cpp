//C++ Code to implement Stack with Linked List

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
        Stack()
        {
            top=NULL;
        }

        void push(int n)
        //To push element into Stack
        {
            Node *temp=new Node;
            temp->data=n;
            temp->next=NULL;
            if (top==NULL)
            {
                top=temp;
            }
            else if (this->isFull())
            {
                cout<<"Stack Overflow"<<endl;
                return;
            }
            else{
                temp->next=top;
                top=temp;
            }
        }

        int pop()
        //To pop element from Stack
        {
            int x=-1;
            if (top==NULL)
            {
                cout<<"Stack is Empty"<<endl;
            }
            else
            {
                Node *p=top;
                top=top->next;
                x=p->data;
                delete p;
            }
            return x;
        }

        bool isEmpty()
        //To check whether the stack is empty
        {
            if (top==NULL) return true;
            else return false;
        }

        bool isFull()
        //To check whether the stack is full
        {
            Node *y= new Node;
            if (y) return false; else return true;
        }

        int peek(int pos)
        //To find the element at given position in stack
        {
            Node *p=top;
            int current=1;
            while (p && current<pos)
            {
                p=p->next;
                current++;
            }
            if (current==pos && p)
            {
                return p->data;
            }
            return -1;
        }

        int StackTop()
        //To return element at top of stack
        {
            return top->data;
        }

        void display()
        //To display contents of stack
        {
            Node *p=top;
            cout<<"Stack: ";
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
    Stack S1;
    S1.push(6);
    S1.push(3);
    S1.push(11);
    S1.display();
    cout<<S1.peek(2)<<endl;
    S1.pop();
    S1.display();

}