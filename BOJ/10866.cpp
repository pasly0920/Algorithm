#include<iostream>
using namespace std;
int deq[20002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int start=10001, end=10001;
    for(int i=0;i<N;i++)
    {
        string command;
        cin>>command;
        int n;
        if(command=="push_front")
        {
            cin>>n;
            deq[start]=n;
            start--;
        }
        else if(command=="push_back")
        {
            cin>>n;
            end++;
            deq[end]=n;
        }
        else if(command=="pop_front")
        {
            if(start==end)
                cout<<-1<<"\n";
            else 
            {
                cout<<deq[start+1]<<'\n';
                start++;
            }
        }
        else if(command=="pop_back")
        {
            if(start==end)
                cout<<-1<<"\n";
            else
            {
                cout<<deq[end]<<"\n";
                end--;
            }
        }
        else if(command=="size")
            cout<<end-start<<"\n";
        else if(command=="empty")
            if(start==end)
                cout<<1<<"\n";
            else
                cout<<0<<"\n";
        else if(command=="front")
        {
            if(start==end)
                cout<<-1<<"\n";
            else 
                cout<<deq[start+1]<<"\n";
        }
        else if(command=="back")
        {
            if(start==end)
                cout<<-1<<"\n";
            else
                cout<<deq[end]<<"\n";
        }
    }
    return 0;
}