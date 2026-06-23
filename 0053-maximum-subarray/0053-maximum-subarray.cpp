class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bstend = nums[0];
        int ans = nums[0];

        for(int i =1;i<nums.size();i++){
            int v1 = bstend+nums[i];
            int v2 = nums[i];

            bstend = max(v1, v2);
            ans = max(ans,bstend);
        }
        return ans;
    }
};