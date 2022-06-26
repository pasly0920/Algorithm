#include<iostream>
#include<vector>
using namespace std;
vector<int> tempo;//cycle element store
void inteam(vector<int>&ver, int now, vector<bool>& visited, vector<bool>&isinstack);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T;
    int N;
    for(int i=0;i<T;i++)
    {
        cin>>N;
        vector<int> ver(N+1);
        vector<bool> isinstack;
        isinstack.assign(N+1, false);
        int n;
        vector<bool> visited;
        visited.assign(N+1, false);
        for(int i=1;i<=N;i++)
        {
            cin>>n;
            ver[i]=n;
        }
        for(int i=1;i<=N;i++)
        {
            if(ver[i]!=-1)
            {
                //cout<<i<<endl;
                if(ver[i]==i)
                {
                    ver[i]=-1;
                    continue;
                }
                inteam(ver, i, visited, isinstack);
                isinstack.assign(N+1, false);
            }
            else
                continue;
        }
        int result=0;
        for(int i=1;i<=N;i++)
            if(ver[i]!=-1)
                result++;
        cout<<result<<'\n';
        ver.clear();
        isinstack.clear();
        tempo.clear();
    }
    return 0;
}
void inteam(vector<int>&ver, int now, vector<bool>& visited, vector<bool>&isinstack)
{
    if(ver[now]==-1)
        return;
    if(isinstack[now]==true)
    {
        while(1)
        {
            //cout<<tempo.back()<<"  ";
            if(tempo.back()==now)
            {
                ver[now]=-1;
                tempo.pop_back();
                break;
            }
            ver[tempo.back()]=-1;
            tempo.pop_back();
        }
        return;
    }
    if(visited[now]==true)
        return;
    visited[now]=true;
    isinstack[now]=true;
    tempo.push_back(now);
    inteam(ver, ver[now], visited, isinstack);
}