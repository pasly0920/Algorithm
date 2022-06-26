#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        int n, target;
        scanf("%d %d", &n, &target);
        vector<int> max;
        queue<pair<int, int>> printer;
        for(int i=0;i<n;i++)
        {
            pair<int, int> temp;
            int q;
            scanf("%d", &q);
            temp.first=i;
            temp.second=q;
            printer.push(temp);
            max.push_back(q);// input complete
        }
        sort(max.begin(), max.end());//max sorting
        int result=0;
        while(1)//make result
        {
            pair<int, int> temp;
            int max_val=max.back();
            if((printer.front()).second>=max_val)
            {
                result++;
                if((printer.front()).first==target)
                {
                    break;
                }
                printer.pop();
                max.pop_back();
            }
            else
            {
                temp.first=(printer.front()).first;
                temp.second=(printer.front()).second;
                printer.pop();
                printer.push(temp);
            }
        }
        printf("%d\n", result);
        max.clear();
        printer=queue<pair<int, int>>();
    }
}