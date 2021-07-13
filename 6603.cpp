#include<iostream>
#include<list>
using namespace std;
list<int> buff;
void Lotto(list<int> cand, int count);
int main()
{
    while(1)
    {
        int K;
        list<int> cand;
        cin>>K;
        if(K==0)
            break;
        int can;
        for(int i=0;i<K;i++)
        {
            cin>>can;
            cand.push_back(can);
        }
        Lotto(cand, 6);
        cout<<endl;
    }
    return 0;
}
void Lotto(list<int> cand, int count)
{
    if(count==0)
    {
        list<int>::iterator it;
        for(it=buff.begin();it!=buff.end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    else if(cand.size()==0)
        return;
    else
    {
        //이 원소를 포함하는 경우
        int front=cand.front();
        buff.push_back(front);
        cand.pop_front();
        Lotto(cand, count-1);
        //이 원소를 포함하지 않는 경우
        buff.pop_back();
        Lotto(cand, count);
        cand.push_front(front);
    }
}