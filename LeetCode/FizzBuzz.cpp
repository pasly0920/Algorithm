class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n, "");
        for(int i=0; i<n; i++){
            int now = i + 1;
            if(now % 3 == 0 && now % 5 == 0)
                result[i] = "FizzBuzz";
            else if(now % 3 == 0)
                result[i] = "Fizz";
            else if(now % 5 == 0)
                result[i] = "Buzz";
            else
                result[i] = to_string(now);
        }
        
        return result;
    }
};