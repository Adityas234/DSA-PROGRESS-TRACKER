class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        int sum = 0;
        int left = 0;

        for(int num : nums){
            total_sum += num;
        }

        for(int i = 0;i<nums.size();i++){
            
            int right = total_sum - nums[i] - left;
            if(left == right){
                return i;
            }

            left += nums[i];
        }
        return -1;
    }
};