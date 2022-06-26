#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N, M;
vector<int> num;
vector<int> target;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    num.assign(N, 0);
    for(int i=0; i<N; i++)
        cin>>num[i];
    sort(num.begin(), num.end());

    cin>>M;
    target.assign(M, 0);
    for(int i=0; i<M; i++)
        cin>>target[i];

    for(int i=0; i<M; i++){
        int targetNum = target[i];
        cout<<int(binary_search(num.begin(), num.end(), targetNum))<<'\n';
    }

    return 0;
}