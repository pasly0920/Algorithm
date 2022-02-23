#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> tripod(n+1);
    vector<vector<int>> dp(n + 1);
    int temp;

    for(int i=1; i<=n; i++){
        tripod[i].push_back(-1);
        for(int j= 1; j<=i; j++){
            cin>>temp;
            tripod[i].push_back(temp);
        }
        tripod[i].push_back(-1);
    }

    dp[1].push_back(-1);
    dp[1].push_back(tripod[1][1]);
    dp[1].push_back(-1);

    for(int i=2; i<=n; i++){
        dp[i].push_back(-1);
        for(int j=1; j<=i; j++)
            dp[i].push_back(max(dp[i-1][j] + tripod[i][j], dp[i-1][j-1] + tripod[i][j]));
        dp[i].push_back(-1);
    }

    int max = -1;
    for(int i=1; i<=n; i++)
        max = (max > dp[n][i]) ? max : dp[n][i];

    cout<<max;
    return 0;
}