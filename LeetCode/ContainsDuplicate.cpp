class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        bool duplicated = false;
        for(int i=0; i<nums.size() - 1; i++){
            if(duplicated)
                break;
            if(nums[i] == nums[i+1])
                duplicated = true;
        }
        return duplicated;
    }
};