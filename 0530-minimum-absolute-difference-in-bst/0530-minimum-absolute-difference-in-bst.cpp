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
    int mindiff = INT_MAX;
    TreeNode* prev = NULL;
    void in_order(TreeNode* root){
        if (root == NULL) return;
        in_order(root->left);
        
        if(prev != nullptr){
            mindiff = min(mindiff , root->val - prev->val);
        }
        prev = root;
        in_order(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        in_order(root);
        return mindiff;
    }
};