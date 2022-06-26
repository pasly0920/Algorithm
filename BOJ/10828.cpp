#include<iostream>
#include<string>
using namespace std;
int stack[10000];
int main()
{
    int N;
    scanf("%d", &N);
    string command;
    int count=0;
    for(int i=0;i<N;i++)
    {
        cin>>command;
        int num;
        if(command=="push")
        {
            scanf("%d", &num);
            stack[count]=num;
            count++;
        }
        else if(command=="pop")
        {
            if(count==0)
                printf("%d\n", -1);
            else
            {
                printf("%d\n", stack[count-1]);
                count--;
            }
        }
        else if(command=="size")
        {
            printf("%d\n", count);
        }
        else if(command=="empty")
        {
            if(count==0)
                printf("%d\n", 1);
            else   
                printf("%d\n", 0);
        }
        else if(command=="top")
        {
            if(count==0)
                printf("%d\n", -1);
            else  
                printf("%d\n", stack[count-1]);
        }
    }
    return 0;
}