#include<iostream>
using namespace std;
int pap[128][128];
int white=0, blue=0;
void color(int N, int x, int y);
bool same(int N, int x, int y);
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d", &pap[i][j]);
    if(same(N, 0, 0))
    {
        if(pap[0][0]==0)
        {
            printf("%d\n%d", 1, 0);
            return 0;
        }
        else
        {
            printf("%d\n%d", 0, 1);
            return 0;
        }
    }
    color(N, 0, 0);
    printf("%d\n%d", white, blue);
    return 0;
}
void color(int N, int x, int y)
{
    if(N==1)
    {
        if(pap[y][x]==0)
        {
            white++;
            return;
        }
        else
        {
            blue++;
            return;
        }
    }
    else if(same(N, x, y))
    {
        if(pap[y][x]==0)
        {
            white++;
            return;
        }    
        else   
        {
            blue++;
            return;
        }
    }
    else
    {
        int base=N/2;
        //1
        color(base, x, y);
        //2
        x+=base;
        color(base, x, y);
        //3
        x-=base;
        y+=base;
        color(base, x, y);
        //4
        x+=base;
        color(base, x, y);
    }
}
bool same(int N, int x, int y)
{
    int color=pap[y][x];
    for(int i=y;i<y+N;i++)
        for(int j=x;j<x+N;j++)
        {
            if(pap[i][j]!=color)
                return false;
        }
    return true;
}