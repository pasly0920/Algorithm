#include<iostream>
#include<vector>
#define epsilon 0.0000000001

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<long long> building(N);
    vector<int> sight;
    sight.assign(N, 0);

   

    for(int i=0; i< N; i++)
        cin>>building[i];
    
    for(int i = 0; i<N; i++){
        int temp = 0;
        long double initial = 0.0;

        if(i != 0)
            initial = building[i] - building[i-1];

        for(int j = i-2; j>=0; j--){
            if(j == i-2)
                temp++;
            if( ((long double)(building[i] - building[j]) / (long double)(i - j)) < initial){
                temp++;
                initial = ((long double)(building[i] - building[j]) / (long double)(i - j));
            }
        }
        if(i != N-1)
            initial = building[i+1] - building[i];
        
        for(int j = i+2; j<N; j++){
            if(j == i+2)
                temp++;
            if( ((long double)(building[j] - building[i]) / (long double)(j - i)) > initial){
                temp++;
                initial = ((long double)(building[j] - building[i]) / (long double)(j - i));
            }
        }
        sight[i] = temp;
    }

    int max = -1;

    for(int i=0; i<N; i++)
        max = (max < sight[i]) ? sight[i] : max;
    if(N >=3)
        max = (max >= 2) ? max : 2;
    cout<<max;

    return 0;
}