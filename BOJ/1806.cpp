#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    long long S;
    long long sum = 0;

    cin>>N>>S;
    vector<int> nums(N);
    for(int i = 0; i<N; i++){
        cin>>nums[i];
        sum += nums[i];
    }

    if(sum < S){
        cout<<"0";
        return 0;
    }
    else if(sum == S){
        cout<<N;
        return 0;
    }
    int st, ed = 0;
    int minLen = N;
    sum = 0;

    for(st = 0; st < N; st++){
        for(; ed <= N; ed++){
            if(sum >= S){
                minLen = min(minLen, ed - st);
                break;
            }
            if(ed == N)
                break;
            sum += nums[ed];
        }
        sum -= nums[st];
    }   
    if(sum >= S)
        minLen = min(minLen, ed - st);
    if(minLen == N)
        cout<<0;
    else if(minLen == 0)
        cout<<1;
    else
        cout<<minLen;
    return 0;
}