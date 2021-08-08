#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int prev_i=0;
vector<vector<int>> tree(26);
vector<bool> visited(26);
vector<bool> print(26);
stack<int> arr;
void front_search(int now);
void mid_search(int now);
void back_search(int now);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    char a, x, y;
    for(int i=0;i<N;i++)
    {
        cin>>a;
        cin>>x>>y;
        int a_i=(int)(a-'A');
        int x_i=(int)(x-'A');
        int y_i=(int)(y-'A');
        if(x!='.')
            tree[a_i].push_back(x_i);
        else
            tree[a_i].push_back(-1);
        if(y!='.')
            tree[a_i].push_back(y_i);
        else
            tree[a_i].push_back(-1);
    }
    visited.assign(26, false);
    cout<<'A';
    front_search(0);
    cout<<'\n';
    visited.assign(26, false);
    print.assign(26, false);
    mid_search(0);
    cout<<'\n';
    visited.assign(26, false);
    back_search(0);
    while(1)
    {
        if(arr.size()==0)
            break;
        cout<<(char)(arr.top()+'A');
        arr.pop();
    }
    return 0;
}
void front_search(int now)
{
    if(visited[now]==true)
        return;
    visited[now]=true;
    for(int i=0;i<tree[now].size();i++)
    {
        if(tree[now][i]==-1)
            continue;
        if(!visited[tree[now][i]])
        {
            cout<<(char)(tree[now][i]+'A');
            front_search(tree[now][i]);
        }
    }
}
void mid_search(int now)
{
    if(visited[now]==true)
        return;
    visited[now]=true;
    for(int i=0;i<2;i++)
    {
        if((tree[now][0]==-1)||(visited[tree[now][0]]==true))
        {
            if(print[now]!=true)
            {
                print[now]=true;
                cout<<(char)(now+'A');
            }
        }
        if(tree[now][i]==-1)
            continue;
        mid_search(tree[now][i]);
    }
}
void back_search(int now)
{
    if(visited[now]==true)
        return;
    visited[now]=true;
    arr.push(now);
    for(int i=0;i<2;i++)
    {
        if(tree[now][i]==-1)
            continue;
        back_search(tree[now][i]);
        cout<<(char)(arr.top()+'A');
        arr.pop();
    }
}