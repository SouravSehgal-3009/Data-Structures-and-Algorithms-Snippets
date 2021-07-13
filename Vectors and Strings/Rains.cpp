/* Given n non negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap 
after raining. */

#include <bits/stdc++.h>
using namespace std;

int minimum(int a, int b)
{
    return (a<=b)?a:b;
}
int rain_unit(vector<int> vec1)
{
    int n=vec1.size();
    int left[n], right[n];
    int leftmax=0, rightmax=0, temp;
    for (int i=0; i<n; i++)
    {
        if (vec1[i]>=leftmax) 
        {
            left[i]=vec1[i];
            leftmax=vec1[i];
        }
        else left[i]=leftmax;

    }
    for (int i=n-1; i>=0; i--)
    {
        if (vec1[i]>=rightmax)
        {
            right[i]=vec1[i];
            rightmax=vec1[i];
        }
        else right[i]=rightmax;
    }

    int units=0;
    for (int i=0; i<n; i++)
    {
        temp=minimum(left[i], right[i]);
        temp=temp-vec1[i];
        if (temp>0) units+=temp;
    }
    return units;
}

int main()
{
    vector<int> vec1={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rain_unit(vec1);
}