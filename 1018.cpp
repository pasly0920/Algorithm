#include<iostream>
#include<vector>
#include<string>
using namespace std;
int boardchange_0(vector<vector<int>> &board, int now_y, int now_x);//top_left -1
int boardchange_1(vector<vector<int>> &board, int now_y, int now_x);//top_left 1
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    string s;
    vector<vector<int>> board(N); //B -1 W 1
    for(int i=0;i<N;i++)
    {
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='B')
                board[i].push_back(-1);
            else    
                board[i].push_back(1);
        }
    }
    int min=98654321;
    for(int i=0;i<=N-8;i++)
    {
        for(int j=0;j<=M-8;j++)
        {
            if(min>64-boardchange_0(board, i, j))
                min=64-boardchange_0(board, i, j);
            if(min>64-boardchange_1(board, i, j))
                min=64-boardchange_1(board, i, j);
        }   
    }
    cout<<min;
    return 0;
}
int boardchange_0(vector<vector<int>> &board, int now_y, int now_x)
{
    int origin=-1;
    int cnt=0;
    for(int i=now_y;i<now_y+8;i++)
    {
        for(int j=now_x;j<now_x+8;j++)
        {
            if(board[i][j]!=origin)
                cnt++;
            origin*=-1;  
        }
        origin*=-1;
    }
    return cnt;
}
int boardchange_1(vector<vector<int>> &board, int now_y, int now_x)
{
    int origin=1;
    int cnt=0;
    for(int i=now_y;i<now_y+8;i++)
    {
        for(int j=now_x;j<now_x+8;j++)
        {
            if(board[i][j]!=origin)
                cnt++;
            origin*=-1;  
        }
        origin*=-1;
    }
    return cnt;
}