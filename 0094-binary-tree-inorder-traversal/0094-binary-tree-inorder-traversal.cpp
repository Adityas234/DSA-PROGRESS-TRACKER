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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }

        vector<int>result;
        vector<int>leftres = inorderTraversal(root->left);
        result.insert(result.end(), leftres.begin(), leftres.end());

        result.push_back(root->val);

        vector<int>right = inorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());

        return result;

    }
};