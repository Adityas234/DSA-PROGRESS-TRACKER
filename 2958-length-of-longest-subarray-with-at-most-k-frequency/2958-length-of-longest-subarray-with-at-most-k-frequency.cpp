class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Include current element in the window
            count[nums[right]]++;

            // Shrink the window from the left if frequency of nums[right] exceeds k
            while (count[nums[right]] > k) {
                count[nums[left]]--;
                left++;
            }

            // Update the maximum valid window length
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};