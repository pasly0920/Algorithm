#include<iostream>
using namespace std;
long long board[1001][1001];
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        board[i][1]=1;
    for(int j=1;j<=m;j++)
        board[1][j]=1;
    for(int i=2;i<=n;i++)
        for(int j=2;j<=m;j++)
            board[i][j]=(board[i-1][j-1]+board[i-1][j]+board[i][j-1])%1000000007;
    cout<<board[n][m];
    return 0;
}