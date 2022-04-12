#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N, M;
vector<int> possible;
vector<int> now;
void tracking();

int main(){
    cin>>N>>M;

    for(int i=1; i<=N; i++)
        possible.push_back(i);

    tracking();

    return 0;
}

void tracking(){
    if(now.size() == M){
        for(int i=0;i<now.size(); i++)
            cout<<now[i]<<' ';
        cout<<'\n';
        return;
    }

    for(int i=0; i<N; i++){
        now.push_back(possible[i]);
        tracking();
        now.pop_back();
    }
        
}