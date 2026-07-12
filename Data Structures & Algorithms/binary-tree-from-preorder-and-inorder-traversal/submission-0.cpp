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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int ,int>inmap;
        for(int i=0;i<inorder.size();i++)inmap[inorder[i]]=i;
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size(), inmap);
    }
    TreeNode* build(vector<int>&preorder, vector<int>& inorder, int prestart , int preend,int instart, int inend, unordered_map<int ,int>&inmap){
        if(prestart >preend || instart >inend) return NULL ;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=inmap[root->val];
        int numleft=inroot-instart;
        root->left=build(preorder, inorder,prestart+1, prestart+numleft,instart, inroot-1,inmap);
        root->right=build(preorder,inorder,prestart+numleft+1,preend, inroot+1,inend,inmap);
        return root;
    }
};
