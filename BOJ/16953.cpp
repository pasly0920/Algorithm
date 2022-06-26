#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

long long A, B;
int main(){
    cin>>A>>B;

    queue<pair<long long, long long>> q;
    q.push(make_pair(A, 0));
    while(!q.empty()){
        long long now = q.front().first;
        long long nowDistance = q.front().second;
        if(now == B){
            cout<<nowDistance + 1;
            return 0;
        }

        q.pop();
        long long next1 = now * 2;
        long long next2 = now * 10 + 1;

        if(next1 <= B && next1 <= 1000000000)
            q.push(make_pair(next1, nowDistance + 1));
        if(next2 <= B && next2 <= 1000000000)
            q.push(make_pair(next2, nowDistance + 1));
    }
    
    cout<<-1;
    return 0;
}