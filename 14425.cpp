#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {

	int N, M, cnt = 0;
	unordered_set<string> S;
	string temp;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		S.insert(temp);
	}
	
	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (S.find(temp) != S.end()) cnt++;
	}

	cout << cnt;
}
