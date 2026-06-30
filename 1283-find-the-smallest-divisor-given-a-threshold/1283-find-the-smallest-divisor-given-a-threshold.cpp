class Solution {
public:

    bool checksum(int divisor, vector<int> &nums, int threshold){
        long long sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low < high){
            int mid = low + (high - low)/2;

            if(checksum(mid, nums, threshold)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};