#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;
unordered_map<int, int> vl;
int recursive_solve(int N, int P, int Q);
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, P, Q;
    cin>>N>>P>>Q;
    cout<<recursive_solve(N, P, Q);
    return 0;
}
int recursive_solve(int N, int P, int Q)
{
    if(N==0)
        return 1;
    else if(vl.find(N)!=vl.end())
        return vl[N];
    else 
        vl[N]=recursive_solve(floor(N/P), P, Q)+recursive_solve(floor(N/Q), P, Q);
    return vl[N];
}