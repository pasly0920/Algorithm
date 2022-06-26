#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
unsigned long long total_bud;
unsigned long long make_sum(vector<int> &want, int h);
int bin_search(vector<int> &want, int st, int ed); 
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;
    int temp;
    vector<int> want;
    int sum, max;
    sum=max=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        sum+=temp;
        if(max<temp)
            max=temp;
        want.push_back(temp);
    }
    cin>>total_bud;
    if(sum<total_bud)
    {
        cout<<max;
        return 0;
    }
    cout<<bin_search(want, 1, max);
    return 0;
}
unsigned long long make_sum(vector<int> &want, int h)
{
    unsigned long long summit=0;
    for(int i=0;i<want.size();i++)
    {
        if(want[i]>=h)
            summit+=h;
        else
            summit+=want[i];
    }
    return summit;
}
int bin_search(vector<int> &want, int st, int ed)
{
    if(st>ed)
    {
        if(make_sum(want, st)>total_bud)
        {
            while(1)
            {
                if(make_sum(want,st)<total_bud)
                    break;
                st--;
            }
            return st;
        }
        if(make_sum(want, st)<total_bud)
        {
            while(1)
            {
                if(make_sum(want,st)>total_bud)
                    break;
                st++;
            }
            return st-1;
        }
    }
    int mid=(st+ed)/2;
    //cout<<mid<<endl;
    if(make_sum(want, mid)==total_bud)
    {
        while(1)
        {
            if(make_sum(want, mid)!=total_bud)
                break;
            mid++;
        }
        return mid-1;
    }
    if(make_sum(want, mid)>total_bud)
        bin_search(want, st, mid-1);
    else
        bin_search(want, mid+1, ed);
}