#include<iostream>
#include<vector>
using namespace std;
int num_arr[16][16];
vector<vector<long long>> dp(16, vector<long long>(16, 0));
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, M, special;
    cin>>N>>M>>special;
    for(int i=1;i<=N;i++)
        dp[i][1]=1;
    for(int i=1;i<=M;i++)
        dp[1][i]=1;
    if(special==0)
    {
        for(int i=2;i<=N;i++)
            for(int j=2;j<=M;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
    if(special!=0)
    {
        num_arr[1][1]=1;
        int prev;
        int tar_x, tar_y;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(i==1&&j==1)
                    prev=1;
                else
                {
                    num_arr[i][j]=prev+1;
                    prev++;
                }
                if(num_arr[i][j]==special)
                {
                    tar_x=j;
                    tar_y=i;
                }
            }
        }
        for(int i=2;i<=tar_y;i++)
            for(int j=2;j<=tar_x;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        long long tar_val=dp[tar_y][tar_x];
        for(int i=tar_y;i<=N;i++)
            dp[i][tar_x]=tar_val;
        for(int i=tar_x;i<=M;i++)
            dp[tar_y][i]=tar_val;
        for(int i=tar_y+1;i<=N;i++)
            for(int j=tar_x+1;j<=M;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
    cout<<dp[N][M];
    return 0;
}