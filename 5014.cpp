#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int total, now, target, up, down;
int BFS(vector<long long> &dp);

int main(){
    cin>> total>> now>> target>> up>> down;
    vector<long long> dp(total + 1, 9999999999);
    if(target == now){
        cout<<"0";
        return 0;
    }
    long long res = BFS(dp);
    if(res == 0)
        return 0;

    cout<<"use the stairs";
    return 0;
}

int BFS(vector<long long> &dp){
    queue<int> q;
    q.push(now);
    dp[now] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int next1 = now + up;
        int next2 = now - down;
        if(next1 == target){
            cout<<dp[now] + 1;
            return 0;
        }
        if(next2 == target){
            cout<<dp[now] + 1;
            return 0;
        }
        if(next1>0 && next1<=total && (dp[now] + 1 < dp[next1])){
                q.push(next1);
                dp[next1] = dp[now] + 1; 
        }
        if(next2>0 && next2<=total && (dp[now] + 1 < dp[next2])){
                q.push(next2);
                dp[next2] = dp[now] + 1;
        }
    }

    return dp[target];
}