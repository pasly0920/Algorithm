#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> arr;
    vector<int> dp;
    arr.assign(N, 0);
    dp.assign(N, 0);
    for(int i=0;i<N;i++)
        cin>>arr[i];
    dp[0]=1;
    for(int i=1;i<N;i++)
    {
        int now=arr[i];
        int max=-1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<now)
            {
                if(dp[j]>max)
                    max=dp[j];
            }
        }
        if(max==-1)
            dp[i]=1;
        else
            dp[i]=max+1;
    }
    int max_val=-1;
    for(int i=0;i<N;i++)
        if(dp[i]>max_val)
            max_val=dp[i];
    cout<<max_val;
    return 0;
}