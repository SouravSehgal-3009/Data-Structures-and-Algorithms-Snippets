//C++ Code to implement Circular Queue 

#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{private:
    int size;
    int front=-1;
    int rear=-1;
    int *arr;
public:
    CircularQueue(int size)
    {
        this->size=size;
        arr= new int[size];
    }

    void enqueue(int n)
    {
        if ((rear+1)%size==front)
        {
            cout<<"Queue overflow"<<endl;
            return;
        }
        else
        {
            rear=(rear+1)%size;
            arr[rear]=n;
        }
    }

    int dequeue()
    {
        int x=-1;
        if (front==rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            front=(front+1)%size;
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
        cout<<"Circular Queue: ";
        int i=front+1;
        while (i!=rear+1)
        {
            cout<<arr[i]<<" ";
            i=(i+1)%size;
        }
        cout<<endl;
    }
};

int main()
{
    CircularQueue Q1(5);
    Q1.enqueue(4);
    Q1.enqueue(9);
    Q1.enqueue(7);
    Q1.enqueue(11);
    Q1.display();
    Q1.dequeue();
    Q1.dequeue();
    Q1.display();
    Q1.enqueue(14);
    Q1.enqueue(19);
    Q1.enqueue(17);
    Q1.display();
    Q1.dequeue();
    Q1.enqueue(21);
    Q1.enqueue(0);
    Q1.enqueue(10);
    Q1.display();
}

