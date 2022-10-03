#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	long long answer = 1;
	int temp;
	for(int i=0; i<n; i++){
		cin>>temp;
		answer *= temp;
	}
	
	cout<<answer;
	return 0;
}