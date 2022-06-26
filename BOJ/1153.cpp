#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N;
    cin>>N;

    vector<int> num;
    for(int i = 0; i<N; i++)
        num.push_back(i);
    for(int i = 2; i<N; i++){
        if(num[i] != 0){
            for(int j = i*2; j<N; j+=i)
                num[j] = 0;
        }
    }
    vector<int> primeNum;
    for(int i = 2; i<N; i++)
        if(num[i] != 0)
            primeNum.push_back(i);
    //N-1 범위까지 소수 구하기 끝

    for(int i= 0; i< primeNum.size(); i++){
        for(int j = i; j<primeNum.size(); j++){
            for(int k= j; k<primeNum.size(); k++){
                for(int l = k; l < primeNum.size(); l++){
                    int sum = primeNum[i] + primeNum[j] + primeNum[k] + primeNum[l];
                    if(sum < N)
                        continue;
                    else if(sum == N){
                        cout<< primeNum[i]<<" "<< primeNum[j]<<" "<<primeNum[k]<<" "<<primeNum[l];
                        return 0;
                    }
                    else
                        break;
                }
            }   
        }    
    }
    cout<< -1;
    return 0;
}