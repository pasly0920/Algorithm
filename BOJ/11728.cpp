#include<iostream>
using namespace std;
int arr_a[1000000];
int arr_b[1000000];
int main()
{
    int N, M;
    cin>>N>>M;
    int i=0, j=0;
    for(int k=0;k<N;k++)
        scanf("%d", &arr_a[k]);
    for(int k=0;k<M;k++)
        scanf("%d", &arr_b[k]);
    while(1)
    {
        if(arr_a[i]<=arr_b[j])
        {
            printf("%d ", arr_a[i]);
            i++;
        }
        else
        {
            printf("%d ", arr_b[j]);
            j++;
        }
        if(i==N)
            break;
        if(j==M)
            break;
    }
    while(j!=M)
    {
        printf("%d ", arr_b[j]);
        j++;
    }
    while(i!=N)
    {
        printf("%d ", arr_a[i]);
        i++;
    }
    return 0;
}