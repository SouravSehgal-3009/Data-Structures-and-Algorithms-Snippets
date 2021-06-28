/*C++ Code to calculate Factorial of a number using Recursion */

#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n==0)
        return 1;
    return factorial(n-1)*n;
}

int main()
{
    int n;
    cout<<"Enter the integer n: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is: "<<factorial(n);
}