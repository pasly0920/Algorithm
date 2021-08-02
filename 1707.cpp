#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<short> ver(20001);//color 저장
int V, E;
bool graph(vector<vector<short>> &edge, short start);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>V>>E;
        vector<vector<short>> edge(V+1);
        short x, y;
        for(int i=0;i<E;i++)
        {
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        ver.assign(V+1, 0);//기본값은 0
        for(short i=1;i<=V;i++)
        {
            bool ans= graph(edge, i);
            if(ans==false)
            {
                cout<<"NO"<<'\n';
                break;
            }
            if((i==V)&&(ans==true))
                cout<<"YES"<<'\n';
        }
    }
    return 0;
}
bool graph(vector<vector<short>> &edge, short start)
{
    int color=-1;
    if((ver[start]==-1)||(ver[start]==1))
        return true;
    if(edge[start].size()==0)
        return true;
    queue<short> dot;//BFS queue
    dot.push(start); 
    ver[start]=color;
    while(dot.size()>0)
    {
        color*=-1;
        short size=dot.size();
        for(int i=0;i<size;i++)
        {
            short now = dot.front();
            dot.pop();
            for(int i=0;i<edge[now].size();i++)
            {
                int next=edge[now][i];
                if(ver[next]==0)
                {
                    ver[next]=color;
                    dot.push(next);
                }
                else if(ver[next]==(color*(-1)))
                    return false;
            }
        }
    }
    return true;
}