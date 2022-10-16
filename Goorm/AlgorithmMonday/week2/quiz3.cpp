#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	cout<<fixed;
	cout.precision(2);
	int N, k;
	cin>>N>>k;
	
	vector<pair<string, double>> people;
	string s;
	double d;
	for(int i=0; i<N; i++){
		cin>>s>>d;
		people.push_back(make_pair(s, d));
	}
	sort(people.begin(), people.end());
	cout<<people[k-1].first<<' '<<people[k-1].second;
	return 0;
}