#include<iostream>
using namespace std;
int horizon(int go[][19], int i, int j);
int vertical(int go[][19], int i, int j);
int diagonal(int go[][19], int i, int j);
int diagonal_l(int go[][19], int i, int j);
int main()
{
    int go[19][19];
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            cin>>go[i][j];
        }
    }
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            /*cout<<i<<" "<<j<<endl;
            cout<<horizon(go, i, j)<<" "<<vertical(go, i, j)<<" "<<diagonal(go, i, j)<<endl;*/
            if(horizon(go, i, j)!=0)
            {
                cout<<horizon(go, i, j)<<endl;
                cout<<i+1<<" "<<j+1;
                return 0;
            }
            if(vertical(go, i, j)!=0)
            {
                cout<<vertical(go, i, j)<<endl;
                cout<<i+1<<" "<<j+1;
                return 0;
            }
            if(diagonal(go, i, j)!=0)
            {
                cout<<diagonal(go, i, j)<<endl;
                cout<<i+1<<" "<<j+1;
                return 0;
            }
            if(diagonal_l(go, i, j)!=0)
            {
                cout<<diagonal_l(go, i, j)<<endl;
                cout<<i+1<<" "<<j+1;
                return 0;
            }
        }
    }
    cout<<0;
    return 0;
}
int horizon(int go[][19], int i, int j)
{
    int dx=1, dy=0;
    int x, y;
    int continual=1;
    int init_color=0;
    if(go[i][j]==0)
        return 0;
    if(j>0)
    {
        if(go[i][j]==go[i-dy][j-dx])
        return 0;
    }
    init_color=go[i][j];
    x=j;
    y=i;
    for(int k=0;k<5;k++)
    {   
        x+=dx;
        y+=dy;
        if((x>=19)||(y>=19))
            break;
        if(go[y][x]==0)
            break;
        if(go[y][x]==init_color)
            continual++;
        else
            break;
    }
    if(continual==5)
        return init_color;
    else 
        return 0;
}
int vertical(int go[][19], int i, int j)
{
    int dx=0, dy=1;
    int x, y;
    int continual=1;
    int init_color=0;
    if(go[i][j]==0)
        return 0;
    if(i>0)
    {
        if(go[i][j]==go[i-dy][j-dx])
        return 0;
    }
    init_color=go[i][j];
    x=j;
    y=i;
    for(int k=0;k<5;k++)
    {   
        x+=dx;
        y+=dy;
        if((x>=19)||(y>=19))
            break;
        if(go[y][x]==0)
            break;
        if(go[y][x]==init_color)
            continual++;
        else
            break;
    }
    if(continual==5)
        return init_color;
    else 
        return 0;
}
int diagonal(int go[][19], int i, int j)
{
    int dx=1, dy=1;
    int x, y;
    int continual=1;
    int init_color=0;
    if(go[i][j]==0)
        return 0;
    if((i>0)&&(j>0))
    {
        if(go[i][j]==go[i-dy][j-dx])
        return 0;
    }
    init_color=go[i][j];
    x=j;
    y=i;
    for(int k=0;k<5;k++)
    {   
        x+=dx;
        y+=dy;
        if((x>=19)||(y>=19))
            break;
        if(go[y][x]==0)
            break;
        if(go[y][x]==init_color)
            continual++;
        else
            break;
    }
    if(continual==5)
        return init_color;
    else   
        return 0;
}
int diagonal_l(int go[][19], int i, int j)
{
    int dx=1, dy=-1;
    int x, y;
    int continual=1;
    int init_color=0;
    if(go[i][j]==0)
        return 0;
    if(j>0)
    {
        if(go[i][j]==go[i-dy][j-dx])
        return 0;
    }
    init_color=go[i][j];
    x=j;
    y=i;
    for(int k=0;k<5;k++)
    {   
        x+=dx;
        y+=dy;
        if((x>=19)||(y>=19))
            break;
        if(x<0)
            break;
        if(go[y][x]==0)
            break;
        if(go[y][x]==init_color)
            continual++;
        else
            break;
    }
    if(continual==5)
        return init_color;
    else   
        return 0;
}