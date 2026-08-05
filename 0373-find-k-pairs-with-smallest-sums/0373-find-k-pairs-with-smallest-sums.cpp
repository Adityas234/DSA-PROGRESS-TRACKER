class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k == 0) return res;

        // Min-Heap format: {sum, {index_in_nums1, index_in_nums2}}
        typedef pair<int, pair<int, int>> pii;
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;

        // Step 1: Pehle min(k, nums1.size()) elements ko nums2[0] ke sath push karo
        for (int i = 0; i < nums1.size() && i < k; i++) {
            minHeap.push({nums1[i] + nums2[0], {i, 0}});
        }

        // Step 2: Sabse chota sum extract karo aur agla pair heap me dalo
        while (k-- > 0 && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();

            int i = top.second.first;
            int j = top.second.second;

            res.push_back({nums1[i], nums2[j]});

            // Agar nums2 me next element hai, toh same nums1[i] ke sath push karo
            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return res;
    }
};