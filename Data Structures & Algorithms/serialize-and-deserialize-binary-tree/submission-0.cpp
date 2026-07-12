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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(!node){
                ans+="#,";
                continue;
            }
            ans+=to_string(node->val)+',';
             q.push(node->left);
            q.push(node->right);


        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        stringstream s(data);
        string str="";
        getline(s,str,',');
        TreeNode* root =new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#"){
                TreeNode* left=new TreeNode(stoi(str));
                node->left=left;
                q.push(left);
            }
            getline(s,str,',');
            if(str!="#"){
                TreeNode* right=new TreeNode(stoi(str));
                node->right=right;
                q.push(right);
            }
        }
        return root;
        
    }
};
