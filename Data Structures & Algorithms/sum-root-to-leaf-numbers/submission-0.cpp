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
    int sumNumbers(TreeNode* root) {
        string temp="";
        return solve(root, temp);
    }
    int solve(TreeNode* root, string temp){
        temp+=to_string(root->val);
        if(!root->left && !root->right){
            
            return stoi(temp);
        }
        int left=0,right=0;
        if(root->left) left=solve(root->left,temp);
        if(root->right) right=solve(root->right,temp);
        return left+right;
        
    }
};