#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<vector<string>> member(201);
    int N;
    cin>>N;
    int age;
    string name;
    for(int i=0;i<N;i++)
    {
        cin>>age>>name;
        member[age].push_back(name);
    }
    for(int i=0;i<=200;i++)
    {
        for(int j=0;j<member[i].size();j++)
            cout<<i<<" "<<member[i][j]<<'\n';
    }
    return 0;
}