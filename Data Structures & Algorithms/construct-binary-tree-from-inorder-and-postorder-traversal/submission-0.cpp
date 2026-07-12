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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int ,int>inmap;
        for(int i=0;i<inorder.size();i++)inmap[inorder[i]]=i;
        return build(inorder, postorder,0,inorder.size()-1,0,postorder.size()-1,inmap);
    }
    TreeNode* build(vector<int>& inorder, vector<int>&postorder , int instart , int inend, int posstart , int posend , unordered_map<int ,int>&inmap){
        if(instart >inend || posstart >posend) return NULL;
        TreeNode* root= new TreeNode(postorder[posend]);
        int inroot=inmap[root->val];
        int numleft=inroot-instart; 
        root->left=build(inorder, postorder, instart,inroot-1, posstart, posstart+numleft-1, inmap);
        root->right=build(inorder, postorder, inroot+1 ,inend, posstart+numleft , posend-1, inmap);
        return root;
    }
};