#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> visited;
vector<vector<int>> edge;
int cardinality = 1;
int N, M, R;
void dfs(int now);

int main(){
    cin>>N>>M>>R;
    edge.assign(N+1, vector<int>(0, 0));
    visited.assign(N+1, 987654321);
    
    int st, ed;
    for(int i=0; i<M; i++){
        cin>>st>>ed;
        edge[st].push_back(ed);
        edge[ed].push_back(st);
    }

    for(int i=1;i<=N; i++)
        if(edge[i].size() > 0)
            sort(edge[i].begin(), edge[i].end());

    dfs(R);

    for(int i=1; i<=N; i++)
        if(visited[i] != 987654321)
            cout<<visited[i]<<'\n';
        else
            cout<<"0"<<'\n';

    return 0;
}

void dfs(int now){
    visited[now] = cardinality;
    cardinality ++;
    for(int i=0;i<edge[now].size(); i++){
        int next = edge[now][i];
        if(visited[next] > cardinality)
            dfs(next);
    }
}