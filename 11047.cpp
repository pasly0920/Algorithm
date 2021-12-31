#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N, K;
    cin>>N>>K;
    vector<int> coin;

    int temp;
    for(int i=0; i<N; i++){
        cin>>temp;
        if(temp <= K)
            coin.push_back(temp);
    }
    reverse(coin.begin(), coin.end());
    
    int ans = 0;
    for(int i=0; i<coin.size(); i++){
        if(K == 0)
            break;
        int num = K / coin[i];

        ans += num;
        K -= coin[i] * num;
    }
    
    cout<<ans;
    return 0;
}