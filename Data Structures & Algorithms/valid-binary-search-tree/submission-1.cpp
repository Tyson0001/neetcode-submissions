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
    bool isValidBST(TreeNode* root) {
        if(!root) return true; 
        return solve(root, LONG_MIN, LONG_MAX);
    }
    bool solve(TreeNode* root,  long left , long right){
        if(!root) return true;
        if(!(left <root->val && root->val <right)) return false;
        return solve(root->left, left, root->val) && solve(root->right, root->val, right);
    }

};
