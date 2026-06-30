class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, count = 0;
        // Array to keep track of the frequencies of 'a', 'b', and 'c'
        int freq[3] = {0}; 
        
        for (int right = 0; right < s.length(); ++right) {
            // Add the current character to our window
            freq[s[right] - 'a']++;
            
            // While the window contains all three characters, it's valid
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // All substrings from 'right' to the end of the string are valid
                count += s.length() - right;
                
                // Shrink the window from the left
                freq[s[left] - 'a']--;
                left++;
            }
        }
        
        return count;
    }
};