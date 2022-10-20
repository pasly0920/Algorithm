#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
	return abs(a) < abs(b);
}

int main() {
	int n;
	cin>>n;
	
	long long sum = 0;
	int temp;
	for(int i=0; i<n; i++){
		cin>>temp;
		sum += temp;
	}
	cout<<sum;
	return 0;
}