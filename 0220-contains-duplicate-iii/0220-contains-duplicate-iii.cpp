class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            while (right - left > indexDiff) {
                window.erase(nums[left]);
                left++;
            }
            auto it = window.lower_bound((long long)nums[right] - valueDiff);
            if (it != window.end() &&
                abs(*it - nums[right]) <= valueDiff) {

                return true;
            }
            window.insert(nums[right]);
        }

        return false;
    }
};