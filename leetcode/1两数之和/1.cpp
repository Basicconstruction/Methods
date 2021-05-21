class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        int trans;
        for(i = 0; i < nums.size();i++){
            for(j = i+1;j< nums.size();j++){
                trans = target - nums[i];
                if(nums[j]==trans){
                    return {i,j};
                }
            }
        }
        return {i,j};
    }
};