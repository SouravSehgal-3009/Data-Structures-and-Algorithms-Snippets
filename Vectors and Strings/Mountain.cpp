/* Function that takes input an array of distinct integers and returns the length of highest mountain */

#include <bits/stdc++.h>
using namespace std;

int highest_mountain(vector<int> arr)
{
    int len=arr.size();
    int max=0, temp, j, k;
    for (int i=1; i<len-1; i++)
    {
        if (arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
            temp=0;
            j=i;
            while (j-1>=0 && arr[j-1]<arr[j])
            {
                temp++;
                j--;
            }
            k=i;
            while (k+1<len && arr[k+1]<arr[k])
            {
                temp++;
                k++;
            }
            temp++;
            if (temp>max)   max=temp;
        }
    }
    return max;
}

int main()
{
    vector<int> vec1={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<highest_mountain(vec1);
}