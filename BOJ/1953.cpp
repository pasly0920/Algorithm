#include<iostream>
#include<vector>

using namespace std;
int n;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    vector<vector<int>> hate(n + 1);

    int num, temp;
    for(int i=1; i<=n; i++){
        cin>>num;
        for(int j=0; j<num; j++){
            cin>> temp;
            hate[i].push_back(temp);
        }
    }
    vector<int> white;
    vector<int> blue;
    white.push_back(1);

    for(int i=2; i<=n; i++){
        int temp = 0;
        bool White = true;
        for(int j=0; j<white.size(); j++){
            if(temp < 0){
                White = false;
                break;
            }
            int now = white[j];
            for(int k = 0; k < hate[now].size(); k++)
                if(hate[now][k] == i)
                    temp --;
        }
        if(White)
            white.push_back(i);
        else
            blue.push_back(i);
        if(i == n && blue.size() == 0){
            white.pop_back();
            blue.push_back(i);
        }
    }
    cout<<white.size()<<'\n';
    for(int i=0; i<white.size(); i++)
        cout<<white[i]<<" ";
    cout<<'\n';
    cout<<blue.size()<<'\n';
    for(int i=0; i<blue.size(); i++)
        cout<<blue[i]<<" ";

    return 0;
}