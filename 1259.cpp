#include<iostream>
#include<string>
using namespace std;
int main()
{
    while(1)
    {
        string num;
        cin>>num;
        if(num=="0")
            break;
        if(num.size()==1)
            cout<<"yes"<<'\n';
        else if(num.size()==2)
            if(num[0]==num[1])
                cout<<"yes"<<'\n';
            else
                cout<<"no"<<'\n';
        else if(num.size()==3)
            if(num[0]==num[2])
                cout<<"yes"<<'\n';
            else
                cout<<"no"<<'\n';
        else if(num.size()==4)
            if((num[0]==num[3])&&(num[1]==num[2]))
                cout<<"yes"<<'\n';
            else
                cout<<"no"<<'\n';
        else if(num.size()==5)
            if((num[0]==num[4])&&(num[1]==num[3]))
                cout<<"yes"<<'\n';
            else
                cout<<"no"<<'\n';
        else 
            cout<<"err"<<endl;
    }
    return 0;
}