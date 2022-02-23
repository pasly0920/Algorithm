#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int N, M;

void dfs(vector<vector<int>> &lab, int y, int x);
int count_safe(vector<vector<int>> &lab);

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>> N>> M;
    vector<vector<int>> lab(N);
    vector<pair<int, int>> empty;
    vector<pair<int, int>> virus;
    int temp;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>temp;
            lab[i].push_back(temp);
            if(temp == 0)
                empty.push_back(make_pair(i, j));
            else if(temp == 2)
                virus.push_back(make_pair(i, j));
        }
    }

    int max_val = -1;
    for(int i=0; i<empty.size(); i++){
        for(int j=i+1; j< empty.size(); j++){
            for(int k= j+1; k< empty.size(); k++){
                vector<vector<int>> tempo = lab;
                tempo[empty[i].first][empty[i].second] = 1;
                tempo[empty[j].first][empty[j].second] = 1;
                tempo[empty[k].first][empty[k].second] = 1;
                for(int l=0; l< virus.size(); l++)
                    dfs(tempo, virus[l].first, virus[l].second);
                max_val = max(max_val, count_safe(tempo));
            }
        }
    }

    cout<<max_val;
    return 0;
}

void dfs(vector<vector<int>> &lab, int y, int x){
    for(int i=0; i<4; i++){
        int next_y = y + dy[i];
        int next_x = x + dx[i];

        if((next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) && (lab[next_y][next_x] == 0)){
            lab[next_y][next_x] = 2;
            dfs(lab, next_y, next_x);
        }
    }
    return;
}

int count_safe(vector<vector<int>> &lab){
    int res = 0;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(lab[i][j] == 0)
                res++;
    return res;
}