#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void cat(int now, int target);
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    if(N==K)
    {
        cout<<0;
        return 0;
    }
    cat(N,K);
    return 0;
}
void cat(int now, int target)
{
    vector<bool> visited;
    visited.assign(100001, false);
    queue<int> edge;
    visited[now]=true;
    edge.push(now);
    int time=0;
    while(edge.size()>0)
    {
        time++;
        int size=edge.size();
        //cout<<size<<endl<<endl;
        for(int i=0;i<size;i++)
        {
            int current=edge.front();
            //cout<<current<<endl;
            edge.pop();
            if(current>0)
            {
                if(visited[current-1]==false)
                {   
                    if((current-1)==target)
                    {
                        //cout<<endl;
                        cout<<time;
                        return;
                    }
                    edge.push(current-1);
                    visited[current-1]=true;
                    //cout<<now-1<<" ";
                }
                if(current<=50000)
                {
                    if(visited[current*2]==false)
                    {
                        if((current*2)==target)
                        {
                            //cout<<endl;
                            cout<<time;
                            return;
                        }
                        edge.push(current*2);
                        visited[current*2]=true;
                        //cout<<current*2<<" ";
                    }
                }
            }
            if(current<=99999)
            {
                if(visited[current+1]==false)
                {
                    if((current+1)==target)
                    {
                        //cout<<endl;
                        cout<<time;
                        return;
                    }
                    edge.push(current+1);
                    visited[current+1]=true;
                }
            }
        }
    }
}