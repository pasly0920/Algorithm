#include<iostream>
using namespace std;
int board[50][50];
void island(int now_y, int now_x, int w, int h);
int dy[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8]={0, 1, 1, 1, 0, -1, -1, -1};
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1)
    {
        int w, h;
        cin>>w>>h;
        if((w==0)&&(h==0))
            break;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
                cin>>board[i][j];
        }
        int result=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(board[i][j]==0)
                {
                    //cout<<i<<" "<<j<<endl;
                    continue;
                }
                else
                {
                    //cout<<i<<"  "<<j<<endl;
                    result++;
                    island(i, j, w, h);
                    //cout<<endl<<endl;  
                }
            }
        }
        //cout<<1<<'\n';
        cout<<result<<'\n';
    }
    return 0;
}
void island(int now_y, int now_x, int w, int h)
{
    //cout<<now_x<<" "<<now_y<<endl;
    //cout<<w<<" "<<h<<endl;
    /*for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            cout<<board[i][j];
        cout<<endl;
    }*/
    if(board[now_y][now_x]==0)
        return;
    board[now_y][now_x]=0;
    for(int k=0;k<8;k++)
    {
        if((now_y+dy[k])<=h-1)
            if((now_x+dx[k])<=w-1) 
                if((now_x+dx[k])>=0)
                    if((now_y+dy[k])>=0)
                        if(board[now_y+dy[k]][now_x+dx[k]]==1)
                            island(now_y+dy[k], now_x+dx[k], w, h);
    }
}