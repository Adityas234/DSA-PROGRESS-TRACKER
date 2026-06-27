class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int cursum = 0;
        int maxsum = 0;

        for(int i = 0;i<k;i++){
            cursum += nums[i];
        }
        
        maxsum = cursum;
        
        for(int i = k;i<nums.size();i++){
            cursum += nums[i] - nums[i-k];

            maxsum = max(cursum , maxsum);
        }

        return (double)maxsum/k;
    }
};