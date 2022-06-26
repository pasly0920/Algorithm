#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> maxDp;
    vector<int> price;
    int N;
    
    cin>>N;
    maxDp.assign(N+1, 0);
    price.assign(N+1, 0);

    for(int i=1; i<=N; i++)
        cin>>price[i];
    
    for(int i=1; i<=N; i++)
        for(int j=0; j<i; j++)
            maxDp[i] = max(maxDp[i], maxDp[j] + price[i-j]);   
    
    cout<<maxDp[N];
    return 0;
}