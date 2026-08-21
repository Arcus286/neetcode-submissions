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
    vector<int> result;
    void inorderTraversal(TreeNode* root){
        if(root == NULL) return;
        inorderTraversal(root -> left);
        result.push_back(root -> val);
        inorderTraversal(root -> right);
    }

    bool isValidBST(TreeNode* root) {
        inorderTraversal(root);
        bool isValid = true;
        for(int i = 1;i<result.size();i++){
            if(result[i-1] >= result[i]){
                isValid = false;
            }
        }
        return isValid;
    }
};
