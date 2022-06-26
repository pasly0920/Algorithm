#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int last(vector<int> vec, int i);
int main()
{
    int N;
    cin>>N;
    vector<int>W;
    int weight;
    for(int i=0;i<N;i++)
    {
        cin>>weight;
        W.push_back(weight);
    }
    sort(W.begin(), W.end());
    int sum=0;
    int making=1;
    for(int i=0;i<W.size();i++)
    {
        if(find(W.begin(), W.end(),making)!=W.end())
        {
            making++;
            sum+=W[i];
            continue;
        }
        if(W[i]<=sum)
        {
            making=sum+W[i];
            sum+=W[i];
            continue;
        }
        if(W[i]>sum)
        {
            if((sum+1)==W[i])
            {
                making=W[i]+1;
                if((i+1)==W.size())
                {
                    cout<<W[i]+1;
                    return 0;
                }
                continue;
            }
            else
            {
                cout<<sum+1;
                return 0;
            }
        }
    }
    cout<<sum+1;
    return 0;
}
   
