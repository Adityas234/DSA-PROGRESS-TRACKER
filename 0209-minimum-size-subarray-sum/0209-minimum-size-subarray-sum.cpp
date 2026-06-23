class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =  nums.size();
        int left = 0;
        int curr_sum = 0;
        int minlen = INT_MAX;

        for(int right = 0;right<n;right++){
            curr_sum += nums[right];

            while(curr_sum>=target){
                minlen = min(minlen, right - left+1);
                curr_sum -= nums[left];
                left++;
            }
        }

        return (minlen==INT_MAX) ? 0:minlen;

    }
};