class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int>sufix(n,0);

        for(int i = 1;i<nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i-1];
        }

        for(int i = n-2;i>=0;i--){
            sufix[i] = sufix[i+1] + nums[i+1];
        }

        for(int i = 0;i<nums.size();i++){
            if(prefix[i]==sufix[i]){
                return i;
            }
        }
        return -1;
    }
};