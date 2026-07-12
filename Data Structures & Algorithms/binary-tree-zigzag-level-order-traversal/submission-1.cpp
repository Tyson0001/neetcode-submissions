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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool lefttoright=true;
        while(!q.empty()){ 
            int n=q.size();
            vector<int>temp(n,0); 
            int i=0;
            while(n--){
                auto node=q.front();
                q.pop();
                if(lefttoright)temp[i++]=node->val;
                else temp[n]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            lefttoright=!lefttoright;
            ans.push_back(temp);

        }
        return ans;
    }
};