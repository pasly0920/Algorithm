#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(string& a, string& b){
    if(a.length() > b.length())
        return true;
    else
        if(a > b)
            return false;
        else
            return true;
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin>>N>>M;

    vector<string> word;
    vector<string> wordPool;
    string temp;
    for(int i=0; i<N; i++){
        cin>>temp;
        if(temp.length() < M)
            continue;
        wordPool.push_back(temp);
    }

    sort(wordPool.begin(), wordPool.end(), compare);
    int maxSize = wordPool.size();

    vector<vector<string>> wordCount(maxSize + 1);
    string nowWord = wordPool[0];
    int nowWordCount = 0;
    int maxWordCount = -1;
    for(int i=0; i<wordPool.size(); i++){
        if(nowWord == wordPool[i])
            nowWordCount ++;
        else{
            wordCount[nowWordCount].push_back(nowWord);
            maxWordCount = max(nowWordCount, maxWordCount);
            nowWord = wordPool[i];
            nowWordCount=1;
        }
        if(i == wordPool.size() - 1){
            wordCount[nowWordCount].push_back(nowWord);
            maxWordCount = max(nowWordCount, maxWordCount);
        }
    }

    for(int i=maxWordCount; i>=1; i--)
        for(int j=0; j<wordCount[i].size(); j++)
            cout<<wordCount[i][j]<<'\n';
    return 0;
}