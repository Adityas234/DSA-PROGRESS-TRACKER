class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int max_val = 0;
        for (int num : nums) {
            max_val = std::max(max_val, num);
        }

        const int MOD = 1e9 + 7;

        // dp[g1][g2] stores the number of subsequence pairs with GCDs g1 and g2
        // We use size max_val + 1. 0 represents an empty subsequence.
        std::vector<std::vector<int>> dp(max_val + 1, std::vector<int>(max_val + 1, 0));
        
        // Base case: both subsequences are empty
        dp[0][0] = 1;

        for (int num : nums) {
            std::vector<std::vector<int>> next_dp = dp;

            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;

                    long long current_count = dp[g1][g2];

                    // Choice 1: Add num to seq1
                    int new_g1 = (g1 == 0) ? num : std::gcd(g1, num);
                    next_dp[new_g1][g2] = (next_dp[new_g1][g2] + current_count) % MOD;

                    // Choice 2: Add num to seq2
                    int new_g2 = (g2 == 0) ? num : std::gcd(g2, num);
                    next_dp[g1][new_g2] = (next_dp[g1][new_g2] + current_count) % MOD;
                }
            }
            dp = std::move(next_dp);
        }

        long long total_pairs = 0;
        // Sum up all states where g1 == g2 and they are both non-empty (g1 > 0)
        for (int g = 1; g <= max_val; ++g) {
            total_pairs = (total_pairs + dp[g][g]) % MOD;
        }

        return total_pairs;
    }
};