class Solution {
public:
    bool checkpass(int max_sum, vector<int> &nums, int k){
        int subarray = 1;
        int cursum = 0;

        for(int i = 0;i<nums.size();i++){
            if(cursum + nums[i] > max_sum){
                subarray++;
                cursum = nums[i];
            }
            else{
                cursum += nums[i];
            }
        }
        return subarray <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        for(int num:nums){
            sum += num;
        }
        int low = *max_element(nums.begin(), nums.end());
        int high = sum;
        
        while(low < high){
            int mid = low + (high - low)/2;

            if(checkpass(mid, nums, k)){
                high = mid;
            }else{
                low = mid +1;
            }
        }

        return low;

    }
};