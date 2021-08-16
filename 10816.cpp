#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    int temp;
    vector<int> has;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        has.push_back(temp);
    }
    int M;
    cin>>M;
    vector<int> tar;
    for(int i=0;i<M;i++)
    {
        cin>>temp;
        tar.push_back(temp);
    }
    sort(has.begin(), has.end());
    vector<int> cnt;
    for(int i=0;i<M;i++)
    {
        int target=tar[i];
        cnt.push_back(upper_bound(has.begin(), has.end(), target)-lower_bound(has.begin(), has.end(), target));
    }
    for(int i=0;i<M;i++)
        cout<<cnt[i]<<" ";
    return 0;
}