#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<vector<int>> map;
void validate(int now_y, int now_x);

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N>>M;
	map.assign(N+1, vector(N+1, 0));
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin>>map[i][j];
		
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(map[i][j] == 2)
				validate(i, j);
	
	int count = 0;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(map[i][j] == -1)
				count ++;
	
	cout<<count;
	return 0;
}

void validate(int now_y, int now_x){
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(now_y, now_x, 0));
	
	int isOk = false;
	while(!q.empty()){
		tuple<int, int, int> now = q.front();
		q.pop();
		
		int now_y = get<0>(now);
		int now_x = get<1>(now);
		int dist = get<2>(now);
		
		for(int i=0; i<4; i++){
			int next_y = now_y + dy[i];
			int next_x = now_x + dx[i];
			int next_dist = dist + 1;
			
			if(next_dist > M)
				continue;
			
			if(next_y >= 1 && next_y <= N && next_x >= 1&& next_x <=N)
				if(map[next_y][next_x] == 1)
					map[next_y][next_x] = -1;
				q.push(make_tuple(next_y, next_x, next_dist));	
		}
	}
}
