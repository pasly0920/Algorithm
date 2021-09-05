#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L, N, rf, rb;
    cin>>L>>N>>rf>>rb;
    vector<int> rest;
    vector<int> taste;
    int temp_x, temp_y;
    for(int i=0;i<N;i++)
    {
        cin>>temp_x>>temp_y;
        rest.push_back(temp_x);//dist
        taste.push_back(temp_y);//unit
    }
    vector<int> pos_time;
    for(int i=0;i<N;i++)
        if(i==0)
            pos_time.push_back((rf-rb)*rest[i]);
        else
            pos_time.push_back((rf-rb)*(rest[i]-rest[i-1]));
    unsigned long long ans=0; 
    for(int i=0;i<pos_time.size();i++)
    {
       int summit=0;
       int max_val=-1;
       int max_idx=-1;
       long long used_time=0;
       for(int j=i;j<pos_time.size();j++)
       {
           if(taste[j]>max_val)
           {
               max_idx=j;
               max_val=taste[j];
           }
       }
       for(int j=i;j<=max_idx;j++)
            used_time+=pos_time[j];
        ans+=used_time*max_val;
        i+=(max_idx-i);
    }
    cout<<ans;
    return 0;
}