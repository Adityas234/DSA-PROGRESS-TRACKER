class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;
        
        // Precompute powers of 10
        vector<long long> power10(m + 1, 1);
        for (int i = 1; i <= m; ++i) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }
        
        // pref_num[i] stores the math value of non-zero digits up to i-1
        vector<long long> pref_num(m + 1, 0);
        // pref_sum[i] stores the arithmetic sum of digits up to i-1
        vector<long long> pref_sum(m + 1, 0);
        // pref_count[i] stores the total number of non-zero digits up to i-1
        vector<int> pref_count(m + 1, 0);
        
        for (int i = 0; i < m; ++i) {
            int digit = s[i] - '0';
            if (digit != 0) {
                pref_num[i + 1] = (pref_num[i] * 10 + digit) % MOD;
                pref_count[i + 1] = pref_count[i] + 1;
            } else {
                pref_num[i + 1] = pref_num[i];
                pref_count[i + 1] = pref_count[i];
            }
            pref_sum[i + 1] = pref_sum[i] + digit;
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            // Number of non-zero digits in the current substring range
            int count = pref_count[r + 1] - pref_count[l];
            
            if (count == 0) {
                answer.push_back(0);
                continue;
            }
            
            // Extract the concatenated integer x modulo 10^9 + 7
            long long x = (pref_num[r + 1] - (pref_num[l] * power10[count]) % MOD + MOD) % MOD;
            
            // Get the sum of digits in the range
            long long digit_sum = pref_sum[r + 1] - pref_sum[l];
            
            // Calculate final answer for the query
            long long res = (x * (digit_sum % MOD)) % MOD;
            answer.push_back(res);
        }
        
        return answer;
        
    }
};