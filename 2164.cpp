#include<iostream>
#include<deque>
using namespace std;
int main()
{
    int N;
    cin>>N;
    deque<int> card;
    for(int i=1;i<=N;i++)
        card.push_back(i);
    while(1)
    {
        if(card.size()==1)
            break;
        card.pop_front();
        if(card.size()==1)
            break;
        int temp=card.front();
        card.pop_front();
        card.push_back(temp);
    }
    cout<<card.front();
    return 0;
}