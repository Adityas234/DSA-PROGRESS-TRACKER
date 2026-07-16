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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        // Map: key = col, value = vector of pairs (row, node_value)
        map<int, vector<pair<int, int>>> columns;

        // Queue storing tuples of: {node, {row, col}}
        queue<pair<TreeNode*, pair<int, int>>> q;

        // Push the root node with coordinates (row = 0, col = 0)
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            TreeNode* node = current.first;
            int row = current.second.first;
            int col = current.second.second;

            // Group the node value and its row under the column key
            columns[col].push_back({row, node->val});

            // If left child exists, move down a row and left a column
            if (node->left != nullptr) {
                q.push({node->left, {row + 1, col - 1}});
            }

            // If right child exists, move down a row and right a column
            if (node->right != nullptr) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }

        // Process each column in sorted order
        for (auto& colPair : columns) {
            auto& nodesInCol = colPair.second;

            // Sort nodes primarily by row. 
            // If rows are identical, standard pair sorting will sort by node->val.
            sort(nodesInCol.begin(), nodesInCol.end());

            vector<int> colValues;
            for (auto& p : nodesInCol) {
                colValues.push_back(p.second); // Extract node value
            }
            result.push_back(colValues);
        }

        return result;
    
    }
};