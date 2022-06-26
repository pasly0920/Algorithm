#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string number;
    cin >> number;

    vector<int> sorting;
    for(int i=0; i<number.size(); i++)
        sorting.push_back(number[i] - '0');
    
    sort(sorting.begin(), sorting.end());
    reverse(sorting.begin(), sorting.end());

    for(int i=0; i<sorting.size(); i++)
        cout<<sorting[i];
    return 0;
}