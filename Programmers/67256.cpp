#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dist(int now, int target){
    if(now == 1 || now == 3){
        if(target == 0)
            return 4;
        else
            return (target/3) + 1;
    }
    else if(now == 4 || now == 6){
        if(target == 0)
            return 3;
        else if(target == 2)
            return 2;
        else
            return (target/3);
    }
    else if(now == 7 || now == 9){
        if(target == 0)
            return 2;
        else if(target == 2)
            return 3;
        else if(target == 5)
            return 2;
        else
            return 1;
    }
    else if(now == 2){
        if(target == 2)
            return 0;
        else if(target == 5)
            return 1;
        else if(target == 8)
            return 2;
        else
            return 3;
    }
    else if(now == 5){
        if(target == 2 || target == 8)
            return 1;
        else if(target == 5)
            return 0;
        else if(target == 0)
            return 2;
    }
    else if(now == 8){
        if(target == 5 || target == 0)
            return 1;
        else if(target == 8)
            return 0;
        else if(target == 2)
            return 2;
    }
    else if(now == 0){
        if(target == 0)
            return 0;
        else if(target == 8)
            return 1;
        else if(target == 5)
            return 2;
        else if(target == 2)
            return 3;
    }
    else if(now == -1 || now == -3){
        if(target == 0)
            return 1;
        else if(target == 8)
            return 2;
        else if(target == 5)
            return 3;
        else if(target == 2)
            return 4;
    }
    return -1;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    string left = "left";
    string right = "right";
    
    int nowLeft = -1;
    int nowRight = -3;
    for(int i=0; i<numbers.size(); i++){
        int nowNumber = numbers[i];
        if(nowNumber%3 == 1){
            answer += "L";
            nowLeft = nowNumber;
        }
        else if(nowNumber%3 == 0 && nowNumber != 0){
            answer += "R";
            nowRight = nowNumber;
        }
        else{
            int leftDist = dist(nowLeft, nowNumber);
            int rightDist = dist(nowRight, nowNumber);
            
            cout<<nowLeft<<' '<<nowRight<<'\n';
            cout<<leftDist<<" "<<rightDist<<'\n';
            
            if(leftDist > rightDist){
                answer += "R";
                nowRight = nowNumber;
            }
            else if(rightDist > leftDist){
                answer += "L";
                nowLeft = nowNumber;
            }
            else{
                if(hand == left){
                    answer += "L";
                    nowLeft = nowNumber;
                }
                else{
                    answer += "R";
                    nowRight = nowNumber;
                }
            }
        }
            
    }
    return answer;
}