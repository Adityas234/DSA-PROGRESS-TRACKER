class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        // Base cases for n = 1 and n = 2
        if (n <= 2) {
            return n;
        }
        
        // Find the bit width of n (position of the most significant bit + 1)
        int bit_width = 0;
        int temp = n;
        while (temp > 0) {
            bit_width++;
            temp >>= 1;
        }
        
        // Total unique XOR values possible is 2^bit_width
        return 1 << bit_width;
    }
};