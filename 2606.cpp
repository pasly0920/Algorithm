#include<iostream>
#include<vector>
using namespace std;
int result=0;
void tracking(vector<vector<int>>edge, int place);
vector<bool> defect;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, pair;
    cin>>N>>pair;
    defect.assign(N+1, false);
    vector<vector<int>> edge(N+1);
    int x, y;
    for(int i=1;i<=pair;i++)
    {
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    tracking(edge, 1);
    //count
    for(int i=2;i<=N;i++)
    {
        if(defect[i]==true)
            result++;
    }
    cout<<result;
    return 0;
}
void tracking(vector<vector<int>>edge, int place)
{
    if(defect[place])
        return;
    defect[place]=true;
    for(int i=0;i<edge[place].size();i++)
    {
        int next=edge[place][i];
        if(!defect[next])
            tracking(edge, next);
    }
}