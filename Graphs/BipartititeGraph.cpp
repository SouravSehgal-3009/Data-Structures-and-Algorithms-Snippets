/*    
Is Graph Bipartite?
Given an undirected graph with n nodes, where each nodes is numbered 0 to  n-1.
You are given a 2D array, where for each v in graph[u] there is an undirected edge between node u and v.
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
Return whether Graph is Bipartite or not.
*/

#include<bits/stdc++.h>
using namespace std;


void make_edge(vector<int> adj[], int v1, int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

bool DFS(vector<vector<int>> adj,vector<int> &Visited, int node, int parent, int color)
{
    Visited[node]=color;
    for (auto x: adj[node])
    {
        if (Visited[x]==0)
        {
            bool prob=DFS(adj, Visited, x, node, 3-color);
            if (!prob)
                return false;
        }
        else if (Visited[x]!=0 && x!=parent)
        {
            if (Visited[x]==color)
                return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> graph)
{
    
    int nodes=graph.size();
    vector<int> Visited(nodes,0);
    int parent=-1, color=1, prob;
    for (int x=0; x<nodes; x++)
    {
        if (Visited[x]==0)
        {
            prob=DFS(graph, Visited, x, parent, color);
            if (!prob)
            {
                return false;
            }
        }
    }
    return prob;
}

int main()
{
    vector<vector<int>> v1={{1,5},{0,2},{1,3},{2,4}, {3,5}, {0,4}};
    cout<<isBipartite(v1);
}