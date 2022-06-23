#include<iostream>
#include<string>
#include<list>

using namespace std;
void keyLog(string origin);

int main(){
    int T;
    cin>>T;
    
    string temp;
    for(int i=0; i<T; i++){
        cin>>temp;
        keyLog(temp);
    }

    return 0;
}

void keyLog(string origin){
    list<char> prev;
    list<char> next;

    for(int i=0; i<origin.size(); i++){
        char now = origin[i];
        switch (now){
        case '<':
            if(prev.size() > 0){
                char move = prev.back();
                prev.pop_back();
                next.push_front(move);
            }
            break;
        case '>':
            if(next.size() > 0){
                char move = next.front();
                next.pop_front();
                prev.push_back(move);
            }
            break;
        case '-':
            if(prev.size() > 0)
                prev.pop_back();
            break;
        default:
            prev.push_back(now);
            break;
        }
    }
    
    list<char>::iterator it;
    for(it = prev.begin(); it != prev.end(); it++)
        cout<<*it;
    for(it = next.begin(); it!= next.end(); it++)
        cout<<*it;
    cout<<'\n';
}