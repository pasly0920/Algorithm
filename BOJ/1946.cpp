#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    vector<pair<int, int>> cand;
    for(int i=0;i<T;i++)
    {
        int N;
        cin>>N;
        int a, b;
        for(int j=0;j<N;j++)
        {
            cin>>a>>b;
            cand.push_back(pair<int, int>(a, b));
        }
        sort(cand.begin(), cand.end());
        int pass=1;
        int prev_min=cand[0].second;
        for(int j=1;j<N;j++)
        {
            if(cand[j].second<prev_min)
            {
                prev_min=cand[j].second;
                pass++;
            }
            else   
                continue;
        }
        cout<<pass<<endl;
        cand.clear();
        vector<pair<int, int>>().swap(cand);
    }
    return 0;
}