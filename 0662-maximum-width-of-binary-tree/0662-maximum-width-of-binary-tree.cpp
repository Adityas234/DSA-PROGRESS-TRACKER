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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int max_width = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int lsize = q.size();
            unsigned long long start = q.front().second;
            unsigned long long end = q.back().second;
            max_width = max(max_width, (int)(end-start+1));

            for(int i = 0; i<lsize; i++){
                TreeNode* curr = q.front().first;
                unsigned long long curr_idx = q.front().second;
                q.pop();
                if(curr->left){
                    q.push({curr->left, 2*curr_idx+1});
                }
                if(curr->right){
                    q.push({curr->right, 2*curr_idx+2});
                }
            }
        }
        return max_width;
    }
};