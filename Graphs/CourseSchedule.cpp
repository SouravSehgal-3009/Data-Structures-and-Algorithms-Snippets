/*
Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array 
prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Constraints:
1 <= numCourses <= 10^5
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
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

bool canFinish(vector<vector<int>> prerequisites,int numCourses) 
{
    vector<int> adj[numCourses];
    for (auto x: prerequisites)
    {
        add_edge(adj, x[1], x[0]);
    }
    vector<bool> Visited(numCourses, false);
    vector<bool> Stack(numCourses, false);
    for (int i=0; i<numCourses; i++)
    {
        if (!Visited[i])
        {
            bool x= isCycle(i, adj,Visited, Stack);
            if (x) return false;
        }
    }
    return true;
}

int main()
{
    int numCourses=8;
    vector<vector<int>> prerequisites={{0,1}, {1,2}, {2,5}, {4,7}, {2,7}};
    cout<<canFinish(prerequisites,numCourses);
}