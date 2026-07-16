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
private:
    int height(TreeNode* root, int & maxheight){
        if(root == NULL){
            return 0;
        }
        int left = height(root->left, maxheight);
        int right = height(root->right, maxheight);
        maxheight = max(maxheight, left+right);
        return max(left, right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxheight = 0;
        height(root, maxheight);
        return maxheight;
    }
};