/*C++ Code to return distinct pairs in array of positive integers with sum k */

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

void Pairs_with_sumK(int A[], int length, int K)
{
    int max_elem=max(A, length);
    int arr1[max_elem+1]={0};
    int count=0;
    for (int i=0; i<length; i++)
    {
        int p2=K-A[i];
        if (arr1[p2]!=0 && p2>=0 && arr1[A[i]]==0)
        {
            count++;
            arr1[A[i]]++;
            cout<<"Pair "<<count<<": ("<<p2<<","<<A[i]<<")"<<endl;
        }
        else
        {
           arr1[A[i]]++; 
        }
    }
    int p2=K/2;
    if (arr1[p2]>1)
    {
        count++;
        cout<<"Pair "<<count<<": ("<<p2<<","<<p2<<")"<<endl;
    }

    if(count==0)
        cout<<"No pairs found"<<endl;

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
    cout<<"Enter the number K to return pairs in array with sum K";
    cin>>K;
    Pairs_with_sumK(array, length, K);

}