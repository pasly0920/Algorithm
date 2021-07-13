#include<iostream>
using namespace std;
int big_mod(int A, int exp, int mod);
int main()
{
    int A, B, C;
    cin>>A>>B>>C;
    cout<<big_mod(A, B, C);
    return 0;
}
int big_mod(int A, int exp, int mod)
{
    if(exp==0)
        return 1%mod;
    if((exp%2)==0)
    {
        long long doub=big_mod(A, exp/2, mod);
        return doub*doub%mod;
    }
    else
    {
        long long doub=big_mod(A, exp/2, mod);
        return doub*doub%mod*A%mod;
    }
}