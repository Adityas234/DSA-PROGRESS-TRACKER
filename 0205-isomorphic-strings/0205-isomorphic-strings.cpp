class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        // Using unordered_map for O(1) average lookup time
        unordered_map<char, char> map_s_to_t;
        unordered_map<char, char> map_t_to_s;

        for (int i = 0; i < s.size(); i++) {
            char char_s = s[i];
            char char_t = t[i];

            // Check mapping from s -> t
            if (map_s_to_t.find(char_s) != map_s_to_t.end()) {
                if (map_s_to_t[char_s] != char_t) {
                    return false;
                }
            } else {
                map_s_to_t[char_s] = char_t;
            }

            // Check mapping from t -> s
            if (map_t_to_s.find(char_t) != map_t_to_s.end()) {
                if (map_t_to_s[char_t] != char_s) {
                    return false;
                }
            } else {
                map_t_to_s[char_t] = char_s;
            }
        }

        return true;
    }
};