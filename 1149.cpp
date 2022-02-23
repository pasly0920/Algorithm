#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<vector<int>> house(N);
    int temp;

    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>temp;
            house[i].push_back(temp);
        }
    }

    vector<vector<int>> dp(N, vector<int>(3, 0));
    for(int i=0; i<3; i++)
        dp[0][i] = house[0][i];

    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            if(j==0)
                dp[i][j] = min(dp[i-1][1] + house[i][j], dp[i-1][2] + house[i][j]);
            else if(j==1)
                dp[i][j] = min(dp[i-1][0] + house[i][j], dp[i-1][2] + house[i][j]);
            else
                dp[i][j] = min(dp[i-1][0] + house[i][j], dp[i-1][1] + house[i][j]);
        }
    }
    
    int min_val = dp[N-1][0];
    min_val = (min_val > dp[N-1][1]) ? dp[N-1][1] : min_val;
    min_val = (min_val > dp[N-1][2]) ? dp[N-1][2] : min_val;

    cout<<min_val;
    return 0;
}