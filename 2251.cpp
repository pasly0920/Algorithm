#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dx[4]={0, 1, 0, -1};
int dy[4]={-1, 0, 1, 0};
int si=0;
void DFS(vector<vector<int>> &map, int now_y, int now_x, int N);
vector<int> result;
int main()
{
    int N;
    scanf("%d", &N);
    vector<vector<int>>map(N);
    int n;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%1d", &n);
            map[i].push_back(n);
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j]==1)
            {
                DFS(map, i, j, N);
                result.push_back(si);
                si=0;
            }
        }
    }
    sort(result.begin(), result.end());
    printf("%d\n", result.size());
    for(int i=0;i<result.size();i++)
        printf("%d\n", result[i]);
    return 0;
}
void DFS(vector<vector<int>> &map, int now_y, int now_x, int N)
{
    if(map[now_y][now_x]!=1)
        return;
    map[now_y][now_x]+=1;
    si++;
    for(int i=0;i<4;i++)
    {
        int nx=now_x+dx[i];
        int ny=now_y+dy[i];
        if((nx>=0)&&(nx<N))
            if((ny>=0)&&(ny<N))
                DFS(map, ny, nx, N);
    }
}