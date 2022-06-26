#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int n, k;
    int m, v;
    long long int sum = 0;

    pair<int,int> gem[300000];
    int bag[300000];
    priority_queue <int> pq;

    scanf("%d%d",&n, &k);
    for(int x = 0 ; x < n ; x++){
        scanf("%d%d",&m, &v);
        gem[x] = make_pair(m, v);
    }
    for(int x = 0 ; x < k ; x++){
        scanf("%d",&bag[x]);
    }

    sort(gem, gem + n);
    sort(bag, bag + k);

    int y = 0;
    for(int x = 0 ; x < k ; x++){
        for( ; y < n && gem[y].first <= bag[x]; y++){
            pq.push(gem[y].second);
        }
        
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << endl;
    return 0;
}