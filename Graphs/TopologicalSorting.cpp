/*Topological Sorting using BFS */

#include <bits/stdc++.h>
using namespace std;

void TopologicalSorting(vector<vector<int>> adj)
{
    int nodes=adj.size(), y;
    vector<int> indegree(nodes,0);
    for (int i=0; i<nodes; i++)
    {
        for (auto x: adj[i])
        {
            indegree[x]++;
        }
    }
    queue<int> q1;
    for (int i=0; i<nodes; i++)
    {
        if (indegree[i]==0) q1.push(i);
    }
    cout<<"Topological Sorting: ";
    while (!q1.empty())
    {
        y=q1.front();
        cout<<y<<" ";
        for (auto x: adj[y])
        {
            indegree[x]--;
            if (indegree[x]==0) q1.push(x);
        }
        q1.pop();
    }
}

int main()
{
    vector<vector<int>> v1={{2},{2,4},{3,5},{5},{5},{}};
    TopologicalSorting(v1);
}