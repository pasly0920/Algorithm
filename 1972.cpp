#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool solve(string S);
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string S;
    while (1)
    {
        cin>>S;
        if(S=="*")
            return 0;
        else
            if(S.size()==1)
                cout<<S<<" is surprising.\n";
            else if(solve(S))
                cout<<S<<" is surprising.\n";
            else
                cout<<S<<" is NOT surprising.\n";
    }
    
}
bool solve(string S)
{
    for(int D=0;D<=S.size()-2;D++)
    {
        vector<string> temp;
        bool ans=true;
        //temp 채우고
        for(int i=0;i<(S.size()-D-1);i++)
        {
            string a=S.substr(i, 1);
            string b=S.substr(i+D+1, 1);
            string sub=a+b;
            //cout<<sub<<'\n';
            temp.push_back(sub);
        }
        //sort 후 중복 판별
        sort(temp.begin(), temp.end());
        for(int i=0;i<temp.size()-1;i++)
            if(temp[i]==temp[i+1])
                ans=false;
        //bool 값 정하고 false일시 false return
        if(ans==false)
            return false;
    }
    return true;
}