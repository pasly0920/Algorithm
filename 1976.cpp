#include<iostream>
#include<vector>
using namespace std;
vector<int> path;
int find(int city)
{
    if(path[city]==city)
        return city;
    else 
        return path[city] = find(path[city]);
}
void uni(int a, int b)
{
    int parent_a = find(a);
    int parent_b = find(b);
    path[parent_a] = parent_b;
}
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    path.resize(N+1);
    for(int i=1;i<=N;i++)
        path[i]=i;
    int chk;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>chk;
            if(chk==0)
                continue;
            else
                uni(i, j);
        }
    }
    int temp_a, temp_b;
    if(M==1)
    {
        cin>>temp_a;
        cout<<"YES";
        return 0;
    }
    bool ans = true;
    cin>>temp_a>>temp_b;
    if(find(temp_a)!=find(temp_b))
        ans = false;
    for(int i=2;i<M;i++)
    {
        temp_a = temp_b;
        cin>>temp_b;
        if(ans==false)
            continue;
        if(find(temp_a)==find(temp_b))
            continue;
        else
            ans = false;
    }
    if(ans==true)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}