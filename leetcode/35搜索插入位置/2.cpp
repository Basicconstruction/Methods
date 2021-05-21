class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>=target){
            return 0;
        }
        if(nums[nums.size()-1]>target){
            return nums.size();
        }
        if(nums[nums.size()-1]==target){
            return nums.size()-1;
        }
        int left = 0;
        int right = nums.size();
        int center;
        while(true){
            center = left + (right-left)/2;
            if(nums[center]==target){
                return center;
            }else if(nums[center]<target){
                left = center;
            }else{
                right = center;
            }
            if(right-left==1){
                if(nums[left]>target&&nums[right]>target){
                    return left+1;
                }
            }
        }
        return left;
    }
};