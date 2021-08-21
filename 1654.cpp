#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;
long long divide(vector<int> &has, int length);
long long bin_search(vector<int> &has, long long st, long long ed);
int N;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int K;
    cin>>K>>N;
    int temp;
    vector<int> has;
    for(int i=0;i<K;i++)
    {
        cin>>temp;
        has.push_back(temp);
    }
    int max=INT_MAX;
    int min=1;
    cout<<bin_search(has, min, max);
    return 0;
}
long long divide(vector<int> &has, int length)
{
    long long summit=0;
    for(int i=0;i<has.size();i++)
    {
        if(has[i]>=length)
            summit+=(has[i]/length);
        else
            summit+=0;
    }
    return summit;
}
long long bin_search(vector<int> &has, long long st, long long ed)
{
    if(st+1>=ed)
        return st;
    if(st+2==ed)
    {
        for(int i=st;i<=INT_MAX;i++)
        {
            if(divide(has, i)<N)
                return i-1;
        }
    }
    long long mid=st/2+ed/2;
    if(divide(has, mid)>=N)
        return bin_search(has, mid, ed);
    else
        return bin_search(has, st, mid);
}