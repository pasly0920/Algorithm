#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin>>A[i];
    sort(A.begin(), A.end());
    int M;
    cin>>M;
    vector<int> B(M);
    for(int i=0;i<M;i++)
        cin>>B[i];
    for(int i=0;i<M;i++)
    {
        if(A[lower_bound(A.begin(), A.end(), B[i])-A.begin()]==B[i])
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }
    return 0;
}   