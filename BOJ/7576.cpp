#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int dx[4]={0, 1, 0, -1};
int dy[4]={-1, 0, 1, 0};
int well=0;
int toma=0;
int time=0;
int BFS(vector<vector<int>> &tomato, queue<pair<int, int>> &scale, int N, int M);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int M, N;
    cin>>M>>N;
    int n;
    vector<vector<int>> tomato(N);
    queue<pair<int, int>> scale;
    pair<int, int> temp;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>n;
            tomato[i].push_back(n);
            if(n!=-1)
                toma++;
            if(n==1)
            {
                well++;
                temp.first=i;
                temp.second=j;
                scale.push(temp);
            }
        }
    }
    if(toma==well)
    {
        cout<<0;
        return 0;
    }
    if(well==0)
    {
        cout<<-1;
        return 0;
    }
    cout<<BFS(tomato, scale, N, M);
    return 0;
}
int BFS(vector<vector<int>> &tomato, queue<pair<int, int>> &scale, int N, int M)
{
    while(scale.size()>0)
    {
        time++;
        int size=scale.size();
        int delta=0;
        for(int i=0;i<size;i++)
        {
            pair<int, int>curr=scale.front();
            pair<int, int>tempo;
            scale.pop();
            for(int i=0;i<4;i++)
            {
                int ny=curr.first+dy[i];
                int nx=curr.second+dx[i];
                if((ny>=0)&&(ny<N))
                {
                    if((nx>=0)&&(nx<M))
                    {
                        if(tomato[ny][nx]==0)
                        {
                            tempo.first=ny;
                            tempo.second=nx;
                            scale.push(tempo);
                            tomato[ny][nx]=1;
                            well++;
                            if(well==toma)
                                return time;
                            delta++;
                        }
                    }    
                }    
            }
        }
        if(delta==0)
            return -1;
    }
}