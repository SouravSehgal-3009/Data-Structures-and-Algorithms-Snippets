//C++ Code to implement Stack with the help of Array

#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *S;
public:
    Stack()
    {
        size=0;
        top=-1;
    }

    Stack(int size)
    //To create a stack with size 'size'
    {
        this->size=size;
        S= new int[size];
        top=-1;

    }

    int getStackTop()
    //To return element at top of stack
    {
        return top;
    }

    void push(int x)
    //To push element into top of stack
    {
        if (top==size-1)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
        top++;
        S[top]=x;
        }
    }

    int pop()
    //To pop element from top of stack
    {
        if (top==-1)
        {
            cout<<"Stack Overflow"<<endl;
            return -1;
        }
        int x=S[top];
        top--;
        return x;
    }

    void display()
    //To display contents of the stack
    {
        cout<<"Stack: ";
        for (int i=top; i>=0;i--)
        {
            cout<<S[i]<<" ";
        }
        cout<<endl;
    }

    int peek(int pos)
    //To find the element at given position in stack
    {
        if (top-pos+1<0)
        {
            cout<<"Invalid index";
            return -1;
        }
        int x=S[top-pos+1];
        return x;
        
    }

    bool isEmpty()
    //To check whether the stack is empty
    {
        if (top==-1)
            return true;
        return false;
    }

    bool isFull()
    //To check whether the stack is full
    {
        if (top==size-1)
        {
            return true;
        }
        return false;
    }

};

int main()
{
    Stack S1(5);
    S1.push(10);
    S1.push(3);
    S1.display();
    S1.pop();
    S1.display();
    cout<<S1.isEmpty();

}