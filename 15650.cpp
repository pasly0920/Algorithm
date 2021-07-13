#include<iostream>
#include<list>
using namespace std;
void comb(int M, list<int>ran);
int main()
{
    int N;
    int M;
    cin>>N>>M;
    list<int>range;
    for(int i=1;i<=N;i++)
        range.push_back(i);
    comb(M, range);
    return 0;
}
void comb(int M, list<int>ran)
{
    static list<int> buffer;
    if(M==0)
    {
        list<int>::iterator iter;
        for(iter=buffer.begin();iter!=buffer.end();iter++)
            cout<<*iter<<" ";
        cout<<"\n";
        return;
    }
    else if(ran.size()==0)
        return;
    else
    {
        int front=ran.front();
        buffer.push_back(front);
        ran.pop_front();
        comb(M-1, ran);
        buffer.pop_back();
        comb(M, ran);
        ran.push_front(front);
    }
    
}