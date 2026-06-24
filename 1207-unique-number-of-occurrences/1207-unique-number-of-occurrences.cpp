class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i = 0;i<arr.size();i++){
            map[arr[i]]++;
        }
        unordered_set<int> s;
        for (const auto& [key, value] : map) {
            if (!s.insert(value).second) {
                return false; 
            }
        }
        return true;
    }
};