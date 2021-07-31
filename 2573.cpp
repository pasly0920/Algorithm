#include<iostream>
using namespace std;
int iceland[300][300];
int new_iceland[300][300];
int dx[4]={0, 1 ,0, -1};
int dy[4]={-1, 0, 1 ,0};
void ice(int now_x, int now_y, int N, int M);
void find_1(int N, int M);
int res=0;
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d", &iceland[i][j]);
    //input comp
    int melt_time=0;
    int ice_sum=0;
    while(1)
    {
        ice_sum=0;
        melt_time++;
        int temp=0;
        int count_0=0;
        for(int i=1;i<N-1;i++)
        {
            for(int j=1;j<M-1;j++)
            {
                if(iceland[i][j]==0)
                {
                    count_0++;
                    continue;
                }
                if(iceland[i][j]<0)
                    iceland[i][j]*=-1;
                if(iceland[i][j]>0)
                {
                    for(int k=0;k<4;k++)
                    {
                        int nx=j+dx[k];
                        int ny=i+dy[k];
                        if(iceland[ny][nx]==0)
                            temp++;
                    }
                    new_iceland[i][j]=iceland[i][j]-temp;
                    if(new_iceland[i][j]<=0)
                        new_iceland[i][j]=-1;
                }
                temp=0;
            }
        }
        for(int i=1;i<N-1;i++)
        {
            for(int j=1;j<M-1;j++)
            {
                if(new_iceland[i][j]<=-1)
                {
                    iceland[i][j]=0;
                    new_iceland[i][j]=0;
                }  
                else if(new_iceland[i][j]!=0)
                {
                    iceland[i][j]=new_iceland[i][j];
                    new_iceland[i][j]=0;
                }
            }
        }
        if(count_0==((N-2)*(M-2)))
        {
            melt_time=0;
            break;
        }
        //melt 동시에 전부 0인지 확인
        for(int i=1;i<N-1;i++)
        {
            for(int j=1;j<M-1;j++)
            {
                if(res!=0)
                    continue;
                if(iceland[i][j]<=0)
                    continue;
                res=0;
                if(iceland[i][j]>0)
                {
                    ice(j, i, N, M);//dfs
                    find_1(N, M);
                    if(res>=1)
                    {
                        printf("%d", melt_time);
                        return 0; 
                    }   
                }   
            }
        }
        //덩이 계산
    }
    if(melt_time==0)
        printf("0");
    return 0;
}
void ice(int now_x, int now_y, int N, int M)
{
    if(iceland[now_y][now_x]<=0)
        return;
    iceland[now_y][now_x]*=-1;
    for(int i=0;i<4;i++)
    {
        int cx=now_x+dx[i];
        int cy=now_y+dy[i];
        if((cx<1)||(cx>M-2))
            continue;
        if((cy<1)||(cy>N-2))
            continue;
        if(iceland[cy][cx]!=0)
            ice(cx, cy, N, M);
    }
}
void find_1(int N, int M)
{
    for(int i=1;i<N-1;i++)
        for(int j=1;j<M-1;j++)
            if(iceland[i][j]>0)
                res++;
}