/*Given an array find the length of the longest band (subsequence which can be reordered such that all elements 
appear consecutive). */

#include <bits/stdc++.h>
using namespace std;

int longest_band(vector<int> vec1)
{
    unordered_set<int> s1;
    int longest=0, temp;
    for (auto x: vec1)
    {
        s1.insert(x);
    }
    for (auto x: vec1)
    {
        if (s1.find(x-1)==s1.end())
        {
            temp=1;
            int y=x+1;
            while (s1.find(y)!=s1.end())
            {
                temp++;
                y++;
            }
            if (temp>longest) longest=temp;
        }
    }
    return longest;
}

int main()
{
    vector<int> vec1={1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<longest_band(vec1);
}