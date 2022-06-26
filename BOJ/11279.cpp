#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void heap_push(vector<int> &heap_arr, int X);
int heap_pop(vector<int> &heap_arr);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> heap_arr;
    heap_arr.push_back(0);
    int N;
    cin>>N;
    int X;
    for(int i=0;i<N;i++)
    {
        cin>>X;
        if(X==0)
            if(heap_arr.size()==1)
                cout<<0<<'\n';
            else
                cout<<heap_pop(heap_arr)<<'\n';
        else 
            heap_push(heap_arr, X);
    }
    return 0;
}
void heap_push(vector<int> &heap_arr, int X)
{
    heap_arr.push_back(X);
    int now_index=heap_arr.size()-1;
    if(now_index==1)
        return;
    else
    {
        while(1)
        {
            int parent=now_index/2;
            if(parent==0)
                break;
            if(heap_arr[parent]<heap_arr[now_index])
                swap(heap_arr[parent], heap_arr[now_index]);
            else
                break;
            now_index=parent;
        }
        return;
    }
}
int heap_pop(vector<int> &heap_arr)
{
    if(heap_arr.size()==1)
        return 0;
    int max_val=heap_arr[1];
    int min_val=heap_arr.back();
    heap_arr.pop_back();
    heap_arr[1]=min_val;
    int now_index=1;
    while(1)
    {
        int left_index=now_index*2;
        int right_index=now_index*2+1;
        if(left_index>=heap_arr.size())
            break;
        int max_value=max({heap_arr[now_index], heap_arr[left_index], heap_arr[right_index]});
        if(max_value==heap_arr[now_index])
            break;
        else if(max_value==heap_arr[left_index])
        {
            swap(heap_arr[now_index], heap_arr[left_index]);
            now_index=left_index;
        }
        else
        {
            swap(heap_arr[now_index], heap_arr[right_index]);
            now_index=right_index;
        }
    }
    return max_val;
}