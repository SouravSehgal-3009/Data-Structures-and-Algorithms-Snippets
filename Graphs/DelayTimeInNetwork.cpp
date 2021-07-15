/*
Delay Time in Network
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as 
directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes 
for a signal to travel from source to target.
We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If 
it is impossible for all the n nodes to receive the signal, return -1.
Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
Input : n = 4, k = 2 , times = {{2,1,1},{2,3,1},{3,4,1}}
Output : 2
*/

#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> times, int n, int k) 
{
    vector<pair<int,int>> adj[n+1];
    for (auto x: times)
    {
        adj[x[0]].push_back({x[1], x[2]});
    }

    vector<int> dist(n+1, INT_MAX);
    set<pair<int,int>> s1;
    dist[k]=0;
    s1.insert({0,k});
    int node, nbr, diststill, distbw;
    while (!s1.empty())
    {
        auto it=s1.begin();
        diststill=it->first,node=it->second;
        s1.erase(it);
        for (auto y: adj[node])
        {
            nbr=y.first, distbw=y.second;
            if (diststill+distbw<dist[nbr])
            {
                auto f=s1.find({dist[nbr], nbr});
                if (f!=s1.end()) s1.erase({dist[nbr], nbr});
                dist[nbr]=diststill+distbw;
                s1.insert({dist[nbr], nbr});
            }
        }
    }
    int time=0;
        for (int i=1; i<=n; i++)
        {
            if (dist[i]==INT_MAX)
                return -1;
            if (dist[i]>time)
                time=dist[i];
        }
        return time;
}

int main()
{
    int n=4, k=2;
    vector<vector<int>> times={{2,1,1},{2,3,1},{3,4,1}};
    cout<<networkDelayTime(times, n,k);
}