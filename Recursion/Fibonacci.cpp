/*C++ Code to calculate Fibonacci number at nth position using Recursion */

#include <bits/stdc++.h>
using namespace std;

int fibn[1000000]={0};

int fib(int n)
{
    if (n==0)
    {
        fibn[n]=0;
        return 0;
    }
    else if (n==1)
    {
        fibn[n]=1;
        return 1;
    }
    if (fibn[n-1]!=0 && fibn[n-2]!=0)
    {
        fibn[n]=fibn[n-2]+fibn[n-1];
    }
    else
    {
        fibn[n]= fib(n-2)+fib(n-1);
    }
    return fibn[n];
}

int main()
{
    int n;
    cout<<"Enter the integer n: ";
    cin>>n;
    cout<<"Fib["<<n<<"] is :"<<fib(n);
}
