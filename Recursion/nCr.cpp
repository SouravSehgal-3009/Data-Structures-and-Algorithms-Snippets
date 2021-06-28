/*C++ Code to calculate Combination(nCr) C(n,r) with help of Pascal Triangle using recursion */

#include <bits/stdc++.h>
using namespace std;

int nCr(int n,int r)
{
    if (r==0 || n==r)
    {
        return 1;
    }
    if (n<r)
        return -1;              //n<r Not Possible 
    return nCr(n-1, r-1)+nCr(n-1, r);
}

int main()
{
    int n, r;
    cout<<"Enter the value of n";
    cin>>n;
    cout<<"Enter the value of r";
    cin>>r;
    cout<<"Value of "<<n<<"C"<<r<<" is: "<<nCr(n, r);
}