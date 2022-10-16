#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int main() {
	int n, k;
	cin>>n>>k;
	
	vector<vector<int>> map(n+1, vector<int>(n+1, 0));
	int a, b;
	for(int i=0; i<k; i++){
		cin>>a>>b;
		map[a][b] += 1;
		for(int j=0; j<4; j++){
			int nextY = a + dy[j];
			int nextX = b + dx[j];
			if(nextY <= 0 || nextY > n || nextX <= 0 || nextX > n)
				continue;
			map[nextY][nextX] += 1;
		}
	}
	
	int sum =0;
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			sum += map[i][j];
	
	cout<<sum;
	return 0;
}