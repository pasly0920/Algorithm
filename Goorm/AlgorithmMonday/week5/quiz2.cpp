#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<vector<int>> sand;
bool allSandGone();
void sandGone();
bool sandGoneIsValid(int now_y, int now_x);
bool isBridgeAble();

int main() {
	cin>>N>>M;
	sand.assign(N, vector(M, 0));
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin>>sand[i][j];
	
	int day = 0;
	while(!allSandGone()){
		sandGone();
		day++;
		if(isBridgeAble()){
			cout<<day;
			return 0;
		}		
	}
	
	cout<<-1;
	return 0;
}

bool allSandGone(){
	int sandCount = 0;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(sand[i][j] == 1)
				sandCount++;
	
	if(sandCount == 0)
		return true;
	else
		return false;
}

void sandGone(){
	queue<pair<int ,int>> q;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(sand[i][j] == 0 && sandGoneIsValid(i, j))
				q.push(make_pair(i, j));
	
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		
		int now_y = now.first;
		int now_x = now.second;
		
		for(int i=0; i<4; i++)
			if(now_y >= 0 && now_y < N && now_x >= 0 && now_x < M && sand[now_y][now_x] == 1)
				sand[now_y][now_x] = 0;
	}
}

bool sandGoneIsValid(int now_y, int now_x){
	int count = 0;
	
	for(int i=0; i<4; i++){
		int next_y = now_y + dy[i];
		int next_x = now_x + dx[i];
		
		if((next_y < 0 && next_y >= N) || (next_x < 0 && next_x >= M))
			count ++;
		else if(sand[next_y][next_x] == 1)
			count++;
	}
	
	if(count == 0)
		return false;
	else
		return true;
}

bool isBridgeAble(){
	pair<int, int> start = make_pair(-1, -1);
	int sandCount = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(sand[i][j] == 1){
				sandCount ++;
				if(start.first == -1)
					start = make_pair(i, j);
			}
		}
	}
	
	int oneCycleCount = 0;
	queue<pair<int, int>> q;
	q.push(start);
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		
		int now_y = now.first;
		int now_x = now.second;
		if(sand[now_y][now_x] == 1)
			oneCycleCount ++;
		
		for(int i=0; i<4; i++){
			int next_y = now_y + dy[i];
			int next_x = now_x + dx[i];
			
			if(next_y >= 0 && next_y < N && next_x >= 0 && next_x < M && sand[next_y][next_x] == 1)
				q.push(make_pair(next_y, next_x));
		}
	}
	
	if(oneCycleCount < sandCount)
		return true;
	else
		return false;
}