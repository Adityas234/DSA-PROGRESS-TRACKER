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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        // Agar left child nahi hai, toh path right side ki taraf jayegi
        if (root->left == NULL) {
            return minDepth(root->right) + 1;
        }
        
        // Agar right child nahi hai, toh path left side ki taraf jayegi
        if (root->right == NULL) {
            return minDepth(root->left) + 1;
        }
        
        // Agar dono children exist karte hain, tab minimum le lo
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};