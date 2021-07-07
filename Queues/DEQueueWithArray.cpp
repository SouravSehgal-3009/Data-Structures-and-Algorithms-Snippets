//C++ Code to implement DEQueue with Array

#include <bits/stdc++.h>
using namespace std;

class DEQueue
{
private:
    int size;
    int front=-1;
    int rear=-1;
    int *arr;
public:
    DEQueue(int size)
    {
        this->size=size;
        arr= new int[size];
    }

    void Renqueue(int n)
    {
        if (rear==size-1)
        {
            cout<<"Queue overflow"<<endl;
            return;
        }
        else
        {
        rear++;
        arr[rear]=n;
        }
    }

    void Fenqueue(int n)
    {
        if (front==-1)
        {
            cout<<"Insertion from front is not possible"<<endl;
            return;
        }
        else
        {
            arr[front]=n;
            front--;
        }
    }

    int Fdequeue()
    {
        int x=-1;
        if (rear==front)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            front++;
            x=arr[front];

        }
        return x;
    }

    int Rdequeue()
    {
        int x=-1;
        if (rear==front)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            x=arr[rear];
            rear--;
        }
        return x;
    }

    int Queuefront()
    {
        return front;
    }

    int Queuerear()
    {
        return rear;
    }

    bool isEmpty()
    {
        if (front==rear) return true;
        else return false;
    }

    bool isFull()
    {
        if (rear==size-1) return true;
        else return false;
    }

    void display()
    {
        cout<<"Queue: ";
        for (int i=front+1; i<=rear; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    DEQueue Q1(5);
    Q1.Fenqueue(4);
    Q1.Fenqueue(9);
    Q1.Renqueue(7);
    Q1.Renqueue(11);
    Q1.display();
    Q1.Fdequeue();
    Q1.Rdequeue();
    Q1.display();
    Q1.Fenqueue(4);
    Q1.Fenqueue(9);
    Q1.display();
}