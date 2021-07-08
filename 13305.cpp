#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<long long> D;
    long long d;
    for(int i=0;i<N-1;i++)
    {
        cin>>d;
        D.push_back(d);
    }
    vector<long long> P;
    long long price;
    for(int i=0;i<N;i++)
    {
        cin>>price;
        P.push_back(price);
    }
    long long prev_p=P[0];
    long long price_sum=prev_p*D[0];
    for(int i=1;i<N-1;i++)
    {
        if(P[i]<prev_p)
            prev_p=P[i];
        price_sum+=prev_p*D[i];
    }
    cout<<price_sum;
    return 0;
}