class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int maxDif = 0;
        
        int maxVal = prices[0];
        int minVal = prices[0];
        int maxIdx = 0;
        int minIdx = 0;
        
        for(int i=1; i<prices.size(); i++){
            int nowVal = prices[i];
            int nowIdx = i;
            
            if(nowVal >= maxVal){
                maxVal = nowVal;
                maxIdx = nowIdx;
            }
            if(nowVal < minVal){
                minVal = nowVal;
                minIdx = nowIdx;
            }
            
            if(maxIdx > minIdx)
                maxDif = max(maxDif, maxVal - minVal);
            else
                maxVal = -99999999;
        }
        
        
        
        return maxDif;
    }
};