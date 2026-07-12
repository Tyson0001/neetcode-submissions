struct Node{
    bool isleaf;
    vector<Node*>child;
    Node(){
        isleaf=false;
        child.assign(26,NULL);
    }

};
class trie{
    public:
    Node* root;
    trie():root(new Node){}
    void insert(string word){
        Node* curr=root;
        for(auto c:word){
            if(curr->child[c-'a']==NULL) curr->child[c-'a']=new Node();
            curr=curr->child[c-'a'];
        }
        curr->isleaf=true;
    }

};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        trie t;
        for(auto c:dictionary) t.insert(c);
        int n=s.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=dp[i+1]+1;
            Node* curr=t.root;
            for(int j=i;j<n;j++){
                if(curr->child[s[j]-'a']==NULL){
                    break;
                }
                curr=curr->child[s[j]-'a'];
                if(curr->isleaf) dp[i]=min(dp[i],dp[j+1]);
            }
        }
        return dp[0];
    }
};