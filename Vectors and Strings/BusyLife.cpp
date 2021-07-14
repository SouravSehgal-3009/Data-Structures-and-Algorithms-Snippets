/*
Busy Life
Given the start and finish times of activities, print the maximum number of activities. Input is already store 
in a vector of pairs. Each pair contains the start and end of the activity.
*/

#include <bits/stdc++.h>
using namespace std;

bool SortActivity(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second<p2.second;
}

int countActivites(vector<pair<int,int>> activities)
{
    sort(activities.begin(), activities.end(), SortActivity);
    int sol=1;
    pair<int, int> p1=activities[0];
    for (int i=1; i<activities.size(); i++)
    {
        if (activities[i].first>=p1.second)
        {
            p1=activities[i];
            sol++;
        }
    }
    return sol;
}

int main()
{
    vector<pair<int,int>> vec1={{7,9},{0,7},{4,5}, {8,9}, {4,10}, {5,7}};
    cout<<countActivites(vec1);
}
