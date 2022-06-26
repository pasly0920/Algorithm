#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> cSum;
int max_val = -1987654321;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin>>N>>K;


    cSum.assign(N+1, 0);
    int temp;
    for(int i=1; i<=N; i++){
        cin>>temp;
        cSum[i] = cSum[i-1] + temp;
    }

    for(int i=K; i<=N; i++){
        temp = cSum[i] - cSum[i - K];
        max_val = max(max_val, temp);
    }
    
    cout<<max_val;
    return 0;
}