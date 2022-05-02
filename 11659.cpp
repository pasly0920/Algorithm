#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> cSum;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin>> N >> M;

    cSum.assign(N + 1, 0);
    int temp;
    for(int i=1; i<=N; i++){
        cin>>temp;
        cSum[i] = cSum[i-1] + temp;
    }

    int a, b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        cout<<cSum[b] - cSum[a-1]<<'\n';
    }
    return 0;
}