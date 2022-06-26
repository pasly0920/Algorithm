#include<iostream>
#include<queue>
#include<string>
using namespace std;
queue<int> test;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    string command;
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>command;
        if(command=="push")
        {
            cin>>n;
            test.push(n);
        }
        else if(command=="pop")
        {
            if(test.empty())
                cout<<-1<<"\n";
            else 
            {
                cout<<test.front()<<"\n";
                test.pop();
            }
        }
        else if(command=="size")
            cout<<test.size()<<"\n";
        else if(command=="empty")
            cout<<test.empty()<<"\n";
        else if(command=="front")
        {
            if(test.empty())
                cout<<-1<<"\n";
            else
                cout<<test.front()<<"\n";
        }
        else if(command=="back")
        {
            if(test.empty())
                cout<<-1<<"\n";
            else
                cout<<test.back()<<"\n";
        }
    }
    return 0;
}