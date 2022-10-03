#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdlib.h>

using namespace std;

int getDist(pair<int, int>a, pair<int, int>b){
	return abs(a.first - b.first) + abs(a.second-b.second);
}

int main() {
	vector<pair<int, int>> dist;
	
	vector<int> num(4, 0);
	for(int i=0; i<4; i++)
		cin>>num[i];
	
	for(int i=0; i<4; i++)
		for(int j=i+1; j<4; j++)
				dist.push_back(make_pair(num[i], num[j]));
	
	int maxDist = 0;
	for(int i=0; i<dist.size(); i++)
		for(int j=i+1; j<dist.size(); j++)
			if(dist[i].first == dist[j].first || dist[i].first == dist[j].second || dist[i].second == dist[j].first || dist[i].second == dist[j].second )
					continue;
			else
				maxDist = max(maxDist, getDist(dist[i], dist[j]));
	
	cout<<maxDist;
	return 0;
}