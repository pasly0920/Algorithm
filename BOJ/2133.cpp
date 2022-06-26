#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    vector<int> tile(31);
    tile[0]=1;
    tile[1]=0;
    for(int i=2;i<=N;i++)
    {
        tile[i]=tile[i-2]*3;
        if(i>=4)
        {
            for(int j=i-4;j>=0;j-=2)
                tile[i]+=2*tile[j];
        }
    }
    printf("%d", tile[N]);
    return 0;
}