/* Given an array containing N integers and a number S denoting a target sum. Find two distinct integers that can 
form target sum. */

#include <bits/stdc++.h>
using namespace std;

vector<int> pairsum(vector<int> A, int partsum)
{
    unordered_set<int> s1;
    vector<int> result;
    for (int i=0; i<A.size(); i++)
    {
        int x=partsum-A[i];
        if (s1.find(x)!=s1.end())
        {
            result.push_back(x);
            result.push_back(A[i]);
        }
        else
        {
            s1.insert(A[i]);
        }
    }
    return result;
}

int main()
{
    vector<int> vec={10,5,2,3,-6,9,11};
    vector<int> vec2=pairsum(vec,4);
    cout<<"Pair: ";
    for (auto x: vec2)
    {
        cout<<x<<" ";
    }
}
