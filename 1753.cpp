#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
vector<pair<int, int>> edge[20001];
vector<int> min_val;
int V, E;
int root;
void dijkstra(int now);
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>V>>E;
    cin>>root;
    //edge.resize(V+1, 0);
    min_val.resize(V+1, 987654321);
    int start, end, value;
    for(int i=0;i<E;i++)
    {
        cin>>start>>end>>value;
        edge[start].push_back(make_pair(end, value));
    }
    dijkstra(root);
    for(int i=1;i<=V;i++)
        if(min_val[i]==987654321)
            cout<<"INF\n";
        else
            cout<<min_val[i]<<'\n';
    return 0;
}
void dijkstra(int now){
    min_val[now]=0;
    priority_queue<pair<int, int>> pq;//min heap
    pq.push(make_pair(0, now));
    while(!pq.empty()){
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        if(min_val[current] < distance)
            continue;
        for(int i=0;i<edge[current].size();i++){
            int next = edge[current][i].first;
            int nextDistance = distance + edge[current][i].second;
            if(nextDistance < min_val[next]){
                min_val[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}