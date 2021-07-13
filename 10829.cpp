#include<iostream>
using namespace std;
void bin(long long N);
int main()
{
    long long N;
    cin>>N;
    if(N==0)
    {
        cout<<0;
        return 0;
    }
    bin(N);
    return 0; 
}
void bin(long long N)
{
    if(N==0)
        return;
    bin(N/2);
    cout<<N%2;
}