#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string A, B;
    cin>>A>>B;
    int L_A = A.size();
    int L_B = B.size();
    vector<vector<int>> LCS(L_B+1, vector<int>(L_A+1, 0));
    for(int i=1;i<=L_B;i++)
        for(int j=1;j<=L_A;j++)
            if(A[j-1]==B[i-1])
                LCS[i][j]=LCS[i-1][j-1]+1;
            else    
                LCS[i][j]=max(LCS[i-1][j], LCS[i][j-1]);
    cout<<LCS[L_B][L_A];
    return 0;
}