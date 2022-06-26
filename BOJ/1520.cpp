#include<iostream>
#include<vector>

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int M, N;
int DFS(vector<vector<int>> &map, vector<vector<int>> &dp, int now_y, int now_x);

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>N>>M;
    vector<vector<int>> map(M);
    vector<vector<int>> dp(N, vector<int> (M, -1));

    int temp;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>temp;
            map[i].push_back(temp);
        }
    }
    
    cout<<DFS(map, dp, 0, 0);

    return 0;
}

int DFS(vector<vector<int>> &map, vector<vector<int>> &dp, int now_y, int now_x){

    if(now_y == N-1 && now_x == M-1)
        return 1;
    
    if(dp[now_y][now_x] != -1)
        return dp[now_y][now_x];
    
    dp[now_y][now_x] = 0;

    for(int i=0; i<4; i++){
        int next_y = now_y + dy[i];
        int next_x = now_x + dx[i];

        if(next_y < N && next_y >=0 && next_x < M && next_x >=0 && map[next_y][next_x] < map[now_y][now_x])
            dp[now_y][now_x] += DFS(map, dp, next_y, next_x);

    }
    return dp[now_y][now_x];
}