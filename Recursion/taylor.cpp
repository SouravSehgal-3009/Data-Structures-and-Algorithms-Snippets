/*C++ Code to calculate Taylor Series expansion of e^x upto n terms using Recursion */

#include <bits/stdc++.h>
using namespace std;

float taylor(int x, int n)
{
    static float p=1;
    static int f=1;
    float r;
    if (n==0)
        return 1;
    r=taylor(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
}

int main()
{
    int x,n;
    cout<<"Enter the integer x: ";
    cin>>x;
    cout<<"Enter the integer n: ";
    cin>>n;
    cout<<"Taylor expansion of e^"<<x<<" upto "<<n<<" terms: "<<taylor(x,n);
}