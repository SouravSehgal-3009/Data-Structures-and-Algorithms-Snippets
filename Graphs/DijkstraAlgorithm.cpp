/*
Dijkstra
You are given a weighted undirected graph.
The vertices are enumerated from 1 to n.
Your task is to find the shortest path between the vertex 1 and the vertex n.(It is sure that there is only one possible answer)
Constraints
2≤ n ≤10^5
0≤ xi,yi,weight ≤10^4
All input values are integers.
Input : n = 5, edges = {{1,2,2},{2, 5, 5},{2, 3, 4},{1, 4, 1},{4, 3, 3},{3, 5, 1}}
Output : { 1, 4, 3, 5 }
*/

#include <bits/stdc++.h>
using namespace std;

void findpath(vector<int> parent,vector<int> &result, int n)
{
    if (n==-1)
        return;
    findpath(parent,result, parent[n]);
    result.push_back(n);
}

vector<int> shortestPath(vector<vector<int>> roads,int n)
{
    vector<pair<int,int>> adj[n+1];
    for (auto x: roads)
    {
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }

    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    set<pair<int,int>> s1;
    vector<int> path;
    dist[1]=0;
    s1.insert({0,1});
    int node, diststill, nbr, distbw;
    while (!s1.empty())
    {
        auto it=s1.begin();
        diststill=it->first, node=it->second;
        s1.erase(it);
        for (auto x: adj[node])
        {
            nbr=x.first, distbw=x.second;
            if (diststill+distbw<dist[nbr])
            {
                auto f=s1.find({dist[nbr], nbr});
                if (f!=s1.end()) s1.erase({dist[nbr], nbr});
                dist[nbr]=diststill+distbw;
                s1.insert({dist[nbr], nbr});
                parent[nbr]=node;

            }
        }
    }
    findpath(parent, path, n);
    return path;
}

int main()
{
    int n=5;
    vector<vector<int>> edges = {{1,2,2},{2, 5, 5},{2, 3, 4},{1, 4, 1},{4, 3, 3},{3, 5, 1}};
    vector<int> path=shortestPath(edges,n);
    for (auto x: path)
    {
        cout<<x<<" ";
    }
}