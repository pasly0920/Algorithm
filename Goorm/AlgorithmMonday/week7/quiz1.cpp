#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int k;
vector<int> eventCount;

bool desc(int a, int b){ 
  return a > b; 
} 

int main() {
	cin>>N>>M;
	eventCount.assign(N+1, 0);
	for(int i=0; i<M; i++) {
		cin>>k;
		int temp;
		for(int j=0; j<k; j++){
			cin>>temp;
			eventCount[temp] += 1;
		}
	}
	
	int maxCount = 0;
	vector<int> maxCountGroup;
	for(int i=0; i<=N; i++) {
		if(eventCount[i] > maxCount) {
			maxCount = eventCount[i];
			maxCountGroup.clear();
			maxCountGroup.push_back(i);
		}
		else if(eventCount[i] == maxCount) {
			maxCountGroup.push_back(i);
		}
	}
	
	sort(maxCountGroup.begin(), maxCountGroup.end(), desc);
	for(int i=0; i < maxCountGroup.size(); i++) {
		cout<<maxCountGroup[i]<<' ';
	}
	return 0;
}