#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int main(){
    int N, M;
    cin>> N>> M;

    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> edge(N+1);
    int tempStart, tempEnd, tempWei;

    for(int i=0; i<M; i++){
        cin>>tempStart>>tempEnd>>tempWei;
        edge[tempStart].push(make_pair(tempWei, tempEnd));
    }

    int ST, ED;
    cin>>ST>>ED;

    vector<int> minDist;
    minDist.assign(N+1 , -1);
    minDist[ST] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, ST));
    
    while(!pq.empty()){
        int current = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        
        if(minDist[current] < dist)
            continue;
        int tempSize = edge[current].size();
        for(int i = 0; i< tempSize; i++){
            int next = edge[current].top().second;
            int nextDist = dist + edge[current].top().first;
            edge[current].pop();

            if(minDist[next] == -1 ||nextDist < minDist[next]){
                minDist[next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }   
        }
    }
    cout<<minDist[ED];
    return 0;
}