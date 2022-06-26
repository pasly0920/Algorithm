#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

long long calc_val(vector<char> &calc, vector<int> &num);

int main(){
    int N;
    cin>>N;

    vector<int> num(N);
    for(int i=0; i<N; i++)
        cin>>num[i];

    vector<int> cal(4);
    for(int i=0; i<4; i++)
        cin>>cal[i];
    
    vector<char> calc;
    for(int i=0; i<4; i++){
        for(int j=0; j<cal[i]; j++){
            if(i == 0)
                calc.push_back('+');
            else if(i == 1)
                calc.push_back('-');
            else if(i == 2)
                calc.push_back('*');
            else
                calc.push_back('/');
        }
    }

    int tot = calc.size();
    long long min_val = 1999999999;
    long long max_val = -1999999999;

    long long res = calc_val(calc, num);
    min_val = min(min_val, res);
    max_val = max(max_val, res);
    do{
        long long res = calc_val(calc, num);
        min_val = min(min_val, res);
        max_val = max(max_val, res);
    }while(next_permutation(calc.begin(), calc.end()));

    res = calc_val(calc, num);
    min_val = min(min_val, res);
    max_val = max(max_val, res);

    cout<<max_val<<'\n'<<min_val;
    return 0;
}

long long calc_val(vector<char> &calc, vector<int> &num){
    stack<long long> n;
    for(int i=num.size() - 1; i>=0; i--)
        n.push(num[i]);
    
    for(int i=0; i<calc.size(); i++){
        long long a = n.top();
        n.pop();
        long long b = n.top();
        n.pop();

        if(calc[i] == '+')
            n.push(a+b);
        else if(calc[i] == '-')
            n.push(a-b);
        else if(calc[i] == '*')
            n.push(a*b);
        else
            n.push(a / b);
    }
    return n.top();
}