#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int n;
    vector<int> value;
    string s;
    cin>>s;
    for(int i=0;i<N;i++)
    {
        cin>>n;
        value.push_back(n);
    }
    stack<double> cal;
    double a, b;
    for(int i=0;i<s.size();i++)
    {
        if((int)s[i]>=65)
        {
            cal.push((double)value[(int)s[i]-65]);
        }
        else
        {
            a=cal.top();
            cal.pop();
            b=cal.top();
            cal.pop();
            if((char)s[i]=='+')
                cal.push(a+b);
            else if((char)s[i]=='-')
                cal.push(b-a);
            else if((char)s[i]=='*')
                cal.push(a*b);
            else if((char)s[i]=='/')\
                cal.push(b/a);
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<cal.top();
    return 0;
}