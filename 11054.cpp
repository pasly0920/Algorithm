#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
vector<short> L(1001);
vector<short> R(1001);
vector<short> arr(1001);
vector<short> dp(1001);
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>arr[i];
    L[1]=1;
    for(int i=2;i<=N;i++)
    {
        int max_val=INT_MIN;
        for(int j=i-1;j>=1;j--)
        {
            if(arr[j]<arr[i])
                max_val=(max_val>L[j])?max_val:L[j];
        }
        if(max_val==INT_MIN)
            L[i]=1;
        else
            L[i]=max_val+1;
    }
    R[N]=1;
    for(int i=N-1;i>=1;i--)
    {
        int max_val=INT_MIN;
        for(int j=i+1;j<=N;j++)
        {
            if(arr[j]<arr[i])
                max_val=(max_val>R[j])?max_val:R[j];
        }
        if(max_val==INT_MIN)
            R[i]=1;
        else
            R[i]=max_val+1;
    }
    int ans=INT_MIN;
    for(int i=1;i<=N;i++)
    {
        if(i==1||i==N)
            dp[i]=max(L[i], R[i]);
        else
            dp[i]=L[i]+R[i]-1;
        if(ans<dp[i])
            ans=dp[i];
    }
    cout<<ans;
    return 0;
}