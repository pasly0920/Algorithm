#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> word;
    vector<string> alpha;
    string s;
    string part;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        word.push_back(s);
        for(int j=0;j<s.size();j++)
        {
            part=s[j];
            alpha.push_back(part);
        }
    }
    sort(alpha.begin(), alpha.end());
    alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());
    vector<pair<int,string>>pre;
    for(int i=0;i<alpha.size();i++)
    {
        string k=alpha[i];
        pre.push_back(pair<int, string>(0,k));
    }
    for(int i=0;i<word.size();i++)
    {
        string now=word[i];//현재 문자열
        for(int j=0;j<now.size();j++)
        {
            string partial=now.substr(j,1);
            for(int k=0;k<pre.size();k++)
            {
                if(pre[k].second==partial)
                    pre[k].first+=pow(10,(now.size()-(j+1)));
            }
        }
    }
    sort(pre.begin(), pre.end());
    reverse(pre.begin(), pre.end());
    int sub=9;
    int sum=0;
    for(int i=0;i<pre.size();i++)
    {
        sum+=pre[i].first*sub;
        sub--;
    }
    cout<<sum;
    return 0;
}