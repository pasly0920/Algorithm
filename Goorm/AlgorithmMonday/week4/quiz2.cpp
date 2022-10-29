#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> map;
vector<vector<int>> tempMap;
int N;

bool isComplte();
void fall();

int main() {
	cin>>N;
	map.assign(N+1, vector<int>(N+1, -1));
	tempMap = map;
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin>>map[i][j];
	
	int day = 0;
	while(!isComplte()){
		day++;
		fall();
	}
	
	cout<<day;
	return 0;
}

bool isComplte(){
	int count = 0;
	for(int i=1;i<=N; i++)
		for(int j=1; j<=N; j++)
			count += map[i][j];
	return count == 0;
}

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void fall(){
	tempMap = map;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			int c = 0;
			
			for(int k=0; k<4; k++){
				int next_y = i + dy[k];
				int next_x = j + dx[k];
				
				if(next_y <= 0 || next_y >N || next_x <= 0 || next_x > N)
					continue;
				
				if(map[next_y][next_x] == 0)
					c++;
			}
			tempMap[i][j] -= c;
			if(tempMap[i][j] < 0)
				tempMap[i][j] = 0;
		}
	}
	map = tempMap;
}

