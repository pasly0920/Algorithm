#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s;
    int N;
    cin>>N;
    vector<vector<string>> word(51);
    for(int i=0;i<N;i++)
    {
        cin>>s;
        word[s.size()].push_back(s);
    }
    for(int i=1;i<=50;i++)
    {
        if(word[i].size()!=0)
        {
            sort(word[i].begin(), word[i].end());
            for(int j=0;j<word[i].size();j++)
            {
                if(j!=0)
                    if(word[i][j]==word[i][j-1])
                        continue;
                cout<<word[i][j]<<'\n';
            }
        }
    }
    return 0;
}