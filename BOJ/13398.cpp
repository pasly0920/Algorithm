#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
#include<algorithm>
using namespace std;
int dp[100001][2];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n+1);
    int small=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]<0)
            small++;
    }
    if(small==n)
    {
        sort(arr.begin()+1, arr.end());
        cout<<arr.back();
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(dp[i-1][0]+arr[i], arr[i]);
        dp[i][1]=max(dp[i-1][0], dp[i-1][1]+arr[i]);
    }
    int max_val=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        max_val=max(max_val, dp[i][0]);
        max_val=max(max_val, dp[i][1]);
    }
    cout<<max_val;
    return 0;
}