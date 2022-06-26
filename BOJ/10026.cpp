#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
vector<vector<int>> board;
vector<vector<int>> board_real;
void dfs(int now_y, int now_x, int val);
void dfs_real(int now_y, int now_x, int val);
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int N;

int main(){
    cin>>N;

    string temp;
    board.assign(N, vector<int>(N,0));
    board_real.assign(N, vector<int>(N, 0));
    for(int i=0; i<N; i++){
        cin>>temp;
        for(int j=0; j<N; j++){
            if(temp[j] == 'R'){
                board[i][j] = 1;
                board_real[i][j] = 1;
            }
            else if(temp[j] == 'G'){
                board[i][j] = 1;
                board_real[i][j] = 2;
            }
            else{
                board[i][j] = 2;
                board_real[i][j] = 3;
            }
        }
    }

    int real_sec_num = 0;
    int sec_num = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board[i][j] < 0)
                continue;
            else{
                dfs(i, j, board[i][j]);
                sec_num++;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board_real[i][j] < 0)
                continue;
            else{
                dfs_real(i, j, board_real[i][j]);
                real_sec_num++;
            }
        }
    }

    cout<<real_sec_num<<' '<<sec_num;
    return 0;
}

void dfs(int now_y, int now_x, int val){
    board[now_y][now_x] = -1* board[now_y][now_x];

    for(int i=0; i<4; i++){
        int next_y = now_y + dy[i];
        int next_x = now_x + dx[i];

        if(next_y>=0&&next_y<N && next_x>=0&&next_x<N && board[next_y][next_x] == val)
            dfs(next_y, next_x, val);
    }
}

void dfs_real(int now_y, int now_x, int val){
    board_real[now_y][now_x] = -1* board_real[now_y][now_x];

    for(int i=0; i<4; i++){
        int next_y = now_y + dy[i];
        int next_x = now_x + dx[i];

        if(next_y>=0&&next_y<N && next_x>=0&&next_x<N && (board_real[next_y][next_x] == val))
            dfs_real(next_y, next_x, val);
    }
}