#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n = -1;
    cin>> n;
    vector<int> num;
    vector<int> primeNum;
    for(int i =0; i<= 1000000; i++)
        num.push_back(i);
    for(int i =2; i<=1000000; i++){
        if(num[i] == 0)
            continue;
        for(int j= i+i; j<=1000000; j+=i){
            num[j] = 0;
        }
    }
    for(int i=2; i<=1000000;i++)
        if((i%2 == 1) && (num[i] != 0))
            primeNum.push_back(i);
    int a, b;
    while(n != 0){
        b = 0;
        for(int i = 0; primeNum[i] < n; i++){
            a = primeNum[i];
            if(binary_search(primeNum.begin(), primeNum.end(), n-a)){
                 b = n - a;
                 break;
            }
        }
        if(b == 0)
            cout<<"Goldbach's conjecture is wrong."<<'\n';
        else
            cout<< n <<" = " << a << " + "<<b<<'\n';
        cin>>n;
    }
    return 0;
}