#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	string s;
	cin>>s;
	int uni = 0;
	char dist = s[0];
	for(int i=1; i<N; i++){
		if(s[i] != dist){
			uni++;
			dist = s[i];
		}
	}
	cout<< ++uni;
	return 0;
}