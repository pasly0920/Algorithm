#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;
    vector<vector<int>> board(N+1, vector<int> (N+1, 0));
    vector<vector<int>> cNum(N+1, vector<int> (N+1, 0));

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin>>board[i][j];
    //board yx
    int tempSum = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            tempSum += board[j][i];
            cNum[j][i] = cNum[j][i - 1] + tempSum;

            if(j==N)
                tempSum = 0;
        }
    }
    
    int x1, y1, x2, y2;
    for(int i=0; i<M; i++){
        cin>>y1>>x1>>y2>>x2;
        cout<<cNum[y2][x2] - cNum[y2][x1- 1] - cNum[y1 - 1][x2] + cNum[y1 - 1][x1 - 1]<<'\n';
    }
    
    return 0;
}