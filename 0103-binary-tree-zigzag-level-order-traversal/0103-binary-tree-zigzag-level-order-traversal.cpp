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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;

        while(!q.empty()){
            int lsize = q.size();
            vector<int> temp(lsize);
            for(int i = 0;i<lsize;i++){
                TreeNode* curr = q.front();
                q.pop();
                int index = ltr ? i : (lsize - 1 - i);
                temp[index] = curr->val;
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            ltr =  !ltr;
            res.push_back(temp);
        }
        return res;
    }
};