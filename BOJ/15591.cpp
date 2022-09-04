#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N, Q;
int solve(vector<vector<int>> usado, int k, int v);
void makeUsaDist(vector<vector<int>> usado, vector<vector<int>> usa_con, vector<vector<int>> usa_dist, int now, int minVal);
vector<bool> check;

int main(){
    cin>>N>>Q;

    vector<vector<int>> usado;
    vector<vector<int>> usa_con;
    usado.assign(N+1, vector<int>(N+1, -1));
    usa_con.assign(N+1, vector<int>(0, 0));
    check.assign(N+1, false);

    int p, q, r;
    for(int i=0; i<N-1; i++){
        cin>>p>>q>>r;
        usado[p][q] = r;
        usado[q][p] = r;
        usa_con[p].push_back(q);
        usa_con[q].push_back(p);
    }

    vector<vector<int>> usa_dist;
    usa_dist.assign(N+1, vector<int>(N+1, -1));
    makeUsaDist(usado, usa_con, usa_dist, 1, 1000000001);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            cout<<usa_dist[i][j]<<' ';
        cout<<'\n';
    }

    int k, v;
    for(int i=0; i<Q; i++){
        cin>>k>>v;
        cout<<solve(usa_dist, k, v)<<'\n';
    }
    return 0;
}

int solve(vector<vector<int>> usa_dist, int k, int v){
    int res = 0;
    for(int i=1; i<=N; i++){
        if(i == v)
            continue;
        if(usa_dist[v][i] >= k)
            res++;
    }
    return res;
}

void makeUsaDist(vector<vector<int>> usado, vector<vector<int>> usa_con, vector<vector<int>> usa_dist, int now, int minVal){
    check[now] = true;
    cout<<now<<'\n';

    for(int i=0; i<usa_con[now].size(); i++){
        int next = usa_con[now][i];
        int nowMinVal = minVal;
        if(now == 1)
            nowMinVal = 1000000001;
        if(!check[next]){
            int min_val;
            if(usado[now][i] != -1)
                min_val = min(nowMinVal, usado[now][i]);
            else
                min_val = usado[now][i];
            cout<<now<<next<<min_val<<'\n';
            usa_dist[now][i] = min_val;
            usa_dist[i][now] = min_val;
            makeUsaDist(usado, usa_con, usa_dist, next, min_val);
        }
    }
}