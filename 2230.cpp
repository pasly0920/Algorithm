#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    vector<int> num(N);
    for(int i=0;i<N;i++)
        cin>>num[i];
    sort(num.begin(), num.end());
    int min_val=INT_MAX;
    for(int i=0;i<N-1;i++)
    {
        auto temp = lower_bound(num.begin()+i, num.begin()+N, num[i]+M);
        if(temp==num.end())
            continue;
        else
            min_val=min(*temp-num[i], min_val);
    }
    cout<<min_val;
    return 0;
}