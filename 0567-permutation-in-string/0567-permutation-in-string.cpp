class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2) return false;

        vector<int> fr1(26,0);
        vector<int> fr2(26,0);

        for(int i = 0;i<n1;i++){
            fr1[s1[i] - 'a']++;
            fr2[s2[i] - 'a']++;

        }

        if(fr1 == fr2) return true;

        for(int i = n1;i<n2;i++){
            fr2[s2[i] - 'a']++;

            fr2[s2[i-n1] - 'a']--;

            if(fr1 == fr2) return true;
        }
        return false;
    }
};