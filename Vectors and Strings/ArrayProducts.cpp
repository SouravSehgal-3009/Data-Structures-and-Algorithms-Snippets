#include <bits/stdc++.h>
using namespace std;

vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    int p=1, q=1, count=0;
    for (auto x: arr)
    {
        p=p*x;
        if (x!=0) q=q*x;
        else count++;
    }

    for (int i=0; i<n; i++)
    {
        if (count>1 && arr[i]==0)
              output[i]=p;
        else if (count==1 && arr[i]==0)
            output[i]=q;
        else
            output[i]=pow(arr[i],-1)*p;

    }
    return output;
}

int main()
{
    vector<int> vec1={1,2,3,1,5};
    auto vc2=productArray(vec1);
    for (auto x: vc2)
    {
        cout<<x<<" ";
    }
}
