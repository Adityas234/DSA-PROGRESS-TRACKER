class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        

        if(nums1.size()<nums2.size()){
            for(int i = 0;i<nums1.size();i++){
                for(int j = 0;j<nums2.size();j++){
                    if(nums1[i]== nums2[j]){
                        s.insert(nums1[i]);
                    }
                }
            }
        }
        else{
            for(int i = 0;i<nums2.size();i++){
                for(int j = 0;j<nums1.size();j++){
                    if(nums2[i]== nums1[j]){
                        s.insert(nums2[i]);
                    }
                }
            }
        }
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};