#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
vector<bool> visited(1025);
vector<bool> print(1025);
vector<int> binary(1025);
queue<int> order;
void mid_search(int now, int max_level, int level);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int K;
    cin>>K;
    int temp;
    int num=(int)pow(2,K);  
    vector<int> arr(1025);//origin  
    for(int i=1;i<num;i++)
    {
        cin>>temp;
        arr[i]=temp;
    }
    visited.assign(1025, false);
    print.assign(1025, false);
    mid_search(1, K, 1);
    for(int i=1;i<num;i++)
    {
        //cout<<order.front()<<" "<<arr[i]<<endl;
        binary[order.front()]=arr[i];
        order.pop(); 
    }
    for(int i=1;i<num;i*=2)
    {
        for(int j=i;j<i*2;j++)
            cout<<binary[j]<<" ";
        cout<<'\n';
    }
    return 0;
}
void mid_search(int now, int max_level, int level)
{
    if(visited[now]==true)
        return;
    if(now>=(int)(pow(2,max_level)))    
        return;
    visited[now]=true;
    for(int i=0;i<2;i++)
    {
        if((level==max_level)||(visited[now*2]==true))
        {
            if(print[now]!=true)
            {
                print[now]=true;
                order.push(now);
            }
        }
        mid_search(now*2+i, max_level, level+1);
    }
}
