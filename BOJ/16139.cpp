#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    cin>>S;

    vector<vector<int>> fr;
    fr.assign(S.length(), vector<int> (26, 0));
    
    int temp;
    for(int i=0; i<S.length(); i++){
        temp = S[i] - 'a';
        for(int j=0; j<26; j++){
            if(j == temp)
                fr[i][j] = (i == 0) ? 1 : fr[i-1][j] + 1;
            else
                fr[i][j] = (i == 0) ? 0 : fr[i-1][j];
        }
    }

    int q;
    cin>> q;

    char temp_ch;
    int left, right;
    for(int i=0; i<q; i++){
        cin>>temp_ch>>left>>right;
        temp = temp_ch - 'a';
        int right_val = fr[right][temp];
        int left_val = (left == 0) ? 0 : fr[left - 1][temp];
        cout<<right_val - left_val<<'\n';
    }
    return 0;
}