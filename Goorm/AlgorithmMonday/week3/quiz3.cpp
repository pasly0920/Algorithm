#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
int N, M, K;
vector<vector<int>>bridge;
vector<bool> visit;
void bfs(int maxValue, int target);

int main() {
	cin>>N>>M>>K;
	
	bridge.assign(N+1, vector(0, 0));
	visit.assign(N+1, false);
	for(int i=0; i<M; i++){
		int a, b;
		cin>>a>>b;
		bridge[a].push_back(b);
		bridge[b].push_back(a);
	}
	
	bfs(K, N);
	return 0;
}

void bfs(int maxValue, int target){
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	visit[1] = true;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int i=0; i<bridge[now.first].size(); i++){
			int next = bridge[now.first][i];
			if(!visit[next] && now.second < maxValue){
				q.push(make_pair(next, now.second + 1));
				visit[next] = true;
				if(next == target){
					cout<<"YES";
					return;
				}
			}
		}
	}
	cout<<"NO";
	return;
}