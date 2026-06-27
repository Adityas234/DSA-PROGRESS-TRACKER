class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxlen = 0;
        unordered_set<char> ns;

        for(int right = 0;right<s.size();right++){
            while(ns.find(s[right]) != ns.end()){
                ns.erase(s[left]);
                left++;
            }

            ns.insert(s[right]);
            maxlen = max(maxlen, right - left+1);
        }
        return maxlen;
    }
};