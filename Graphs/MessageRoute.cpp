/*
Message Route There is a network of n computers, each computer is numbered 1 to n.
The computer network is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge that connects computer 
ui and computer vi . Your task is to find if Alice can send a message to Bob, if it is possible, return minimum number of 
computers on such a route and if it is not possible than return -1.
Alice's Computer is 1 and Bob's computer is  n.
Constraints:
2≤ n ≤10^5
1<= edges.length <= 2*10^5
1<= ui, vi <=n
*/

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int v1, int v2)
{   
             adj[v1].push_back(v2);
             adj[v2].push_back(v1);
             
}

int messageRoute(int n, vector<vector<int>>edges)
{
    int source=1;
    vector<int> adj[n+1];
    for (auto x: edges)
    {
        add_edge(adj, x[0], x[1]);
    }

    int Visited[n+1]={0};
    int dist[n+1]={-1};
    queue<int> q1;
    q1.push(source);
    Visited[source]=1;
    dist[source]=0;
    while (!q1.empty())
    {
        int x=q1.front();
        q1.pop();
        for (auto y: adj[x])
        {
            if (!Visited[y])
            {
                q1.push(y);
                Visited[y]=1;
                dist[y]=dist[x]+1;
            }
        }
    }
    return dist[n]+1;
}

int main()
{
    int n=5;
    vector<vector<int>> comp={{1,2}, {3,4}, {2,5}};
    cout<<"Min no. of Computers: "<<messageRoute(n,comp);

}