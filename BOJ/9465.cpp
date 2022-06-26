#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int dp[100001][3];
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int k=0;k<T;k++)
    {
        int n;
        cin>>n;
        int value[3][100001];
        for(int i=0;i<2;i++)
            for(int j=0;j<n;j++)
                cin>>value[i][j];
        for(int i=0;i<n+2;i++)
            for(int j=0;j<3;j++)
                dp[i][j]=0;
        for(int i=0;i<n;i++)
        {
            dp[i+1][0] = max(dp[i+1][0], max(dp[i][0], max(dp[i][1], dp[i][2])));
            dp[i+1][1] = max(dp[i+1][1], max(dp[i][0], dp[i][2]) + value[0][i]);
            dp[i+1][2] = max(dp[i+1][2], max(dp[i][0], dp[i][1]) + value[1][i]);
        }
        cout<<max(dp[n][0], max(dp[n][1], dp[n][2]))<<'\n';
    }
    return 0;
}