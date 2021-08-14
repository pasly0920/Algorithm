#include<iostream>
#include<vector>
using namespace std;
vector<int> visited;
bool backedge;
void count(int n, int now, vector<vector<int>> &edge);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, m;
    int ca=1;
    while(1)
    {
        cin>>n>>m;
        if((n==0)&&(m==0))
            break;
        vector<vector<int>> edge(n+1);
        visited.assign(n+1, 0);
        int x, y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        int T=0;
        for(int i=1;i<=n;i++)
        {
            backedge=false;
            if(visited[i]!=0)
                continue;
            else
                count(0, i, edge);
            if(backedge==false)
                T++;
        }
        cout<<"Case"<<" "<<ca<<":"<<" ";
        if(T==0)
            cout<<"No trees."<<'\n';
        else if(T==1)
            cout<<"There is one tree."<<'\n';
        else 
            cout<<"A forest of "<<T<<" trees."<<'\n';
        ca++;
    }
    return 0;
}
void count(int cnt, int now, vector<vector<int>> &edge)
{   
    visited[now]=cnt;
    for(int i=0;i<edge[now].size();i++)
       if(visited[edge[now][i]]==false)
            count(cnt+1, edge[now][i], edge);
        else if(visited[now]-visited[edge[now][i]]>1)
            backedge=true;
}