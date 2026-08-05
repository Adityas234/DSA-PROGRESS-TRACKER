class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<pair<int, int>> res;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for (auto p : mp) {
            // p.first = element (value)
            // p.second = frequency
            res.push_back({p.first, p.second}); 
    
            // Ya fir direct pair bhi push kar sakta hai:
            // res.push_back(p);
        }

        sort(res.begin(), res.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(res[i].first);
        }

        return ans;
    }
};