#include<iostream>
#include<vector>
using namespace std;
int N, Q;
vector<int> origin;
vector<int> sum_front;
vector<long long> permutation;
void solve(int l, int r);
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>Q;
    origin.resize(N+1, 0);
    sum_front.resize(N+2, 0);
    long long total = 0;
    for(int i=1; i<=N; i++){
        cin>>origin[i];
        total+=origin[i];
    }
    permutation.resize(N+1, 0);
    long long temp = 0;
    permutation[N] = 0;
    long long temp_sum = origin[N];
    for(int i=N-1;i>=1;i--){
        permutation[i] = permutation[i+1] + origin[i] * temp_sum;
        temp_sum += origin[i];
    }
    sum_front[1] = total;
    for(int i=2; i<=N; i++){
        total -= origin[i-1];
        sum_front[i] = total;
    }
    sum_front[N+1] = 0;
    int l, r;
    for(int i=0;i<Q;i++){
        cin>>l>>r;
        solve(l, r);
    }
    return 0;
}
void solve(int l, int r){
    long long sum = 0;
    sum = permutation[l] - (permutation[r])*(sum_front[l] - sum_front[r+1]);
    cout<<sum<<'\n';
}