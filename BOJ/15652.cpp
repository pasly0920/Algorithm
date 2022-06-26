#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N, M;
vector<int> possible;
vector<int> now;
void tracking(int prev);

int main(){
    cin>>N>>M;

    for(int i=1; i<=N; i++)
        possible.push_back(i);

    tracking(0);

    return 0;
}

void tracking(int prev){
    if(now.size() == M){
        for(int i=0;i<now.size(); i++)
            cout<<now[i]<<' ';
        cout<<'\n';
        return;
    }

    for(int i=prev; i<N; i++){
        now.push_back(possible[i]);
        tracking(i);
        now.pop_back();
    }
        
}