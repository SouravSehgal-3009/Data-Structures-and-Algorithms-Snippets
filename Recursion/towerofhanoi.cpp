/*C++ Code to list down the ways to form Tower of Hanoi with n disks with three towers*/

#include <bits/stdc++.h>
using namespace std;

long long tower_of_hanoi(int n, char tower1, char tower2, char tower3)  
//To transfer n disks from tower1 to tower 3 using tower2
{
    int count=0;
    static int i=1;
    if (n>0)
    {
        count+=tower_of_hanoi(n-1, tower1, tower3, tower2);
        count++;
        cout<<i<<": Move disk"<<n<<" from tower "<<tower1<<" to tower "<<tower3<<endl;
        i++;
        count+=tower_of_hanoi(n-1, tower2, tower1, tower3);
        return count;
    }
    return 0;
}

int main()
{
    int n;
    cout<<"Enter the number of disks";
    cin>>n;
    cout<<"Steps to form Tower of Hanoi with "<<n<<" disks"<<endl;
    cout<<tower_of_hanoi(n, 'A', 'B', 'C');
}