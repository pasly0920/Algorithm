#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> ppl;
vector<int> grade;

int getGrade(int i);

int main() {
  cin>> N;
  grade.assign(N, 0);

  int wei, hei;
  for(int i=0; i<N; i++) {
    cin>>wei>>hei;
    ppl.push_back(make_pair(wei, hei));
  }
  
  for(int i=0; i<N; i++) {
    grade[i] =  getGrade(i);   
  }

  for(int i=0; i<N; i++)
    cout<< grade[i]<<" ";

  return 0;
}

int getGrade(int i) {
  int bigger = 0;

  int nowWei = ppl[i].first;
  int nowHei = ppl[i].second;
  for(int j=0; j<N; j++) {
    if(j == i)
      continue;
    if(nowWei < ppl[j].first && nowHei < ppl[j].second)
      bigger ++;
  }

  return bigger + 1;
}