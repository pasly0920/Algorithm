#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<int> A;
    vector<int> B;
    int a, b;
    for(int i=0;i<N;i++)
    {
        cin>>a;
        A.push_back(a);
    }
    for(int i=0;i<N;i++)
    {
        cin>>b;
        B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(A.begin(), A.end());
    int sum=0;
    for(int i=0;i<N;i++)
    {
        sum+=(A[i]*B[i]);
    }
    cout<<sum;
    return 0;
}