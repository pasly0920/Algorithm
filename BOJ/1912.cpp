#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<long long> dp;
    dp.assign(n, 0);
    cin>>dp[0];
    int num;
    for(int i=1;i<n;i++)
    {
        cin>>num;
        if(dp[i-1]+num>num)
            dp[i]=dp[i-1]+num;
        else
            dp[i]=num;
    }
    long long max_val=-10000;
    for(int i=0;i<n;i++)
        if(dp[i]>max_val)
            max_val=dp[i];
    cout<<max_val;
    return 0;
}