#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int N;
    cin>> N;

    vector<int> X(N);
    vector<int> XSort;
    vector<int> res(N);
    for(int i = 0; i<N; i++)
        cin>>X[i];
    XSort = X;
    sort(XSort.begin(), XSort.end());
    XSort.erase(unique(XSort.begin(), XSort.end()), XSort.end());
    for(int i = 0; i < N; i++)
        res[i] = lower_bound(XSort.begin(), XSort.end(), X[i]) - XSort.begin();
    for(int i = 0; i< N; i++)
        cout<<res[i]<< " ";
    return 0;
}