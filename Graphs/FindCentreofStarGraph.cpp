/*Find Center of Star Graph
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center
node and exactly n - 1 edges that connect the center node with every other node.You are given a 2D integer array edges where 
each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.
Constraints:
3 <= n <= 10^5
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
The given edges represent a valid star graph. */

#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>edges)
{
    int vertices=edges.size()+1;
    vector<int> V[vertices+1];
    for (auto l1: edges)
    {
        V[l1[0]].push_back(l1[1]);
        V[l1[1]].push_back(l1[0]);
    }
    int i;
    for (i=1; i<=vertices; i++)
    {
        if (V[i].size()==vertices-1)
        {
            break;
        }
    }
    return i;
}

int main()
{
    vector<vector<int>> edges={{1,2}, {3,2}, {4,2}};
    cout<<findCenter(edges);
}