#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
long long min_val = 123456789012345;
vector<vector<int>> S;
vector<int> team;
vector<int> team2;
void tracking(int now);
long long calc_val();

int main(){
    cin>>N;
    S.assign(N+1, vector<int>(N+1, 0));

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin>>S[i][j];

    tracking(0);

    cout<<min_val;
    return 0;
}

void tracking(int now){
    if(team.size() == (N/2)){
        int idx = 0;
        for(int i=1; i<=N; i++){
            if(team[idx] == i)
                idx++;
            else
                team2.push_back(i);
        }
        min_val = min(min_val, calc_val());
        team2.clear();
        return;
    }

    for(int i= now + 1; i<=N; i++){
        team.push_back(i);
        tracking(i);
        team.pop_back();
    }
}

long long calc_val(){
    long long res1, res2;
    res1=0, res2=0;
    
    for(int i=0; i<team.size(); i++)
        for(int j=0; j<team.size(); j++)
            res1 += S[team[i]][team[j]];
    for(int i=0; i<team2.size(); i++)
        for(int j=0; j<team2.size(); j++)
            res2 += S[team2[i]][team2[j]];    

    long long sub = res1 - res2;
    if(sub >= 0)
        return sub;
    else
        return -1 * sub;
}