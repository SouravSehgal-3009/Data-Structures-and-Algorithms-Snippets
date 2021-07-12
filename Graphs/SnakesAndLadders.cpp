/*
Snakes and Ladder Game
You are playing a snakes & ladder game which is a famous ancient Indian game played on board with dice. Given a Snakes & Ladders 
board of size N, which contains multiple Snakes & Ladders. You are also given starting & ending point of each snake & ladder in
a vector<pair<int,int> >. As per the rules -
If you are bitten by snake (by standing at cell having snake head), you will reach the position where tail of the snake ends.
If you reach a cell, which is also starting point of a ladder, then you will climb that ladder.
Give the board configuration, compute the minimum number of dice throws needed to reach the end of the game starting from cell 1. In each turn you can throw any number from 1 to 6 on the dice to move ahead in the board.
*/

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int v1, int v2)
{   
             adj[v1].push_back(v2);
}

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders)
{
    int source=1;
    int board[n+1];
    for (int i=1; i<=n; i++)
    {
        board[i]=i;
    }
    for (auto x: snakes)
    {
        board[x.first]=board[x.second];
    }

    for (auto x: ladders)
    {
        board[x.first]=board[x.second];
    }
    vector<int> adj[n+1];
    for (int i=1; i<=n-1; i++)
    {
        for (int j=1; j<=6; j++)
        {
            int x=i+j;
            if (x<=n)
            {   
                if (board[i]==i)
                     add_edge(adj, board[i], board[x]);
            }
        }
    }

    int Visited[n+1]={0};
    int moves[n+1]={0};
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
                moves[y]=moves[x]+1;
            }
        }
    }
    return moves[n];
}

int main()
{
    int n=36;
    vector<pair<int, int>> snakes={{17,4},  {24,16}, {34,12}, {31,30}};
    vector<pair<int, int>> ladders={{2,15},  {5,7}, {18,29}, {25,35}, {9,27}};
    cout<<"No of minimum throws: "<<min_dice_throws(36, snakes, ladders);
}