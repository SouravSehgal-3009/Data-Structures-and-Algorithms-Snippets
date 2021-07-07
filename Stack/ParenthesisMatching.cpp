//C++ Code to implement Paranthesis Matching

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
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

        void push(char n)
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

        void pop()
        //To pop element from Stack
        {
            if (top==NULL)
            {
                cout<<"Stack is Empty"<<endl;
            }
            else
            {
                Node *p=top;
                top=top->next;
                delete p;
            }
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

        char StackTop()
        //To return element at top of stack
        {
            return top->data;
        }
};

bool paranthesisMatch(string s1)
//Returns 1 if paranthesis match else returns 0
{
    Stack S;
    for (auto x: s1)
    {
        if (x=='(' || x=='[' || x=='{') S.push(x);
        if (x==')' || x==']' || x=='}')
        {
        if (S.StackTop()=='(' && x==')') S.pop();
        else if (S.StackTop()=='[' && x==']') S.pop();
        else if (S.StackTop()=='{' && x=='}') S.pop();
        else return false;
        }

    }
    if (S.isEmpty()) return true; else return false;
}

int main()
{
    string s="{[a+(b+c)*d]*f}";
    string s1="[(a-b)*c";
    cout<<"Result: "<<paranthesisMatch(s)<<endl;
    cout<<"Result: "<<paranthesisMatch(s1)<<endl;
}