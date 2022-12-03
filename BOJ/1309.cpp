#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;

int main() {
  cin>> N;
  vector<vector<int>> zoo;
  zoo.assign(N+1, vector<int>(3, 0));

  zoo[1][0] = 1;
  zoo[1][1] = 1;
  zoo[1][2] = 1;
  
  for(int i=2; i <= N; i++) {
    zoo[i][0] = (zoo[i-1][0] + zoo[i-1][1] + zoo[i-1][2])%9901;
    zoo[i][1] = (zoo[i-1][0] + zoo[i-1][2])%9901;
    zoo[i][2] = (zoo[i-1][0] + zoo[i-1][1])%9901;
  }

  cout<<(zoo[N][0] + zoo[N][1] + zoo[N][2])%9901;
  return 0;
}