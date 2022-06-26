#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<long long> card;
    long long c;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        card.push_back(c);
    }
    for(int i=0;i<m;i++)
    {
        sort(card.begin(),card.end());
        long long x=card[0];
        long long y=card[1];
        card[0]=x+y;
        card[1]=x+y;
    }
    long long sum=0;
    for(int i=0;i<n;i++)
        sum+=card[i];
    cout<<sum;
    return 0;
}