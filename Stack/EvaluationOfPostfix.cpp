//C++ Code to evaluate Postfix Expression

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char op)
//To check whether input is operand or not
{
    if (op=='+' || op=='-'|| op=='*'||op=='/' || op=='^')
        return false;
    else    
        return true;
}

class Node
{
public:
    float data;
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

        void push(float n)
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

        float pop()
        //To pop element from Stack
        {
            float x=-1;
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

        float StackTop()
        //To return element at top of stack
        {
            return top->data;
        }
};

float EvalPostfix(string inp)
//Function to evaluate given postfix expression
{
    Stack S1;
    for (char x: inp)
    {
        if (isOperand(x))
        {
            int y=x-'0';
            S1.push(y);
        }
        else
        {
            float m1=S1.pop(), m2=S1.pop(), z;
            switch(x)
            {
                case '+':
                    z=m2+m1;
                    S1.push(z);
                    break;
                case '-':
                    z=m2-m1;
                    S1.push(z);
                    break;
                case '*':
                    z=m2*m1;
                    S1.push(z);
                    break;
                case '/':
                    z=m2/m1;
                    S1.push(z);
                    break;
                case '^':
                    z=pow(m2, m1);
                    S1.push(z);
                    break;
            }        
            }
    }
    return S1.pop();
}

int main()
{
    string s1="348*+2-5/";
    cout<<"Result: "<<EvalPostfix(s1)<<endl;
    string s2="34+8*222^^-";
    cout<<"Result: "<<EvalPostfix(s2)<<endl;
}