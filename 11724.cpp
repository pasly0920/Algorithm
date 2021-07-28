#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int result=0;
vector<bool> visited;
void connecting(vector<vector<int>> &edge, int start);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    vector<vector<int>> edge(N+1);
    int x, y;
    for(int i=0;i<M;i++)
    {
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x); 
    }
    visited.assign(N+1, false);
    for(int i=1;i<=N;i++)
    {
        if(visited[i]==true)
            continue;
        else
        {
            result++;
            connecting(edge, i);
        }
    }
    cout<<result;
    return 0;
}
void connecting(vector<vector<int>>& edge, int start)
{
    if(visited[start]==true)
        return;
    visited[start]=true;
    for(int i=0;i<edge[start].size();i++)
    {
        int next=edge[start][i];
        connecting(edge, next);
    }
}