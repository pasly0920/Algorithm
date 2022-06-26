#include<iostream>
#include<cmath>
using namespace std;
static int result=0;
void Z_stream(int n, int x, int y, int tar_x, int tar_y);
int main()
{
    int N, r, c;
    cin>>N>>r>>c;
    int n=(int)(pow(2,N));
    Z_stream(n, 0, 0, c, r);
    cout<<result;
}
void Z_stream(int n, int x, int y, int tar_x, int tar_y)
{
    if(n==0)
        return;
    else
    {
        int space=n/2;
        //1
        if((tar_y>=y)&&(tar_y<y+space))
            if((tar_x>=x)&&(tar_x<x+space))
            {
                result+=(space*space)*0;
                Z_stream(space, x, y, tar_x, tar_y);
            }
        
        //2
        x+=space;
        if((tar_y>=y)&&(tar_y<y+space))
            if((tar_x>=x)&&(tar_x<x+space))
            {
                result+=(space*space)*1;
                Z_stream(space, x, y, tar_x, tar_y);
            }
        //3
        x-=space;
        y+=space;
        if((tar_y>=y)&&(tar_y<y+space))
            if((tar_x>=x)&&(tar_x<x+space))
            {
                result+=(space*space)*2;
                Z_stream(space, x, y, tar_x, tar_y);
            }
        //4
        x+=space;
        if((tar_y>=y)&&(tar_y<y+space))
            if((tar_x>=x)&&(tar_x<x+space))
            {
                result+=(space*space)*3;
                Z_stream(space, x, y, tar_x, tar_y);
            }
    }
}