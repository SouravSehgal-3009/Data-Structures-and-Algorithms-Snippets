/*Minimum Degree of a Connected Trio in a Graph
You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges,
 where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.A connected trio is a set of
three nodes where there is an edge between every pair of them. The degree of a connected trio is the number of edges where 
one endpoint is in the trio, and the other is not. Return the minimum degree of a connected trio in the graph, or -1 if the 
graph has no connected trios.
Constraints:
2 <= n <= 400
edges[i].length == 2
1 <= edges.length <= n * (n-1) / 2
1 <= ui, vi <= n
ui != vi
There are no repeated edges. */

#include<bits/stdc++.h>
using namespace std;

int minTrioDegree(int n, vector<vector<int>> edges) 
{
    int nodes[n+1][n+1];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            nodes[i][j]=0;
        }
    }

    for (auto x: edges)
    {
        nodes[x[0]][x[1]]=1;
        nodes[x[1]][x[0]]=1;
    }

    int total[n+1]={0};
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            total[i]+=nodes[i][j];
            
        }
    }
    int minimum=INT_MAX;
    int f=0;

    vector<int> v1;
    for (int i=1; i<=n-2; i++)
    {
        for (int j=i+1; j<=n-1; j++)
        {
            for (int k=j+1; k<=n; k++)
            {
                if (nodes[i][j]==1 && nodes[i][k]==1 && nodes[j][k]==1)
                {
                    f=1;
                    int temp=total[i]+total[j]+total[k]-6;
                    if (temp<minimum)
                    {
                        minimum=temp;
                    }

                }
            }
        }
    }


    if (f==0) return -1;
    return minimum;
}

int main()
{
    vector<vector<int>> edges={{1,2}, {2,3}, {3,1}, {1,4}};
    cout<<minTrioDegree(4, edges);
}


