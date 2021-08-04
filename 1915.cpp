#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int arr[1000][1000];
int dp[1000][1000];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int temp;
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d", &arr[i][j]);
            if((j==0)||(i==0))
                dp[i][j]=arr[i][j];
            if(arr[i][j]==1)
                count++;
        }
    }
    int max_val=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==0)
                dp[i][j]=0;
            else
            {
                dp[i][j]=min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j]=min(dp[i][j], dp[i][j-1]);
                dp[i][j]+=1;
            }
            max_val=max(max_val, dp[i][j]);
        }
    }
    if(max_val==0)
        if(count!=0)
            max_val=1;
    printf("%d", max_val*max_val);
    return 0;
}