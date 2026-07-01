/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return{};
        }
        vector<int> ans;
        ans.push_back(root->val);
        
        vector<int> leftres = preorderTraversal(root->left);
        ans.insert(ans.end(), leftres.begin(), leftres.end());
        vector<int> rightres = preorderTraversal(root->right);
        ans.insert(ans.end(), rightres.begin(), rightres.end());
        return ans;
    }
};