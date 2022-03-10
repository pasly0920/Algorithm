#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<char> T;

    char temp;
    for(int i=0; i<N; i++){
        cin>>temp;
        T.push_back(temp);
    }

    int start = 0;
    int end = T.size() - 1;

    vector<char> res;
    res.push_back('a');
    char next;
    while(start <= end){
        //two pointer infinite comparison
        if(T[start] < T[end]){
            next = T[start];
            start++;
        }
        else if(T[start] > T[end]){
            next = T[end];
            end--;
        }
        else{
            bool choose = true;
            int temps = start + 1;
            int tempe = end - 1;
            while(temps < tempe){
                if(T[temps] < T[tempe]){
                    choose = true;//near start
                    break;
                }
                else if(T[temps] > T[tempe]){
                    choose = false;//near end
                    break;
                }
                else{
                    temps++;
                    tempe--;
                }
            }
            if(choose){
                next = T[start];
                start++;
            }
            else{
                next = T[end];
                end --;
            }
        }
        res.push_back(next);
    }

    for(int i=1; i<res.size(); i++){
        cout<<res[i];
        if(i%80 == 0)
            cout<<'\n';
    }

    return 0;
}