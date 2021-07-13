/* Given an array containing N integers and a number S denoting a target sum. Find triplets that can 
form target sum. */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int partsum)
{
    vector<vector<int>> vec1;
    sort(arr.begin(), arr.end());
    int n=arr.size();
    int j,k;
    for (int i=0; i<n-3; i++)
    {
        j=i+1;
        k=n-1;
        while (j<k)
        {
            int x=arr[i]+arr[j]+arr[k];
            if (x==partsum)
            {
                vec1.push_back({arr[i],arr[j], arr[k]});
                break;
            }
            else if (x>partsum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return vec1;
}

int main()
{
    vector<int> vec={1,2,3,4,5,6,7,8,9,15};
    vector<vector<int>> result=triplets(vec, 18);
    for (auto x: result)
    {
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    }
}