#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> coin(100);
int making[100001];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int temp;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &coin[i]);
        making[coin[i]]=1;
    }
    sort(coin.begin(), coin.begin()+n);
    if(coin.front()>k)
    {
        printf("-1");
        return 0;
    }
    for(int i=coin.front();i<=k;i++)
    {
        if(making[i]==1)
            continue;
        for(int j=0;j<coin.size();j++)
        {
            if(coin[j]>i)
                break;
            if(making[i-coin[j]]==0)
                continue;
            if(making[i]==0)
            {
                making[i]=making[i-coin[j]]+1;
                continue;
            }
            making[i]=min(making[i], making[i-coin[j]]+1);
        }
    }
    if(making[k]==0)
        printf("-1");
    else 
        printf("%d", making[k]);
    return 0;
}