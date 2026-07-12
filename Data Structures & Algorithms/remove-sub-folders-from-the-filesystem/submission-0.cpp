class Solution {
public: 
    struct Node{
        bool isleaf;
        unordered_map<string, Node*>child;
        Node(){
            isleaf=false;
        }

    }; 
    Node* root=new Node();
    vector<string> removeSubfolders(vector<string>& folder) {
        for(auto c:folder){
            stringstream s(c);
            string str;
            Node* curr=root;
            while(getline(s,str,'/')){
                if(str.empty()) continue;
                if(curr->child.find(str)==curr->child.end()){
                    curr->child[str]=new Node();

                }
                curr=curr->child[str];
            }
            curr->isleaf=true;
        }
        vector<string>ans;
        for(auto c:folder){
            stringstream s(c);
            string str;
            Node* curr=root;
            bool subfolder=false; 
            while(getline(s,str,'/')){
                if(str.empty()) continue; 
                Node* newnode= curr->child[str];
                if(newnode->isleaf && s.rdbuf()->in_avail()!=0){
                    subfolder=true;
                    break;

                }
                curr=newnode;
            }
            if(!subfolder) ans.push_back(c);
        }
        return ans;
        
    }
};