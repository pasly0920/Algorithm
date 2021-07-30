#include<iostream>
#include<vector>
using namespace std;
int result=0;
int material[1000][1000];
int dx[4]={0, 1, 0, -1};
int dy[4]={-1, 0, 1, 0};
void elec(int now_x, int now_y, int N, int M);
int main()
{
    int N, M;
    scanf("%d %d", &M, &N);
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            scanf("%1d", &material[i][j]);
    for(int i=0;i<N;i++)
        elec(i, 0, N, M);
    if(result==0)
        printf("NO");
    else 
        printf("YES");
    return 0;
}
void elec(int now_x, int now_y, int N, int M)
{
    if(material[now_y][now_x]==1)
        return;
    if(now_y==(M-1))
        result++;
    material[now_y][now_x]=1;
    for(int i=0;i<4;i++)
    {
        if((now_y+dy[i]>=0)&&(now_y+dy[i]<M))
            if((now_x+dx[i]>=0)&&(now_x+dx[i]<N))
                if(material[now_y+dy[i]][now_x+dx[i]]==0)
                    elec(now_x+dx[i], now_y+dy[i], N, M);
    }
}
