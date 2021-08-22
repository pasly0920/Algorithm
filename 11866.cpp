#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int N, K;
    cin>>N>>K;
    vector<bool> table;
    table.assign(N+1, false);
    table[0]=true;
    vector<int> deleted;
    int now_index=1;
    while(1)
    {
        for(int i=0;i<K-1;i++)
        {
            if(now_index==N)
            {
                if(table[1]==false)
                    now_index=1;
                else
                {
                    now_index=1;
                    i--;
                }
            } 
            else if(table[now_index+1]==false)
                now_index++;
            else
            {
                now_index++;
                i--;
            }
        }
        deleted.push_back(now_index);
        table[now_index]=true;
        if(deleted.size()==N)
            break;
        while(1)
        {
            if(now_index>N)
                now_index=1;
            if(table[now_index]==false)
                break;
            else
                now_index++;
        }
    }
    cout<<'<';
    for(int i=0;i<N-1;i++)
        cout<<deleted[i]<<", ";
    cout<<deleted[N-1]<<'>';
    return 0;
}