#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<int>arr(n, 0);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	vector<bool>isPrime(n+1, true);
	isPrime[0] = false;
	isPrime[1] = false;
	
	for (int i = 2; i <= sqrt(n); i++){
  	if (!isPrime[i])
    	continue;
    for (int j = i * i; j <= n; j += i)
      isPrime[j] = false;
  }
	
	int answer = 0;
	for(int i=1; i<=n; i++)
		if(isPrime[i])
			answer += arr[i - 1];
	
	cout<<answer;
	return 0;
}