class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int half_len = n / 2;

        // Extract the first half and sort it lexicographically
        string first_half = s.substr(0, half_len);
        sort(first_half.begin(), first_half.end());

        // Construct the middle character if length is odd
        string mid = "";
        if (n % 2 != 0) {
            mid = s[half_len];
        }

        // Create the reversed second half
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());

        return first_half + mid + second_half;
    }
};