/*
Cycle Detection in Undirected Graph
Given a undirected graph having n nodes, and an array of edges where edges[i] = [ui, vi] is a bidirectional edge between node 
ui and node vi.
Find whether the graph contains a cycle or not, return true if the cycle is present else return false.
Constraints:
3<= n <= 10^5
2<= edges.length <= 10^5
1<= ui, vi <= n
Nodes are numbered 1 to n
Graph may or may not be connected
*/

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int v1, int v2)
{   
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
             
}

bool isCycle(int v,vector<int> adj[], vector<bool> &Visited, int parent)
{
    Visited[v]=true;
    for (auto x: adj[v])
    {
        if (!Visited[x])
        {
            bool cyclefound=isCycle(x, adj, Visited, v);
            if (cyclefound)
                return true;
        }
        else if (x!=parent)
                return true;
       
    }
    return false;
}

bool solve(int n, vector<vector<int> > edges) 
{
    vector<int> adj[n+1];
    for (auto x: edges)
    {
        add_edge(adj, x[0], x[1]);
    }

    vector<bool> Visited(n+1, false);
    int parent=-1;
    
    for (int i=1; i<=n; i++)
    {
        if (!Visited[i])
        {
            bool x= isCycle(i, adj,Visited, parent);
            if (x) return x;
        }
    }
    return false;
}

int main()
{
    int n=5;
    vector<vector<int>> edges={{1,2}, {3,4}, {4,5}, {3,5}};
    cout<<solve(n,edges);
}