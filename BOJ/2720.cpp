#include<iostream>
using namespace std;
int main()
{
    int T,C;
    int q, d, n, p;
    cin>>T;
    for(int i=0; i<T;i++)
    {
        cin>>C;
        q=C/25;
        C-=25*q;
        d=C/10;
        C-=10*d;
        n=C/5;
        C-=5*n;
        p=C;
        cout<<q<<" "<<d<<" "<<n<<" "<<p<<endl;
    }
    return 0;
}