/*
Directed Graph Cycle Detection
Given a directed graph having n nodes, and an array of edges where edges[i] = [ui, vi] is an edge directed from node ui to 
node vi .
Find whether the graph contains a cycle or not, return true if the cycle is present else return false.
Constraints:
1<= n <= 10^5
1<= edges.length <= 10^5
1<= ui, vi <= n
Nodes are numbered 1 to n
Graph may or may not be connected
Input :, edges = {{1,  2}, {1, 3}, {2, 3}, {1,  4}, {4, 5}}
*/

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int v1, int v2)
{   
    adj[v1].push_back(v2);             
}

bool isCycle(int v,vector<int> adj[], vector<bool> &Visited,vector<bool> Stack)
{
    Visited[v]=1;
    Stack[v]=1;
    for(auto x: adj[v])
    {
        if (Stack[x]==1)
            return true;
        else if (!Visited[x])
        {
            int cyclefound=isCycle(x, adj, Visited, Stack);
            if (cyclefound) return true;
        }
    }
    Stack[v]=0;
    return false;
}

bool solve(int n, vector<vector<int>>edges) 
{
    vector<int> adj[n+1];
    for (auto x: edges)
    {
        add_edge(adj, x[0], x[1]);
    }

    vector<bool> Visited(n+1, false);
    vector<bool> Stack(n+1, false);
    for (int i=1; i<=n; i++)
    {
        if (!Visited[i])
        {
            bool x= isCycle(i, adj,Visited, Stack);
            if (x) return x;
        }
    }
    return false;
}

int main()
{
    int n=5;
    vector<vector<int>> edges = {{1,  2}, {1, 3}, {2, 3}, {1,  4}, {4, 5}};
    cout<<solve(n,edges);

}