#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string res="";
    int st=0;
    int df=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='.')
        {
            res+='.';
            continue;
        }        
        for(int j=i;j<s.size();j++)
        {
            if(s[j]=='X')
            {
                df++;
                st++;
            }  
            if(s[j]=='.')
                break;
        }
        while(1)
        {
            if(st%2==1)
            {
                cout<<-1;
                return 0;
            }
            if(st==0)
                break;
            if(st>=4)
            {
                res+="AAAA";
                st-=4;
            }
            else if(st<4)
            {
                if(st==2)
                {
                    res+="BB";
                    st-=2;
                }   
            }
        }
        i+=df-1;
        df=0;
    }
    cout<<res;
    return 0;
}