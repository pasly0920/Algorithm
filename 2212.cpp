#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N, K;
    cin>>N;
    cin>>K;
    int place;
    vector<int> P;
    for(int i=0;i<N;i++)
    {
        cin>>place;
        P.push_back(place);
    }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
   
    return 0;
}