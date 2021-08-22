#include<iostream>
using namespace std;
int main()
{
    int a, b;
    cin>>a>>b;
    int A=a;
    int B=b;
    while(1)
    {
        int C=A%B;
        if(C==0)
        {
            cout<<B<<'\n';
            break;
        }
        else
        {
            A=B;
            B=C;
        }
    }
    cout<<a*b/B;
    return 0;
}