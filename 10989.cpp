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
    vector<int> arr;
    arr.assign(10001, 0);
    int temp;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        arr[temp]+=1;
    }
    for(int i=1;i<=10000;i++)
    {
        for(int j=0;j<arr[i];j++)
            cout<<i<<'\n';
    }
    return 0;
}