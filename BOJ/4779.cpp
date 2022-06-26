#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void canto(int N, vector<int>& cant, int start);
int main()
{
    int N;
    while(1)
    {
        static vector<int> cant;
        cant.clear();
        cin>>N;
        if(cin.eof()==true)
            break;
        for(int i=0;i<=(int)(pow(3,N));i++)
            cant.push_back(0);
        if((N==0)||(N==1))
        {
            if(N==0)
                cout<<"-"<<endl;
            else 
                cout<<"- -"<<endl;
        }
        else
        {
            canto(N, cant, 0);
            for(int i=1;i<cant.size();i++)
            {
                if(cant[i]==N)
                    cout<<"-";
                else   
                    cout<<" ";
            }
            cout<<endl;
        }
    }
}
void canto(int N, vector<int>& cant, int start)
{
    if(N==0)
        return;
    else
    {   
       //앞의 부분
        int val=(int)(pow(3,N-1));
        for(int i=start+1;i<=start+val;i++)
            cant[i]+=1;
        canto(N-1, cant, start);
        //뒤의 부분
        start+=val*2;
        for(int i=start+1;i<=start+val;i++)
            cant[i]+=1;
        canto(N-1, cant, start);
    }
}