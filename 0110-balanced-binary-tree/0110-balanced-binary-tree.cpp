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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        return checkheight(root) != -1;
    }

private:
    int checkheight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int hleft = checkheight(root->left);
        if(hleft == -1) return -1;
        int hright = checkheight(root->right);
        if(hright == -1) return -1;

        if(abs(hleft - hright)>1){
            return -1;
        }

        return max(hleft, hright) +1;

    }
};