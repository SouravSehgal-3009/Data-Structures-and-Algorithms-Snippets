/* Maximal Network Rank
There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates 
that there is a bidirectional road between cities ai and bi. The network rank of two different cities is defined as the total 
number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
Constraints:
2 <= n <= 100
0 <= roads.length <= n * (n - 1) / 2
roads[i].length == 2
0 <= ai, bi <= n-1
ai != bi
Each pair of cities has at most one road connecting them.  */

#include<bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> roads) 
{
    int cities[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cities[i][j]=0;
        }
    }

    for (auto x: roads)
    {
        cities[x[0]][x[1]]=1;
        cities[x[1]][x[0]]=1;
    }

    int total[n]={0};
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            total[i]+=cities[i][j];
            
        }
    }

    int max=0;
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            int temp=0;
            temp=total[i]+total[j];
            if (cities[i][j]==1) temp--;
            if (temp>max) max=temp;
        }
    }
    return max;
}

int main()
{
    vector<vector<int>> roads={{0,1}, {0,3}, {1,2}, {1,3}};
    cout<<maximalNetworkRank(4, roads);
}