#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<pair<int, int>> met;
    int met_count=0;
    int min_end;//가장 먼저 끝나는 회의의 종료 시간
    int a, b;
    for(int i=0;i<N;i++)
    {
        cin>>a>>b;
        met.push_back(pair<int, int>(b, a));//정렬을 위해 끝나는 시간을 앞으로 배치
    }
    sort(met.begin(), met.end());
    int temp;
     for(int i=0;i<N;i++)
    {
        swap(met[i].first, met[i].second);
    }
    //끝나는 시간을 기준으로 하여 정렬 완료
    min_end=met[0].second;
    met_count++;//처음은 패스
    for(int i=1;i<N;i++)
    {
        if(met[i].first>=min_end)
        {
            min_end=met[i].second;
            met_count++;
        }
        else
            continue;
    }
    cout<<met_count;
    return 0;
}