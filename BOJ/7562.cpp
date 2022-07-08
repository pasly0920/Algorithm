#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;
vector<vector<int>> board;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int chess(int x1, int x2, int y1, int y2, int l);

int main(){
    int t;
    cin>>t;

    int l, x1, x2, y1, y2;
    for(int i=0; i<t; i++){
        cin>>l;
        cin>>y1>>x1;
        cin>>y2>>x2;
        board.assign(l, vector<int>(l, -1));
        board[y1][x1] = 0;
        if(x1 == x2 && y1 == y2)
            cout<<0<<'\n';
        else
            cout<<chess(x1, x2, y1, y2, l)<<'\n';
    }

    return 0;
}

int chess(int x1, int x2, int y1, int y2, int l){
    queue<pair<int, int>> q;
    q.push(make_pair(y1, x1));

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        int now_dist = board[now.first][now.second];

        if(now.first == y2 && now.second == x2)
            break;
        for(int i=0; i<8; i++){
            int next_y = now.first + dy[i];
            int next_x = now.second + dx[i];
            int next_dist = now_dist + 1;

            if(next_y >=0 && next_y < l && next_x >=0 && next_x < l && (board[next_y][next_x] == -1 || next_dist < board[next_y][next_x])){
                q.push(make_pair(next_y, next_x));
                board[next_y][next_x] = next_dist;
            }
        }
    }

    return board[y2][x2];
}