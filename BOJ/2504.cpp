#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
vector<int>result_arr;
vector<int>temp;
int result=0;
int main()
{
    string ex;
    cin>>ex;
    char ch;
    stack<char> test_1;
    stack<char> test_2;
    stack<char> test_3;
    for(int i=0;i<ex.size();i++)
    {
        ch=(char)ex[i];
        if((ch=='('))
            test_1.push(ch);
        else if((ch=='['))
            test_2.push(ch);
        else
        {
            if(ch==')')
            {
                if(test_1.empty())
                {
                    cout<<0;
                    return 0;
                }
                else
                    test_1.pop();
            }
            if(ch==']')
            {
                if(test_2.empty())
                {
                    cout<<0;
                    return 0;
                }
                else
                    test_2.pop();
            }
        }
    }
    if(!(test_1.empty()))
    {
        cout<<0;
        return 0;
    }
    if(!(test_2.empty()))
    {
        cout<<0;
        return 0;
    }
    int temp=1;
    //값 판단
    for(int i=0;i<ex.size();i++)
    {
        ch=(char)ex[i];
        if(test_3.empty())
        {
            result_arr.push_back(result);
            result=0;
        }
        if(ch=='(')
        {
            test_3.push(ch);
            temp*=2;
        }
        else if(ch=='[')
        {
            test_3.push(ch);
            temp*=3;
        }
        else if(ch==')')
        {
            if(ex[i-1]=='(')
                result+=temp;
            test_3.pop();
            temp/=2;
        }
        else if(ch==']')
        {
            if(ex[i-1]=='[')
                result+=temp;
            test_3.pop();
            temp/=3;
        }
    }
    if(result!=0)
        result_arr.push_back(result);
    int sum=0;
    for(int i=0;i<result_arr.size();i++)
        sum+=result_arr[i];
    cout<<sum;
    return 0;
}   