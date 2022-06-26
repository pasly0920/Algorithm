#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long unsigned tile[1001];
    tile[0]=1; 
    tile[1]=1;
    for(int i=2;i<=n;i++)
        tile[i]=tile[i-1]+tile[i-2];
    cout<<tile[n]%10007;
    return 0;
}