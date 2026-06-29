class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> res(2,-1);
        for(int i = 0; i< nums.size();i++){
            if(nums[i] == target){
                ans.push_back(i);
            }
        }
        if(ans.empty()){
            return res;
        }
        else{
            return {ans.front(), ans.back()};
        }
    }
};