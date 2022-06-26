#include<iostream>
#include<vector>
using namespace std;
int cnt=0;
vector<bool> visited;
void DFS(int now, vector<vector<int>> &edge);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<vector<int>> edge(N);
    vector<int> parent_node(N);
    int parent;
    int root;
    for(int i=0;i<N;i++)
    {
        cin>>parent;
        if(parent==-1)
            root=i;
        else
        {
            edge[parent].push_back(i);
            parent_node[i]=parent;
        }
    }//edge로 tree 구성 완료
    int erase_ver;
    cin>>erase_ver;
    for(int i=0;i<edge[parent_node[erase_ver]].size();i++)
    {
        if(edge[parent_node[erase_ver]][i]==erase_ver)
            edge[parent_node[erase_ver]][i]= -1;
    }//노드 지우기
    visited.assign(N, false);
    if(root==erase_ver)
    {
        cout<<0;
        return 0;
    }
    else
        DFS(root, edge);
    cout<<cnt;
    return 0;
}   
void DFS(int now, vector<vector<int>> &edge)
{
    if((edge[now].size()==0)||((edge[now].size()==1)&&(edge[now][0]==-1)))
        cnt++;
    visited[now]=true;
    for(int i=0;i<edge[now].size();i++)
        if(edge[now][i]==-1)
            continue;
        else if(!visited[edge[now][i]])
            DFS(edge[now][i], edge);
}