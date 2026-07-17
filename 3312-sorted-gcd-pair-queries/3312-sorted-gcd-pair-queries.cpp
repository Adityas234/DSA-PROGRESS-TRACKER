class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 1: Count frequencies of each number
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2 & 3: Count pairs that have 'i' as a common divisor
        vector<long long> gcd_pairs_count(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long total_multiples = 0;
            for (int j = i; j <= max_val; j += i) {
                total_multiples += count[j];
            }
            
            // Total combinations of pairs among these multiples
            long long total_pairs = total_multiples * (total_multiples - 1) / 2;
            
            // Step 4: Inclusion-exclusion to get exact GCD pairs
            for (int j = 2 * i; j <= max_val; j += i) {
                total_pairs -= gcd_pairs_count[j];
            }
            gcd_pairs_count[i] = total_pairs;
        }
        
        // Step 5: Compute prefix sums of the GCD pair counts
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sums[i] = prefix_sums[i - 1] + gcd_pairs_count[i];
        }
        
        // Step 6: Process each query using binary search
        vector<int> answer;
        answer.reserve(queries.size());
        for (long long q : queries) {
            // Find the first GCD index where total accumulated pairs strictly exceeds q
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            answer.push_back(distance(prefix_sums.begin(), it));
        }
        
        return answer;
    }
};