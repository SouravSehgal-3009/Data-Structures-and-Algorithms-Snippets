//C++ Code to implement Infix to Postfix Conversion using Stack

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char op)
//To check whether input is operand or not
{
    if (op=='+' || op=='-'|| op=='*'||op=='/' || op=='^' || op=='(' || op==')')
        return false;
    else    
        return true;
}

int outstack_prec(char oper)
//Precedence of operator out of stack
{
    if (oper=='+' || oper=='-')
        return 1;
    else if (oper=='*' || oper=='/')
        return 3;
    else if (oper=='^')
        return 6;  
    else if (oper=='(')
        return 7;
    return 0;
}

int instack_prec(char oper)
//Precedence of operator inside stack
{
    if (oper=='+' || oper=='-')
        return 2;
    else if (oper=='*' || oper=='/')
        return 4;
    else if (oper=='^')
        return 5;  
    else if (oper=='(')
        return 0;
    return 0;
}

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

string InfixToPostfx(string s)
//Conversion from infix to postfix
{
    string postfix="";
    Stack S1;
    for (char x: s)
    {
        if (isOperand(x))
        {
            postfix.push_back(x);
        }
        else{
            while (!S1.isEmpty() && outstack_prec(x)<=instack_prec(S1.StackTop()))
            {
                if (S1.StackTop()!='(')
                    postfix.push_back(S1.StackTop());
                S1.pop();
            }
            if (x!=')')
                S1.push(x);
        }
    }
    while (!S1.isEmpty())
    {
        if (S1.StackTop()!='(')
                postfix.push_back(S1.StackTop());
        S1.pop();
    }
    return postfix;
}

int main()
{
    string infix="a+b*c-d/e";
    cout<<"Infix to Postfix: "<<InfixToPostfx(infix)<<endl;
    string infix1="(a+(b*c)-d)/e";
    cout<<"Infix to Postfix: "<<InfixToPostfx(infix1)<<endl;
    string infix2="(a+b)*c-d^e^f";
    cout<<"Infix to Postfix: "<<InfixToPostfx(infix2)<<endl;
}



