class NumArray {
private:
    vector<int>prefix;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.assign(n+1,0);

        for(int i = 0;i<n;i++){
            prefix[i+1] = prefix[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int res = prefix[right + 1] - prefix[left];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */