class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<int> result;
        if(n2>n1){
            return result;
        }
        vector<int> fr1(26,0);
        vector<int> fr2(26,0);

        

        for(int i = 0;i<n2;i++){
            fr1[s[i] - 'a']++;
            fr2[p[i] - 'a']++;

        }
        if(fr1 == fr2){
            result.push_back(0);
        }

        for(int i = n2;i<n1;i++){
            fr1[s[i] - 'a']++;

            fr1[s[i-n2] - 'a']--;

            if(fr1 == fr2){
                result.push_back(i-n2+1);
            }
        }
        return result;
    }
};