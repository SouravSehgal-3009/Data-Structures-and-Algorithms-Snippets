/* Bellman Ford Algorithm
Return array of shortest distances from source to all nodes */

#include <bits/stdc++.h>
using namespace std;

vector<int> BellmanFord(int V, int source, vector<vector<int>> edges)
{
    vector<int> dist(V+1, INT_MAX);
    dist[source]=0;
    int i, p, distbw, node1, node2;
    for (i=0; i<V-1; i++)
    {
        p=0;
        for (auto x: edges)
        {
            node1=x[0], node2=x[1], distbw=x[2];
            if (dist[node1]!=INT_MAX && dist[node1]+distbw<dist[node2])
            {
                dist[node2]=dist[node1]+distbw;
                p=1;
            }
        }
        if (p==0) break;
    }

    //for detection of negative weight cycle
    
    for (auto x: edges)
        {
            node1=x[0], node2=x[1], distbw=x[2];
            if (dist[node1]!=INT_MAX && dist[node1]+distbw<dist[node2])
            {
                cout<<"Negative Weight Cycle Detected"<<endl;
                exit(0);
            }
        }
    
    return dist;
}

int main()
{
    vector<vector<int>> edges = {{1,2,3},{2, 3, 4},{3, 1, -10}};
    int n=3, k=1;
    vector<int> v=BellmanFord(n,k,edges);
    for (int x=1; x<v.size(); x++)
    {
        cout<<v[x]<<" ";
    }
}