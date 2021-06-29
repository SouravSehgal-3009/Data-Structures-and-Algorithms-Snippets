/*C++ Code to return duplicates in array of positive integers*/

#include <bits/stdc++.h>
using namespace std;
int max(int A[], int length)
    //Returns integer with maximum value in the array
{
        int max_elem=A[0];
        for (int i=0; i<length; i++)
        {
            if (A[i]>max_elem)
                max_elem=A[i];

        }
        return max_elem;
}

void duplicates(int A[], int length)
{
    int max_elem=max(A, length);
    int arr1[max_elem+1]={0};
    int count=0;
    for (int i=0; i<length; i++)
    {
        arr1[A[i]]++;
    }
    for (int i=0; i<=max_elem; i++ )
    {
        if (arr1[i]>1)
        {
            cout<<i<<" :"<<arr1[i]<<" duplicate values in array"<<endl;
            count++;
        }
    }
    if (count==0)
    {
        cout<<"No duplicate values in array"<<endl;
    }
}

int main()
{
    int length, K;
    cout<<"Enter the number of elements you want in array:";
    cin>>length;
    int array[length];
    for (int i=0; i<length; i++)
    {
        cout<<"Enter element: ";
        cin>>array[i];
    }
    duplicates(array, length);

}