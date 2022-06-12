#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

vector<int> ladder;
vector<int> snake;
vector<int> min_dist;

int main(){
    int n, m;
    cin>>n>>m;

    ladder.assign(101, 0);
    snake.assign(101, 0);
    min_dist.assign(101, 987654321);

    int st, ed;
    for(int i=0; i<n; i++){
        cin>>st>>ed;
        ladder[st] = ed;
    }
    for(int i=0; i<m; i++){
        cin>>st>>ed;
        snake[st] = ed;
    }

    queue<pair<int, int> > q;
    q.push(make_pair(1, 0));
    min_dist[1] = 0;
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();

        if(now.first == 100){
            cout<<now.second;
            return 0;
        }

        for(int i=1; i<=6; i++){
            int next = now.first + i;
            if (next > 100)
                continue;
            int next_dist = now.second + 1;
            if(ladder[next] != 0)
                next = ladder[next];
            if(snake[next] != 0)
                next = snake[next];
            if(min_dist[next] > next_dist){
                q.push(make_pair(next, next_dist)); 
                min_dist[next] = next_dist;  
            }
        }
    }

    return 0;
}