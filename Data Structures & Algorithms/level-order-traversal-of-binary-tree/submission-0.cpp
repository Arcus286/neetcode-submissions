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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;

        if(root == NULL) return result;

        q.push(root);

        while(!q.empty()){
            int levelCount = q.size();
            vector<int> levelElements;

            for(int i = 0;i<levelCount;i++){
                TreeNode* curr = q.front();
                q.pop();
                levelElements.push_back(curr -> val);
                if(curr -> left != NULL) q.push(curr -> left);
                if(curr -> right != NULL) q.push(curr -> right);
            }

            result.push_back(levelElements);
        }
        return result;
    }
};
