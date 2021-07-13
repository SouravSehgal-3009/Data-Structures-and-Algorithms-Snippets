/*Subarray Sort */

#include <bits/stdc++.h>
using namespace std;

bool inOrder(vector<int> vec1, int index)
{
    if (index==0) return vec1[0]<vec1[1];
    else if (index==vec1.size()-1) return vec1[index-1]<vec1[index];
    else if (vec1[index-1]>vec1[index] || vec1[index]>vec1[index+1]) return false;
    return true;
}

pair<int,int> subarraysort(vector<int> vec1)
{
    int smallest=INT_MAX;
    int highest=INT_MIN;
    for (int i=0; i<vec1.size(); i++)
    {
        if (!inOrder(vec1, i))
        {
            cout<<i<<" "<<inOrder(vec1, i)<<endl;
            smallest=min(smallest, vec1[i]);
            highest=max(highest, vec1[i]);
            cout<<smallest<<" "<<highest<<endl;
        }
    }
    if (smallest==INT_MIN) return {-1,-1};
    int i=0, j=vec1.size()-1;
    while (vec1[i]<=smallest) i++;
    while (vec1[j]>=highest) j--;
    return {i,j};
}

int main()
{
    vector<int> vec1={1,2,3,12,5,8,6,7,9,10,11};
    auto p=subarraysort(vec1);
    cout<<"Index: "<<p.first<<" "<<p.second;
}