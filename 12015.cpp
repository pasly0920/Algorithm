#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr(1000001);
vector<int> dp;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>arr[i];
    dp.push_back(arr[1]);
    for(int i=2;i<=N;i++)
    {
        if(arr[i]>dp.back())
            dp.push_back(arr[i]);
        else
        {
            int idx=lower_bound(dp.begin(), dp.end(), arr[i])-dp.begin();
            if(dp[idx]==arr[i])
                continue;
            else
                if(dp[idx-1]>arr[i])
                    dp[idx-1]=arr[i];
                else if(dp[idx]>arr[i])
                    dp[idx]=arr[i];
        }
    }
    cout<<dp.size();
    return 0;
}