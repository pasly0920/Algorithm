#include<iostream>
#include<stack>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long summit=0;
    int K;
    cin>>K;
    int now;
    stack<int> arr;
    for(int i=0;i<K;i++)
    {
        cin>>now;
        if(now==0)
        {
            summit-=arr.top();
            arr.pop();
        }
        else
        {
            arr.push(now);
            summit+=now;
        }
    }
    cout<<summit;
    return 0;
}