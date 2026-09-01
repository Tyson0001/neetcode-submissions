class Solution {
public: 
    vector<int>topo(vector<vector<int>>&adj , unordered_set<int>&total){
        vector<int>indegree(26,0);
        for(int i=0;i<26;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<26;i++){
            if(indegree[i]==0 && total.count(i)) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans;
    }
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>adj(26);
        int n=words.size();
        unordered_set<int>total;
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(),s2.size());
            int found=false;
            for(int i=0;i<len;i++){
                if(s1[i]!=s2[i]){
                    found=true;
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    total.insert(s1[i]-'a');
                    total.insert(s2[i]-'a');
                    break;
                    
                }
            }
            if(!found && s1.size() >s2.size()) return "";

        }
        vector<int>ans=topo(adj ,total);
        if(ans.size()!=total.size()) return "";
        string res="";
        for(auto it:ans){
            res+= (it+'a');
        }
        for(int i=0;i<n;i++){
            for(auto it:words[i]){
                if(!total.count(it-'a')){
                    total.insert(it-'a');
                    res+=it;
                }
            }
        }
        return res;


    }
};
