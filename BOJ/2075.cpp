#include<iostream>
#include<set>
#include<cmath>
using namespace std;
int N;
set<int, greater<int>> num;
void sol(int element);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int temp;
    if(N==1)
    {
        cin>>temp;
        cout<<temp;
        return 0;
    }
    for(int i=0;i<N^2;i++)
    {
        if(i==(N*N-1))
            break;
        cin>>temp;
        sol(temp);
    }
    cin>>temp;
    if(*(--num.end())<temp){
        num.insert(temp);
        if(num.size()>=N)
            num.erase(*(--num.end()));
    }
    cout<<*(--num.end());
    return 0;
}
void sol(int element)
{
    if(num.size()<N)
        num.insert(element);
    else
    {
        num.insert(element);
        num.erase(--num.end());
    }
}