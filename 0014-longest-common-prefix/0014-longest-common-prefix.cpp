class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size()-1];

        string res = "";

        for(int i = 0;i<first.size();i++){
            if(i>last.size() || first[i]!=last[i]){
                break;
            }
            res += first[i];
        }

        return res;
    }
};