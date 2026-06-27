class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0;
        int maxres = INT_MIN;

        for(int i = 0;i<k;i++){
            if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'){
                res++;
            }
        }
        
        maxres = res;


        for(int i = k;i<s.size();i++){
            
            if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'){
                res++;
            }
            if(s[i-k] == 'a'||s[i-k] == 'e'||s[i-k] == 'i'||s[i-k] == 'o'||s[i-k] == 'u'){
                res--;
            }
            maxres = max(maxres, res);
        }
        return maxres;
    }
};