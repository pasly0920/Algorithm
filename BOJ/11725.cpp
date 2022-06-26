#include<iostream>
#include<vector>
using namespace std;
vector<bool>visited;
void finding(vector<vector<int>>& ver, vector<int>&parent, int prev, int now);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<vector<int>> ver(N+1);
    int x, y;
    for(int i=0;i<N-1;i++)
    {
        cin>>x>>y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    vector<int>parent(N+1);
    visited.assign(N+1, false);
    finding(ver, parent, 0, 1);
    for(int i=2;i<=N;i++)
        cout<<parent[i]<<'\n';
    return 0;
}
void finding(vector<vector<int>>& ver, vector<int>&parent, int prev, int now)
{
    if(visited[now]==true)
        return;
    //cout<<prev<<" "<<now<<endl;
    visited[now]=true;
    parent[now]=prev;
    for(int i=0;i<ver[now].size();i++)
        if(visited[ver[now][i]]==false)
        {
            finding(ver, parent, now, ver[now][i]);
        }
}