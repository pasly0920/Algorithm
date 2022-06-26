#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void permutation(int M, int start);
void print_permutation();

vector<int> num;
vector<int> temp;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;
    
    for(int i=1; i<=N; i++)
        num.push_back(i);
    
    do{
        for(int i=0; i< M; i++)
            cout<<num[i]<<" ";
        cout<<'\n';

        reverse(num.begin() + M, num.end());
    }while(next_permutation(num.begin(), num.end()));

    return 0;
}
