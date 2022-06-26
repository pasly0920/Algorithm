#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
using namespace std;
int backpack_num=-1;
void solve(vector<pair<int, short>> &object, vector<int>& backpack, int W_max);
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    int W, V;
    vector<pair<int, short>> object;
    object.push_back(make_pair(0, 0));
    for(int i=1;i<=N;i++)
    {
        cin>>W>>V;
        object.push_back(make_pair(W, V));
    }
    vector<int>backpack(M+1);
    int W_max=0;
    for(int i=1;i<=M;i++)
    {
        cin>>backpack[i];
        W_max=max(W_max, backpack[i]);
    }
    solve(object, backpack, W_max);
    cout<<backpack_num;
    return 0;
}
void solve(vector<pair<int, short>> &object, vector<int>& backpack, int W_max)
{
    int W = W_max;
    int I = object.size()-1;
    vector<vector<unsigned int>> DP(I+1, vector<unsigned int>(W+1, 0));
    for(int i=0;i<=I;i++)
        DP[i][0]=0;
    for(int i=0;i<=W;i++)
        DP[0][i]=0;
    for(int i=1;i<=I;i++)
        for(int j=1;j<=W;j++)
            if(object[i].first<=j)
                DP[i][j]=max(object[i].second+DP[i-1][j-object[i].first], DP[i-1][j]);
            else
                DP[i][j]=DP[i-1][j];
    long double max_efficient = -1;
    long double efficient;
    for(int i=1;i<=backpack.size()-1;i++)
    {
        efficient=(long double)DP[I][backpack[i]]/backpack[i];
        if(efficient>max_efficient)
        {
            max_efficient=efficient;
            backpack_num=i;
        }
    }
}