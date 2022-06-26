#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> dp;
int cal(int X);
int main()
{
    int X;
    cin>>X;
    dp.assign(X+1, -1);
    cout<<cal(X);
    return 0;
}
int cal(int X)
{
    if(X==1)
        return 0;
    if(dp[X]!=-1)
        return dp[X];
    int result=cal(X-1)+1;
    if(X%3==0)
        result=min(result, cal(X/3)+1);   
    if(X%2==0)
        result=min(result, cal(X/2)+1);
    dp[X]=result;
    return result;
}