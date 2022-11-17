#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int M;
vector<vector<int>> fr;
vector<bool> visited;
void dfs(int now);

int main() {
	cin>>N>>M;
	fr.assign(N+1, vector<int>(0, 0));
	visited.assign(N+1, false);
	
	int a, b;
	for(int i=0; i<M; i++) {
		cin>>a>>b;
		fr[a].push_back(b);
		fr[b].push_back(a);
	}
	
	dfs(1);
	
	int count = 0;
	for(int i=0; i<=N; i++) {
		if(visited[i])
			count ++;
	}
	
	cout<<count;
	return 0;
}

void dfs(int now) {
	visited[now] = true;
	for (int i = 0; i < fr[now].size(); i++)
	{
		int next = fr[now][i];
		if (!visited[next])
      dfs(next);
	}
}