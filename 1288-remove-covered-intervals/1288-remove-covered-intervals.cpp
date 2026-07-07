class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int remainingCount = 0;
        int max_end = 0;
        
        for (const auto& interval : intervals) {
            // If the current interval's end is larger than the max_end seen so far,
            // it cannot be fully covered by any previous interval.
            if (interval[1] > max_end) {
                remainingCount++;
                max_end = interval[1]; // Update the furthest boundary
            }
            // If interval[1] <= max_end, it's covered, so we just skip it.
        }
        
        return remainingCount;
    }
};