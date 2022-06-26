#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int dx[4]={0, 1, 0, -1};
int dy[4]={-1, 0, 1, 0};
vector<vector<bool>> visited(50);
short R, C;
short BFS(vector<vector<char>> &forest, short now_y, short now_x);
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C;
    vector<vector<char>> forest(R);
    short now_x, now_y;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            char temp;
            cin>>temp;
            if(temp=='S')
            {
                now_x=j;
                now_y=i;
                forest[i].push_back('.');
            }
            else
                forest[i].push_back(temp);
        }
    }
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
            visited[i].push_back(false);
    }
    visited[now_y][now_x]=true;
    int ans=BFS(forest, now_y, now_x);
    if(ans==-1)
        cout<<"KAKTUS";
    else
        cout<<ans;
    return 0;
}
short BFS(vector<vector<char>> &forest, short now_y, short now_x)
{
    queue<pair<short, short>> life;
    queue<pair<short, short>> water;
    life.push(make_pair(now_y, now_x));
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(forest[i][j]=='*')
                water.push(make_pair(i, j));
    short time=0;
    while(!life.empty())
    {
        time++;
        if(time>=R*C)
            return -1;
        //water BFS
        int water_size=water.size();
        for(int i=0;i<water_size;i++)
        {
            pair<short, short> wat=water.front();
            water.pop();
            for(int j=0;j<4;j++)
            {
                short xx=wat.second+dx[j];
                short yy=wat.first+dy[j];
                if(yy>=0&&yy<R)
                    if(xx>=0&&xx<C)
                        if(forest[yy][xx]=='.')
                        {
                            forest[yy][xx]='*';
                            water.push(make_pair(yy, xx));
                            //cout<<j<<yy<<" "<<xx<<endl;
                        }
            }
        }
        //life BFS
        int life_size=life.size();
        for(int i=0;i<life_size;i++)
        {
            pair<short, short> lif=life.front();
            life.pop();
            bool survive=false;
            if(forest[lif.first][lif.second]=='*')
            {
                for(int i=0;i<4;i++)
                {
                    int xx=lif.second+dx[i];
                    int yy=lif.first+dy[i];
                    if(yy>=0&&yy<R)
                        if(xx>=0&&xx<C)
                            if(forest[yy][xx]=='D')
                                survive=true;
                }
                if(!survive)
                    continue;
            }
            for(int j=0;j<4;j++)
            {
                int xx=lif.second+dx[j];
                int yy=lif.first+dy[j];
                if(yy>=0&&yy<R)
                    if(xx>=0&&xx<C)
                        if(forest[yy][xx]=='.'&&visited[yy][xx]==false)
                        {
                            life.push(make_pair(yy, xx));
                            visited[yy][xx]=true;
                        }
                        else if(forest[yy][xx]=='D')
                            return time;            
            }
        }
    }
    return -1;
}