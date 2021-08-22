#include<iostream>
using namespace std;
int main()
{
    int N, K;
    cin>>N>>K;
    int a=1;
    int b=1;
    for(int i=0;i<K;i++)
        a*=(N-i);
    for(int i=1;i<=K;i++)
        b*=i;
    cout<<a/b;
    return 0;
}