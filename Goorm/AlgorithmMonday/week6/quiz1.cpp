#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve(int num);

int main() {
	int num;
	for(int i=0; i<5; i++){
		cin>>num;
		cout<<solve(num)<<'\n';
	}
	return 0;
}

int solve(int num){
	int a = 0;
	vector<int> singleNum;
	while (num != 0) {
    singleNum.push_back(num % 10);
  	num /= 10;
  }

	a = singleNum[0] + singleNum [2] + singleNum[4] + singleNum[6];

	if(singleNum[1] != 0)
		a *= singleNum[1];
	if(singleNum[3] != 0)
		a*= singleNum[3];
	if(singleNum[5] != 0)
		a *= singleNum[5];
	
	return a % 10;
}