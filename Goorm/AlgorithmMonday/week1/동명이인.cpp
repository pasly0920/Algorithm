#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	string target;
	cin>>target;
	
	vector<string> name;
	string temp;
	for(int i=0; i<n; i++){
		cin>>temp;
		name.push_back(temp);
	}
	
	int answer = 0;
	for(int i=0; i<n; i++)
		if(name[i].find(target) != string::npos)
			answer++;
	
	cout<<answer;
	return 0;
}