#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int N, K;
vector<pair<int, int>> area;
vector<vector<int>> map;
int xMin, yMin, xMax, yMax;

void mapArea();
int calcArea();

int main() {
	cin>>N>>K;
	
	xMin = 1000;
	xMax = 0;
	yMin = 1000;
	yMax = 0;
	
	map.assign(1001, vector<int>(1001 ,0));
	
	for(int i=0; i<N; i++){
		for(int j=0; j<2; j++){
			int x, y;
			cin>>x>>y;
			
			xMin = min(xMin, x);
			xMax = max(xMax, x);
			yMin = min(yMin, y);
			yMax = max(yMax, y);
			
			area.push_back(make_pair(y, x));
		}
	}
	
	mapArea();
	cout<<calcArea();
	return 0;
}

void mapArea(){
	for(int i=0; i<area.size(); i++){
		pair<int, int> st = area[i];
		pair<int, int> ed = area[i+1];
		
		for(int y=st.first; y<ed.first; y++)
			for(int x=st.second; x<ed.second; x++)
				map[y][x] += 1;
				
		i++;
	}
};

int calcArea(){
	int result = 0;
	
	for(int i=yMin; i<=yMax; i++)
		for(int j=xMin; j<=xMax; j++)
			if(map[i][j] == K)
				result += 1;
	
	return result;
}