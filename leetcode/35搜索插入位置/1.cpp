class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0 ; i < nums.size();){
            if(nums[i]==target){
                return i;
            }else if(nums[i]<target){
                ++i;
            }else{
                return i;
            }
        }
        return nums.size();
    }
};