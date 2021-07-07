//C++ Code to implement Queue with Array

#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int size;
    int front=-1;
    int rear=-1;
    int *arr;
public:
    Queue(int size)
    {
        this->size=size;
        arr= new int[size];
    }

    void enqueue(int n)
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

    int dequeue()
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
    Queue Q1(5);
    Q1.enqueue(4);
    Q1.enqueue(9);
    Q1.enqueue(7);
    Q1.enqueue(11);
    Q1.display();
    Q1.dequeue();
    Q1.dequeue();
    Q1.display();
}
