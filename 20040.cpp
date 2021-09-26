#include<iostream>
#include<vector>
using namespace std;
vector<int> dot;
int find(int node)
{
    if(dot[node]==-1)
        return node;
    else 
        return dot[node] = find(dot[node]);
}
void uni(int a, int b)
{
    int parent_a = find(a);
    int parent_b = find(b);
    dot[parent_b]= parent_a;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    dot.resize(n, -1);
    int ans=0;
    int a, b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        if(ans!=0)
            continue;
        if((find(a)==find(b))&&(find(a)>=0))
            ans=i;
        else
            uni(a, b);
    }
    cout<<ans;
    return 0;
}