#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n;
		cin>>n;
		vector<int>exam(n, 0);
		int sum = 0;
		for(int j=0; j<n; j++){
			cin>>exam[j];
			sum += exam[j];
		}
		double average = (double)sum / n;
		int success = 0;
		for(int j=0; j<n; j++)
			if(exam[j] >= average)
				success ++;
		cout<<success<<'/'<<n<<'\n';
	}
	return 0;
}