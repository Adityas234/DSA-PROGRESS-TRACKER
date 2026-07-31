class Solution {
public:
    int minimumPushes(string word) {
        std::vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Step 2: Sort frequencies in descending order
        std::sort(freq.rbegin(), freq.rend());

        // Step 3: Calculate the total minimum pushes
        int totalPushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break; // No more characters left
            
            int pushesPerChar = (i / 8) + 1; // 1 push for 0-7, 2 pushes for 8-15, etc.
            totalPushes += freq[i] * pushesPerChar;
        }

        return totalPushes;
    }
};