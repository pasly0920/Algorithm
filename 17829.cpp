#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[1024][1024];
vector<int> temp;
vector<int> test;
void pulling(int arr[1024][1024],int N);
void second(int arr[1024][1024], int x, int y);
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d", &arr[i][j]);
    pulling(arr, N);
    return 0;
}
void pulling(int arr[1024][1024],int N)
{
    if(N==1)
    {
        printf("%d", arr[0][0]);
        return;
    }
    else
    {
        for(int y=0;y<N;y+=2)
            for(int x=0;x<N;x+=2)
                second(arr, x, y);
        int i=0;
        for(int y=0;y<(N/2);y++)
        {
            for(int x=0;x<(N/2);x++)
            {
                arr[y][x]=temp[i];
                i++;
            }
        }
        temp.clear();
        pulling(arr, N/2);
    }
}
void second(int arr[1024][1024], int x, int y)
{
    for(int i=y;i<y+2;i++)
        for(int j=x;j<x+2;j++)
            test.push_back(arr[i][j]);
    sort(test.begin(), test.end());
    int k=test[2];
    temp.push_back(k);
    test.clear();
}