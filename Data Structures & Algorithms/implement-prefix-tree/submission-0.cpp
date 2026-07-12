struct Node{
    bool isleaf;
    vector<Node*>child;
    Node(){
        isleaf=false;
        child.assign(26,NULL);
        
    }

};

class PrefixTree {
public: 
    Node* root;
    PrefixTree() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(auto c:word){
            if(node->child[c-'a']==NULL){
                node->child[c-'a']=new Node();
            }
            node=node->child[c-'a'];
        }
        node->isleaf=true;
    }
    
    bool search(string word) { 
        Node* node=root;
        for(auto c:word){
            if(node->child[c-'a']== NULL) return false;
            node=node->child[c-'a'];
        }
        return node->isleaf;
        
    }
    
    bool startsWith(string prefix) { 
        Node* node=root;
        for(auto c:prefix){
            if(node->child[c-'a']==NULL) return false;
            node=node->child[c-'a'];
        }
        return true;
        
    }
};
