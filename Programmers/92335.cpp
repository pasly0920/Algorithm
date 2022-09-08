#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> convertedNum;
bool isSpecial(long long num){
    long long r = 2;
    if (num == 2)
        return (true);
    if (num <= 1)
        return (false);
    while (r * r <= num)
    {
        if (num % r == 0)
            return (false);
        r++;
    }
    return (true);
}
void convert(int n, int k){
    if (n < k) 
	{
		convertedNum.push_back(n);
		return;
	}
	
	convert(n/k, k);
    convertedNum.push_back(n%k);
}

int solution(int n, int k) {
    int answer = 0;
    convert(n, k);
    
    long long nowNum = -1;
    vector<long long> seperatedNum;
    for(int i = 0; i<convertedNum.size(); i++){
        if(convertedNum[i] == 0){
            if(nowNum == -1 || nowNum == 0)
                continue;
            seperatedNum.push_back(nowNum);
            nowNum = -1;
        }
        if(nowNum == -1)
            nowNum = convertedNum[i];
        else
            nowNum = nowNum * 10 + convertedNum[i];
        if(i == convertedNum.size() - 1 && nowNum >= 1)
            seperatedNum.push_back(nowNum);
    } //seperate
    
    // 소수 여부 배열 생성
    for(int i=0; i<seperatedNum.size(); i++)
        if(isSpecial(seperatedNum[i]))
            answer ++;
    // 소수 검출
    return answer;
}