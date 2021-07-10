/* C++ Code to implement Linear Probing */

#include <bits/stdc++.h>
using namespace std;

#define size 10

class LinearProbing
{
private:
    int *arr;
public:
    LinearProbing()
    {
        arr=new int[size];
        for (int i=0; i<size; i++)
        {
            arr[i]=0;
        }
    }

    int Hash(int x)
    {
        return x%10;    
    }

    int probe(int key)
    {
        int index=Hash(key);
        int i=0;
        if (arr[index]!=0)
        {
            while (arr[(index+i)%size]!=0)
            {
                i++;
            }
        }
        return (index+i)%size;
    }

    void insert(int A[], int length)
    {
        for (int i=0; i<length; i++)
        {
            int index=probe(A[i]);
            arr[index]=A[i];
        }
    }

    int search(int key)
    {
        int index=Hash(key);
        if (arr[index]==key) return index;
        int i=0;
        while (arr[(index+i)%size]!=key)
        {
            if (arr[(index+i)%size]==0) break;
            i++;
        }
        if (arr[(index+i)%size]==0) return -1;
        return (index+i)%size;
    }
};

int main()
{
    int A[]={45, 23, 9, 81,21, 24, 59};
    LinearProbing lp1;
    lp1.insert(A, sizeof(A)/sizeof(A[0]));
    cout<<"Search: "<<lp1.search(9);
}