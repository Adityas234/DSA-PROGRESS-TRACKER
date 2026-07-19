class Solution {
public:
    string smallestSubsequence(string s) {
        std::vector<int> last_occurrence(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }
        
        std::string result = ""; // Acting as our stack
        std::vector<bool> seen(26, false); // To track characters in the stack
        
        // Step 2: Iterate through the string
        for (int i = 0; i < s.length(); ++i) {
            char curr = s[i];
            
            // If the character is already in our result stack, skip it
            if (seen[curr - 'a']) {
                continue;
            }
            
            // Maintain monotonic increasing property:
            // Pop characters from the stack if they are larger than the current character
            // AND they appear again later in the string
            while (!result.empty() && result.back() > curr && last_occurrence[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Push the current character to both the stack and seen array
            result.push_back(curr);
            seen[curr - 'a'] = true;
        }
        
        return result;
    }
};