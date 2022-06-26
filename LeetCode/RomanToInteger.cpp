class Solution {
public:
    int romanToInt(string s) {
        vector<int> number;
        for(int i=0; i<s.size(); i++){
            switch(s[i]){
                case 'I':
                    number.push_back(1);
                    break;
                case 'V':
                    number.push_back(5);
                    break;
                case 'X':
                    number.push_back(10);
                    break;
                case 'L':
                    number.push_back(50);
                    break;
                case 'C':
                    number.push_back(100);
                    break;
                case 'D':
                    number.push_back(500);
                    break;
                case 'M':
                    number.push_back(1000);
                    break;
            }
        }
        
        int intNum = 0;
        for(int i=0; i<number.size(); i++){
            if(i == number.size() - 1)
                intNum += number[i];
            else{
                if(number[i] < number[i+1]){
                    intNum += (number[i+1] - number[i]);
                    i++;
                }
                else{
                    intNum += number[i];
                }
            }
        }
        
        return intNum;
    }
};