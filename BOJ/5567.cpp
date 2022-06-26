#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> connect(n+1);
    int x, y;
    vector<int> result;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        connect[x].push_back(y);
        connect[y].push_back(x);
    }
    int init;
    for(int i=0;i<connect[1].size();i++)
    {
        init=connect[1][i];
        result.push_back(init);
        for(int j=0;j<connect[init].size();j++)
            result.push_back(connect[init][j]);
    }
    if(result.size()==0)
    {
        cout<<0;
        return 0;
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    cout<<result.size()-1;
    return 0;
}