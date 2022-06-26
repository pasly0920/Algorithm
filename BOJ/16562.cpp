#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<short> fr;
vector<short> cost;
int find(int node)
{
    if(fr[node]==-1)
        return node;
    else 
        return fr[node] = find(fr[node]);
}
void uni(int a, int b)
{
    int parent_a = find(a);
    int parent_b = find(b);
    if(parent_a==parent_b)
        return;
    if(cost[parent_a]<cost[parent_b])
        fr[parent_b] = parent_a;
    else
        fr[parent_a] = parent_b;
}
vector<bool> check;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin>>n>>m>>k;
    cost.resize(n+1, 0);
    for(int i=1;i<=n;i++)
        cin>>cost[i];
    fr.resize(n+1, -1);
    int a, b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        if(a==b)
            continue;
        uni(a, b);
    }
    check.resize(n+1, false);
    int min_cost = 0;
    for(int i=1;i<=n;i++)
    {
        int min_f = find(i);
        if(min_f==-1)
        {
            min_cost+=cost[i];
            check[i]=true;
            if(min_cost>k)
                break;
            continue;
        }
        if(check[min_f])
            continue;
        else
        {
            min_cost+=cost[min_f];
            check[min_f]=true;
        }
        if(min_cost>k)
            break;
    }
    if(min_cost<=k)
        cout<<min_cost;
    else
        cout<<"Oh no";
    return 0;
}