#include<iostream>
#include<cmath>
using namespace std;
#define PI 3.1415926535987
long double bin_search(long double st, long double ed);
long double A, B, C;
int main()
{
    cin>>A>>B>>C;
    long double min_val=(C-B)/A;
    long double max_val=(C+B)/A;
    cout.precision(15);
    cout<<bin_search(min_val, max_val);
    return 0;
}
long double bin_search(long double st, long double ed)
{
    long double mid=st/2+ed/2;
    long double val= A*mid+B*sin(mid);
    if(abs(val-C)<=pow(10, -10))
        return mid;
    else if(val>C)
        return bin_search(st, mid);
    else 
        return bin_search(mid, ed);
}