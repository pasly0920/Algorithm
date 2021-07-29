#include<iostream>
#include<vector>
using namespace std;
vector<bool> visited;
vector<int> result;
void tracking(vector<vector<int>> &ver, int now, int tar_2, int res);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, tar_1, tar_2, m;
    int x, y;
    cin>>N>>tar_1>>tar_2>>m;
    vector<vector<int>> ver(N+1);
    visited.assign(N+1, false);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    tracking(ver, tar_1, tar_2, 0);
    if(result.size()==0)
        cout<<-1;
    else
        cout<<result.back();
    return 0;
}
void tracking(vector<vector<int>> &ver, int now, int tar_2, int res)
{
    if(visited[now]==true)
        return;
    visited[now]=true;
    if(now==tar_2)
        result.push_back(res);
    for(int i=0;i<ver[now].size();i++)
    {
        if(visited[ver[now][i]]==false)
            tracking(ver, ver[now][i], tar_2, res+1);
    }
}