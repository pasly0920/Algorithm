#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
vector<int> A;
vector<vector<pair<int, int>>> br;
int bfs(int start, int startTime);
bool isValid(int i, int j, int k);

int main() {
	cin>>N>>M;
	A.assign(N+1, 0);
	br.assign(N+1, vector<pair<int, int>>());
	
	for(int i=1; i<=N; i++)
		cin>>A[i];
	
	vector<pair<int, int>> startP;
	for(int i=0; i<M; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		
		if(u == 1)
			startP.push_back(make_pair(v, w));
		if(v == 1)
			startP.push_back(make_pair(u, w));
		
		br[u].push_back(make_pair(v, w));
		br[v].push_back(make_pair(u, w));
	}	
	
	long long minTime = 9223372036854775807;
	for(int i=0; i<startP.size(); i++) {
		long long spendTime = bfs(startP[i].first, startP[i].second);
		if(spendTime != -1)
			minTime = min(minTime, spendTime);
	}
	
	if(minTime == 9223372036854775807)
		cout<< -1;
	else
		cout<<minTime;
	
	return 0;
}

//tuple prev now spendTime
int bfs(int start, int startTime) {
	queue<tuple<int, int, long long>> q;
	vector<int> visitCount;
	visitCount.assign(N+1, 0);
	q.push(make_tuple(1, start, startTime));
	
	long long minSpend = 9223372036854775807;
	
	while(!q.empty()) {
		tuple<int, int, long long> nowP = q.front();
		q.pop();
		int prev = get<0>(nowP);
		int now = get<1>(nowP);
		long long sTime = get<2>(nowP);
		for(int i=0; i<br[now].size(); i++) {
			int next = br[now][i].first;
			if(isValid(prev, now, next)){
				q.push(make_tuple(now, next, sTime + br[now][i].second));
				if(next == N)
					minSpend = min(minSpend, sTime + br[now][i].second);
				visitCount[now] += 1;
				if(visitCount[now] >= N && minSpend == 9223372036854775807)
					return -1;
				if(visitCount[now] >= N && minSpend != 9223372036854775807)
					return minSpend;
			}
		}
	}

	return -1;
}

bool isValid(int i, int j, int k) {
	if(i%A[j] == k%A[j])
		return true;
	else
		return false;
}