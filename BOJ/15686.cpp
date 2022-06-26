#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
using namespace std;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int combination(int M);
int min_dist(vector<pair<int, int>> temp);
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    int temp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>temp;
            if(temp == 0)
                continue;
            else if(temp == 1)
                house.push_back(make_pair(i, j));
            else    
                chicken.push_back(make_pair(i, j));
        }
    }
    cout<<combination(M);
    return 0;
}
int combination(int M)
{
    //조합 구현
    int all = chicken.size();
    vector<bool> comb(all, true);
    int fin_sol = 987654321;
    for(int i=0;i<all-M;i++)
        comb[i] = false;
    do{
        vector<pair<int,int>> temp;
        for(int i=0;i<all;i++)
            if(comb[i]){
                //cout<<i<<" ";
                temp.push_back(chicken[i]);
            }
        fin_sol = min(fin_sol, min_dist(temp));
    }while(next_permutation(comb.begin(), comb.end()));
    //그에 대해 전부 거리 계산 작업
    return fin_sol;
}
int min_dist(vector<pair<int, int>> temp)
{
    int res = 0;
    for(int i=0;i<house.size();i++){
        int min_val = 987654321;
        for(int j=0;j<temp.size();j++){
            min_val = min(min_val, abs(house[i].first - temp[j].first) + abs(house[i].second - temp[j].second));
        }
        res += min_val;
    }
    //cout<<res<<endl;
    return res;
}