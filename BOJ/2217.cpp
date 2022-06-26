#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<int>W;
    int weight;
    for(int i=0;i<N;i++)
    {
        cin>>weight;
        W.push_back(weight);
    }
    sort(W.begin(), W.end());
    reverse(W.begin(), W.end());
    long long max_w=W[0];
    for(int i=0;i<N;i++)
    {
        if(max_w<(W[i]*(i+1)))
            max_w=W[i]*(i+1);
    }
    cout<<max_w;
    return 0;
}