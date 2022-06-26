#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int knapsack[101][100001];
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> W(N+1);
    vector<int> V(N+1);
    for(int i=1;i<=N;i++)
        scanf("%d %d", &W[i], &V[i]);
    for(int i=1;i<=K;i++)
    {
        if(i<W[1])
            knapsack[1][i]=0;
        else    
            knapsack[1][i]=V[1];
    }
    for(int i=2;i<=N;i++)
    {
        for(int j=2;j<=K;j++)
        {
            if(j<W[i])
                knapsack[i][j]=knapsack[i-1][j];
            else
                knapsack[i][j]=max(knapsack[i-1][j], knapsack[i-1][j-W[i]]+V[i]);
        }
    }
    printf("%d", knapsack[N][K]);
    return 0;   
}