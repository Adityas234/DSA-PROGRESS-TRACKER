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
public:
    void flatten(TreeNode* root) {

        if(root == NULL){
            return;
        }
        vector<int>tempres;

        tempres = preorderTraversal(root);
        TreeNode* temp = root;
        temp->val = tempres[0];
        for(int i = 1;i<tempres.size();i++){
            temp->left = NULL;
            temp->right= new TreeNode(tempres[i]);
            temp = temp->right;
        }
    }
};