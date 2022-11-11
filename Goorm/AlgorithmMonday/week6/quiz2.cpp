#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	string crypted;
	cin>>N>>crypted;
	
	string encrypted = "";
	for(int i=0; i<N; i++){
		int order = i + 1;
		if(order%2 == 1){
			char targetChr = crypted[i];
			int targetChrNum = targetChr - 'a';
			int loopCount = ((int)(crypted[order] - '0') * (int)(crypted[order] - '0'));
			int resultChr = (targetChrNum + loopCount) % 26;
			encrypted += (char)(resultChr + 'a');
		}
	}
	
	cout<<encrypted;
	
	
	return 0;
}