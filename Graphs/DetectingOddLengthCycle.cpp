/*
Detecting an Odd Length Cycle
Given an undirected graph as an adjacency list, return whether the graph has an odd length cycle.
Constraints:
n, m ≤ 250 where n and m are the number of rows and columns in graph
*/

#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<int>> adj,vector<int> &Visited, int node, int parent, int color)
{
    Visited[node]=color;
    for (auto x: adj[node])
    {
        if (Visited[x]==0)
        {
            bool prob=DFS(adj, Visited, x, node, 3-color);
            if (prob)
                return true;
        }
        else if (Visited[x]!=0 && x!=parent)
        {
            if (Visited[x]==color)
                return true;
        }
    }
    return false;
}

bool solve(vector<vector<int>> graph)
{
    int nodes=graph.size();
    vector<int> Visited(nodes, 0);
    int parent=-1, color=1, prob;
    for (int x=0; x<nodes; x++)
    {
        if (Visited[x]==0)
        {
            prob=DFS(graph, Visited, x, parent, color);
            if (prob)
            {
                return true;
            }
        }
    }
    return prob;
}

int main()
{
        vector<vector<int>> v1={{1,2,3},{0,2},{0, 1,3},{0,2}};
        cout<<solve(v1);

}
