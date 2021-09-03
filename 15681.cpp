#include<iostream>
#include<vector>
using namespace std; 
int cnt;
vector<bool> visited;
vector<int> subtree; 
void sub_tree(vector<vector<int>> &edge, int now);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, R, Q;
    cin>>N>>R>>Q;
    vector<vector<int>> edge(N+1);
    int a,b;
    for(int i=0;i<N-1;i++)
    {
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    subtree.assign(N+1, 0);
    visited.assign(N+1, false);
    sub_tree(edge, R);
    int node;
    for(int i=0;i<Q;i++)
    {
        cin>>node;
        cout<<subtree[node]<<'\n';
    }
    return 0;
}
void sub_tree(vector<vector<int>> &edge, int now)
{
    if(visited[now]==true)
        return;
    visited[now]=true;
    for(int i=0;i<edge[now].size();i++)
        if(visited[edge[now][i]]==false)
            sub_tree(edge, edge[now][i]);
    int summit=1;
    for(int i=0;i<edge[now].size();i++)
        summit+=subtree[edge[now][i]];
    subtree[now]=summit;
}