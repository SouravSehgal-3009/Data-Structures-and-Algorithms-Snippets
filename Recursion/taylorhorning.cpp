/*C++ Code to calculate Taylor Series expansion of e^x upto n terms using Horner's rule and using Recursion */

#include <bits/stdc++.h>
using namespace std;

float taylor_horner(float x, int n)
{
    static float s=1;
    if (n==0)
    {
        return s;
    }
    s=1+(x/n)*s;
    return taylor_horner(x,n-1);
}

int main()
{
    int x,n;
    cout<<"Enter the integer x: ";
    cin>>x;
    cout<<"Enter the integer n: ";
    cin>>n;
    cout<<"Taylor expansion of e^"<<x<<" upto "<<n<<" terms: "<<taylor_horner(x,n);
}