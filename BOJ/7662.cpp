#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int K;
        cin>>K;
        multiset<int> arr;
        for(int j=0;j<K;j++)
        {
            char command;
            int num;
            cin>>command>>num;
            if(command=='I')
                arr.insert(num);
            else
            {
                if(num==-1)
                    if(!arr.empty())
                        arr.erase(arr.begin());
                if(num==1)
                    if(!arr.empty())
                        arr.erase(--arr.end());
            }
        } 
        if(arr.empty())
            cout<<"EMPTY"<<'\n';
        else 
            cout<<*(--arr.end())<<" "<<*arr.begin()<<'\n';
    }
    return 0;
}