#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
vector<vector<int>> homework(1001);
vector<int> dp(1001);
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int max_day=-1;
    int d, w;
    for(int i=0;i<N;i++)
    {
        cin>>d>>w;
        max_day=max(max_day, d);
        homework[d].push_back(w);
    }
    priority_queue<short, vector<short>> possible;
    for(int day=max_day;day>=1;day--)
    {
        for(int i=0;i<homework[day].size();i++)
            possible.push(homework[day][i]);
        if(possible.empty())
            dp[day]=0;
        else
        {
            dp[day]=possible.top();
            possible.pop();
        }
    }
    int summit=0;
    for(int i=1;i<=max_day;i++)
        summit+=dp[i];
    cout<<summit;
    return 0;
}