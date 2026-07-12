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
    TreeNode* prev , *first , *middle, *last; 
    void dfs(TreeNode* root, TreeNode* &prev){
        if(!root) return;
        dfs(root->left, prev);
        if(prev && prev->val > root->val){
            if(!first){
                first=prev;
                middle=root;
            }else last=root;

        }
        prev=root;
        dfs(root->right, prev);
    }
    void recoverTree(TreeNode* root) {
        prev=first=middle=last=NULL;
        dfs(root, prev);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
        
    }
};