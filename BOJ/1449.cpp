#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N, L;
    cin>>N>>L;
    int place;
    vector<int> P;
    for(int i=0;i<N;i++)
    {
        cin>>place;
        P.push_back(place);
    }
    sort(P.begin(), P.end());
    int count=1;
    int prev_d=P[0];
    for(int i=0;i<N;i++)
    {
        if(P[i]<(prev_d+L))
            continue;
        else
        {
            count++;
            prev_d=P[i];
        }
    }
    cout<<count;
    return 0;
}