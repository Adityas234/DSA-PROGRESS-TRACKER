class Solution {
public:
    vector<vector<int>> memo;
    
    int getMaxDiff(vector<int>& nums, int i, int j) {
        // Base Case: jab ek hi element bache
        if (i == j) return nums[i];
        
        // Agar pehle calculate ho chuka hai
        if (memo[i][j] != -1) return memo[i][j];
        
        // Pick left OR Pick right
        int pickLeft = nums[i] - getMaxDiff(nums, i + 1, j);
        int pickRight = nums[j] - getMaxDiff(nums, i, j - 1);
        
        return memo[i][j] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        
        // Player 1 tabhi jeetega jab diff >= 0 ho
        return getMaxDiff(nums, 0, n - 1) >= 0;
    }
};