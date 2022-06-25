#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int N, M;
int min_val = 987654321;
int min_ver = -1;
vector<vector<int>> fr;
vector<vector<int>> min_dist;

int main(){
    cin>>N>>M;
    fr.assign(N+1, vector<int>(N, 0));
    min_dist.assign(N+1, vector<int>(N+1, 987654321));

    int a, b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        fr[a].push_back(b);
        fr[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        min_dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int now = q.front();
            q.pop();

            for(int j=0; j<fr[now].size(); j++){
                int next = fr[now][j];
                int next_dist = min_dist[i][now] + 1;
                if(next_dist < min_dist[i][next]){
                    min_dist[i][next] = min_dist[i][now] + 1;
                    q.push(next);
                }
            }
        }

        int temp_sum = 0;
        for(int j=1; j<=N; j++)
            temp_sum += min_dist[i][j];

        if(temp_sum < min_val){
            min_val = temp_sum;
            min_ver = i;
        }
    }

    cout<<min_ver;
    return 0;
}