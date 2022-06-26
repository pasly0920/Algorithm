#include<iostream>
using namespace std;
unsigned long long int dp[21][21][21];
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T; 
    dp[1][1][1]=1;
    for(int n=2;n<=20;n++)
    {
        for(int l=1;l<=n;l++)
        {
            for(int r=1;r<=(n+1-l);r++)
            {
                dp[n][l][r]=dp[n-1][l-1][r]+dp[n-1][l][r-1]+(n-2)*dp[n-1][l][r];
            }
        }
    }
    int n, l, r;
    for(int i=0;i<T;i++)
    {
        cin>>n>>l>>r;
        cout<<dp[n][l][r]<<'\n';
    }
    return 0;

}