/* C++ Code to implement Double Hashing */

#include <bits/stdc++.h>
using namespace std;

#define size 10

class DoubleHashing
{
private:
    int *arr;
public:
    DoubleHashing()
    {
        arr=new int[size];
        for (int i=0; i<size; i++)
        {
            arr[i]=0;
        }
    }

    int Hash1(int x)
    {
        return x%10;    
    }

    int Hash2(int x)
    {
        return 7-x%7;    
    }

    int Hash3(int x, int i)
    {
        return (Hash1(x)+i*Hash2(x))%10;
    }

    int Hash(int key)
    {
        int index=Hash1(key);
        int i=0;
        if (arr[index]!=0)
        {
            while (arr[Hash3(key, i)]!=0)
            {
                i++;
            }
        }
        return Hash3(key, i);
    }

    void insert(int A[], int length)
    {
        for (int i=0; i<length; i++)
        {
            int index=Hash(A[i]);
            arr[index]=A[i];
        }
    }

    int search(int key)
    {
        int index=Hash(key);
        if (arr[index]==key) return index;
        int i=0;
        while (arr[Hash3(key, i)]!=key)
        {
            if (arr[Hash3(key, i)]==0) break;
            i++;
        }
        if (arr[Hash3(key, i)]==0) return -1;
        return Hash3(key, i);
    }
};

int main()
{
    int A[]={45, 23, 9, 81,21, 24, 59};
    DoubleHashing dh;
    dh.insert(A, sizeof(A)/sizeof(A[0]));
    cout<<"Search: "<<dh.search(21);
}