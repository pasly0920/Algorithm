#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>start;
vector<int>ending;
vector<int>human;
int dp[100000];
int main()
{
    int N;
    scanf("%d", &N);
    int a, b, c;
    for(int i=0;i<N;i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        start.push_back(a);
        ending.push_back(b);
        human.push_back(c); 
    }
    dp[0]=human[0];
    dp[1]=max(human[0], human[1]);
    for(int i=2;i<ending.size();i++)
        dp[i]=max(dp[i-1], dp[i-2]+human[i]);
    printf("%d", dp[N-1]);
    return 0;
}
