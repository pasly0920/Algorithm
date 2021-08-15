#include<iostream>
using namespace std;
int index[100001];
int inorder[100001];
int postorder[100001];
void pre_order(int instart, int inend, int poststart, int postend);
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>inorder[i];
        index[inorder[i]]=i;
    }
    for(int i=1;i<=N;i++)
        cin>>postorder[i];
    pre_order(1, N, 1, N);
    return 0;
}
void pre_order(int instart, int inend, int poststart, int postend)
{
    if(instart>inend||poststart>postend)
        return;
    int rootindex= index[postorder[postend]];
    int leftsize=rootindex-instart;
    int rightsize=inend-rootindex;
    cout<<inorder[rootindex]<<' ';
    pre_order(instart, rootindex-1, poststart, poststart+leftsize-1);
    pre_order(rootindex+1, inend, poststart+leftsize, postend-1);
}