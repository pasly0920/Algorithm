#include<iostream>
#include<algorithm>
using namespace std;
int biggest(char board[][15], int i, int j, int M, int N);
int main()
{
    int M, N;
    char board[15][15];
    char board_fixed[15][15];
    int max=0;//답안
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>board[i][j];
        }
    }
    int first_max;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            first_max=biggest(board, i, j, M, N);
            if(first_max<0)
                continue;
            for(int k=0;k<first_max;k++)
            {   
                for(int c=0;c<M;c++) 
                {
                    for(int v=0;v<N;v++)
                    {
                        board_fixed[c][v]=board[c][v];
                    }
                }
                for(int l=0;l<=k;l++)
                {
                    board_fixed[i-l][j]=='.';
                    board_fixed[i+l][j]=='.';
                    board_fixed[i][j-l]=='.';
                    board_fixed[i][j+l]=='.';
                }//board_fixed 생성 
                for(int z=0;z<M;z++)
                {
                    for(int x=0;x<N;x++)
                    {
                        int second_max=biggest(board_fixed, z, x, M, N);
                        if(((4*first_max+1)*(4*second_max+1))>max)
                            max=(4*first_max+1)*(4*second_max+1);
                    }
                }
            }
        }
    }
    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout<<biggest(board, i, j, M, N)<<" ";
        }
        cout<<endl;
    }*/
    cout<<max;
    return 0;
}
int biggest(char board[][15], int i, int j, int M, int N)//가능한 가장 큰 십자가의 크기를 알려줌 
{
    int d=0;
    if(board[i][j]=='.')
        return -1;
    for(d=0;;d++)
    {
        if((i+2<d)||(j+2<d))
            break;
        if(((i+d)>M-1)||((j+d)>N-1))
            break;
        if((board[i-d][j]=='#')&&(board[i+d][j]=='#')&&(board[i][j-d]=='#')&&(board[i][j+d]=='#'))
            continue;
        else
        {
            break;
        }
    }
    if(d!=0)
        d--;
    return d;
}