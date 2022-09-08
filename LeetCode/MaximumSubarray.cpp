class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxValPrev = nums[0];
        int maxValNext = nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            maxValNext = max(maxValPrev, 0) + nums[i];
            maxValPrev = maxValNext;
            res = max(res, maxValNext);
        }
        return res;
    }
};