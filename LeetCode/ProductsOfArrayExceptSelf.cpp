class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int maxMultiple = 1;
        int zeroCount = 0;
        int zeroIdx = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeroIdx = i;
                zeroCount++;
            }
            else{
                maxMultiple *= nums[i];
            }
        }        
        
        vector<int>ans(nums.size(), 0);
        if(zeroCount >= 2)
            return ans;
        if(zeroCount == 1){
            ans[zeroIdx] = maxMultiple;
            return ans;
        }
        for(int i=0; i<nums.size(); i++)
            ans[i] = maxMultiple / nums[i];
        
        return ans;
    }
};