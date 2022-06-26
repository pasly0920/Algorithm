#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<int> P;
    int p;
    for(int i=0;i<N;i++)
    {
        cin>>p;
        P.push_back(p);
    }
    int min_sum=0;
    sort(P.begin(), P.end());
    int N_repl=N;
    for(int i=0;i<N;i++)
    {
        min_sum+=(N_repl*P[i]);
        N_repl--;
    }
    cout<<min_sum;
    return 0;
}