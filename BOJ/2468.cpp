#include<iostream>
#include<vector>
using namespace std;
void raining(vector<vector<int>> &board, int rain, int now_x, int now_y, int N);
int dx[4]={0, 1, 0, -1};
int dy[4]={-1, 0, 1, 0};
int temp_result=0;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    int n;
    int min=101;
    int max=-1;
    vector<vector<int>> board(N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>n;
            board[i].push_back(n);
            if(n<min)
                min=n;
            if(n>max)
                max=n;
        }
    }
    int result=1;// final
    if(min==max)
    {
        cout<<1;
        return 0;
    }
    for(int rain=min;rain<max;rain++)
    {
        temp_result=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                if(board[i][j]>rain)
                {
                    temp_result++;
                    raining(board, rain, i, j, N);
                } 
            }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(board[i][j]<0)
                    board[i][j]=(-1)*board[i][j];
            }
        }
        //cout<<rain<<" "<<temp_result<<endl;
        if(temp_result>result)
            result=temp_result;
    }
    cout<<result;
    return 0;
}
void raining(vector<vector<int>> &board, int rain, int now_x, int now_y, int N)
{
    if(board[now_x][now_y]<=rain)
        return;
    board[now_x][now_y]=board[now_x][now_y]*(-1);
    for(int i=0;i<4;i++)
    {
        if(((now_x+dx[i])>=0)&&((now_x+dx[i])<N))
            if(((now_y+dy[i])>=0)&&((now_y+dy[i])<N))
                if(board[now_x+dx[i]][now_y+dy[i]]>rain)
                    raining(board, rain, now_x+dx[i], now_y+dy[i], N);
    }

}