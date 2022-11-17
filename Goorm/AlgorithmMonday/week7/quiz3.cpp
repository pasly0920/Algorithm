#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
int N, M, K;
vector<vector<int>> bridge;
int bfs(int start);

int main() {
	cin>>N>>M>>K;
	bridge.assign(N+1, vector<int> (0, 0));
	
	int a, b;
	vector<int> startP;
	for(int i=0; i<M; i++) {
		cin>>a>>b;
		if(a == K) {
			startP.push_back(b);
		}
		bridge[a].push_back(b);
	}
	
	int minCount = 987654321;
	for(int i=0; i<startP.size(); i++) {
		int start = startP[i];
		
		int count = bfs(start);
		if(count != -1)
			minCount = min(minCount, count);
	}
	
	if(minCount == 987654321)
		cout<<-1;
	else
		cout<<minCount;
	
	return 0;
}

int bfs(int start) {
	vector<bool> visited;
	visited.assign(N+1, false);
	queue<pair<int, int>> q;
	q.push(make_pair(start, 1));
	visited[start] = true;
	
	while(!q.empty()) {
		pair<int, int> nowP = q.front();
		q.pop();
		int now = nowP.first;
		int nowDist = nowP.second;
		for(int i=0; i<bridge[now].size(); i++) {
			int next = bridge[now][i];
			if(!visited[next]) {
				q.push(make_pair(next, nowDist + 1));
				visited[next] = true;
			}
			
			if(next == K) {
				return nowDist + 1;
			}
		}
	}
	
	return -1;
}
