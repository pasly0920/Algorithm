#include<iostream>
#include<deque>
using namespace std;
int result_2=0, result_3=0;
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    deque<int> cir;
    for(int i=1;i<=N;i++)
        cir.push_back(i);
    int n;
    deque<int> cand;
    for(int i=0;i<M;i++)
    {
        scanf("%d", &n);
        cand.push_back(n);
    }
    int target;
    int temp;
    int dist_2, dist_3;
    for(int i=0;i<M;i++)
    {
        target=cand.front();
        for(int i=0;i<N;i++)
        {
            if(cir[i]==target)
            {
                dist_2=i;
                dist_3=cir.size()-dist_2;
                break;
            }
        }
        if(dist_2<=dist_3)
        {
            for(int i=0;i<dist_2;i++)
            {
                temp=cir.front();
                cir.pop_front();
                cir.push_back(temp);
                result_2++;
            }
            if(cir.front()==target)
            {
                cand.pop_front();
                cir.pop_front();
            }
            else
                printf("err_1");
        }
        else
        {
            for(int i=0;i<dist_3;i++)
            {
                temp=cir.back();
                cir.pop_back();
                cir.push_front(temp);
                result_3++;
            }
            if(cir.front()==target)
            {
                cand.pop_front();
                cir.pop_front();
            }
            else
                printf("err_2");
        }
    }
    printf("%d", result_2+result_3);
    return 0;
}