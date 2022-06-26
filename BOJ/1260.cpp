#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<bool> visited;
void DFS(int N, vector<vector<int>> &edge, int current);
void BFS(int N, vector<vector<int>> &edge, int current);

int main(){
    int N, M, V;
    cin>>N>>M>>V;

    vector<vector<int>> edge(N + 1);
    int a, b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1; i<= N; i++)
        sort(edge[i].begin(), edge[i].end());

    visited.assign(N+1, false);
    DFS(N, edge, V);
    cout<<endl;
    visited.assign(N+1, false);
    BFS(N, edge, V);
    
    return 0;
}

void DFS(int N, vector<vector<int>> &edge, int current){
    if(visited[current])
        return;
    visited[current] = true;
    cout<< current << " ";
    for(int i=0; i<edge[current].size(); i++){
        int next = edge[current][i];
        DFS(N, edge, next);
    }
}

void BFS(int N, vector<vector<int>> &edge, int current){
    queue<int> q;
    q.push(current);
    visited[current] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout<< current << " ";
        for(int i=0;i < edge[current].size(); i++){
            int next = edge[current][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}