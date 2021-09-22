#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int DP[1000][1000];
int maze[1000][1000];
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>maze[i][j];
    DP[0][0]=maze[0][0];
    for(int i=1;i<N;i++)
        DP[i][0]=maze[i][0]+DP[i-1][0];
    for(int i=1;i<M;i++)
        DP[0][i]=maze[0][i]+DP[0][i-1];
    for(int i=1;i<N;i++)
        for(int j=1;j<M;j++)
            DP[i][j]=max(DP[i-1][j-1], max(DP[i-1][j], DP[i][j-1]))+maze[i][j];
    cout<<DP[N-1][M-1];
    return 0;
}