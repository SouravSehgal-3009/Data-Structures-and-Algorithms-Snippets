//C++ Code to impplement BFS and DFS graph

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    private:
        int vertices;
        vector<int> *adj;
        int directed=0;
    public:
        Graph(int V)
        {
            vertices=V;
            adj=new vector<int>[vertices];
        }

        void add_edge(int v1, int v2)
        {   
             adj[v1].push_back(v2);
        }

        void makeGraph(int edges)
        {
            int d;
            cout<<"For undirected graph, enter 0 else enter 1: ";
            cin>>d;
            directed=d;
            for (int i=1; i<=edges; i++)
            {
                cout<<"For Edge "<<i<<endl;
                int v1, v2;
                cout<<"Enter Vertex 1: ";
                cin>>v1;
                cout<<"Enter Vertex 2: ";
                cin>>v2;
                this->add_edge(v1,v2);
                if (directed==0) this->add_edge(v2,v1);
            }
        }

        void BFS(int v)
        {
            int Visited[vertices]={0};
            queue<int> q1;
            Visited[v]=1;
            q1.push(v);
            cout<<"BFS: ";
            while (!q1.empty())
            {
                int x=q1.front();
                q1.pop();
                cout<<x<<" ";
                for (auto y: adj[x])
                {
                    if (!Visited[y])
                    {
                        Visited[y]=1;
                        q1.push(y);
                    }
                }
            }
            cout<<endl;
        }

        void ShortestPath(int source, int dest)
        {
            int Visited[vertices]={0};
            int parent[vertices]={-1};
            int dist[vertices]={0};
            queue<int> q1;
            q1.push(source);
            Visited[source]=1;
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
                        parent[y]=x;
                        dist[y]=dist[x]+1;
                    }
                }
            }

            cout<<"Shortest distance from source "<<source<<" to destination "<<dest<<" :"<<dist[dest]<<endl;


            if (dest!=-1)
            {
                cout<<"Shortest path: ";
                int temp=dest;
                while (temp!=source)
                {
                    cout<<temp<<"-";
                    temp=parent[temp];
                }
                cout<<source;
            }
            cout<<endl;
        }

        void DFSHelper(int A[], int v)
        {
            A[v]=1;
            cout<<v<<" ";
            for (auto x: adj[v])
            {
                if (!A[x])
                {
                        DFSHelper(A, x);
                }
            }
        }

        void DFS(int s)
        {
            int Visited[vertices]={0};
            cout<<"DFS: ";
            DFSHelper(Visited, s);

        }
    
};

int main()
{
    int vertices, edges;
    cout<<"Enter number of vertices: ";  
    cin>>vertices;
    cout<<"Enter number of edges: ";   //Vertices will be named 0 to vertices-1
    cin>>edges;
    Graph G1(vertices);
    G1.makeGraph(edges);
    G1.BFS(1);
    G1.ShortestPath(1,3);
    G1.DFS(1);
}
