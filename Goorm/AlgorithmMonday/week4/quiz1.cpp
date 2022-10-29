#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	long long count;
	int M;
	cin>>count>>M;
	
	string type;
	int money;
	queue<int> q;
	for(int i=0; i<M; i++){
		cin>>type>>money;

		if(type == "deposit"){
			count += money;
		}
		else if(type == "pay"){
			if(count > money)
				count -= money;
		}
		else{
			
			if(count > money && q.empty())
				count -= money;
			else
				q.push(money);
		}
		
		while(!q.empty()){
			if(count < q.front())
				break;
			count -= q.front();
			q.pop();
		}
	}
	
	cout<<count;
	return 0;
}