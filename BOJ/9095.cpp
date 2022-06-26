#include<iostream>
#include<vector>

using namespace std;
int res = 0;
int n;
int num_case[3] = {1, 2, 3};
void dfs(int now);

int main() {
    int T;
    cin>>T;

    for(int i=0; i<T; i++){
        cin>>n;
        dfs(0);
        cout<<res<<'\n';
        res = 0;
    }

    return 0;
}

void dfs(int now){
    if(now > n)
        return;
    if(now == n){
        res ++;
        return;
    }
    for(int i=0; i<3; i++)
        dfs(now + num_case[i]);
}