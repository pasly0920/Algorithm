#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> edge;
vector<int> Indegree;
vector<int> result;
void DAG(int N);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    int a, b;
    edge.resize(N+1);
    Indegree.resize(N+1, 0);
    for(int i=0;i<M;i++)
    {   
        cin>>a>>b;
        edge[a].push_back(b);
        Indegree[b]+=1;
    }
    DAG(N);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    return 0;
}
void DAG(int N){
    queue<int> tar;
    for(int i=1;i<=N;i++){
        if(Indegree[i]==0)
            tar.push(i);
    }
    while(tar.size()!=0){
        int now = tar.front();
        tar.pop();
        result.push_back(now);
        for(int i=0;i<edge[now].size();i++){
            int v = edge[now][i];
            Indegree[v]-=1;
            if(Indegree[v]==0)
                tar.push(v);
        }
    }
}