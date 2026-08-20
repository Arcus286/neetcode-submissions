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
    int helper(TreeNode* root, int maxSoFar){
        if(root == NULL) return 0;

        int isGood = 0;
        if(root -> val >= maxSoFar){
            isGood = 1;
            maxSoFar = root -> val;
        }
        
        int leftTree = helper(root -> left,maxSoFar);
        int rightTree = helper(root -> right,maxSoFar);
        return rightTree + leftTree + isGood;
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return helper(root,root -> val);
    }
};
